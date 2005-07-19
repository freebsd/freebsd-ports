/*
 * FreeBSD kernel wrapper for KQEMU
 * Copyright (c) 2005 Antony T Curtis
 *
 * Based upon the Linux wrapper by Fabrice Bellard
 */

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/kernel.h>
#if __FreeBSD_version < 500000
#include <sys/buf.h>
#endif
#include <sys/uio.h>
#include <sys/conf.h>
#include <sys/ctype.h>
#include <sys/fcntl.h>
#include <sys/malloc.h>
#include <sys/proc.h>
#if __FreeBSD_version > 500000
#include <sys/ktr.h>
#include <sys/sched.h>
#endif
#include <sys/ioccom.h>
#include <sys/signalvar.h>
#include <sys/resourcevar.h>
#include <sys/module.h>

#include <vm/vm.h>
#include <vm/vm_param.h>
#include <vm/pmap.h>
#include <vm/vm_map.h>
#include <vm/vm_page.h>
#include <vm/vm_kern.h>
#include <vm/vm_extern.h>

#include <machine/stdarg.h>

#define __KERNEL__

#include "kqemu.h"

static unsigned long cache_page(vm_offset_t paddr, caddr_t addr);
static caddr_t find_page(vm_offset_t paddr, int free);

static MALLOC_DEFINE(M_KQEMU, "KQEMU", "KQEMU Resources");

struct pagecache {
	caddr_t addr;
};

static struct pagecache **pagecache;
#if __FreeBSD_version > 500000
static struct mtx cache_lock;
#endif

static unsigned long cache_page(vm_offset_t paddr, caddr_t addr)
{
    unsigned long ppn = (unsigned long)(paddr >> PAGE_SHIFT);
    int pci = (int)(ppn >> 10);
    struct pagecache *cache;
#if __FreeBSD_version > 500000
    mtx_lock_spin(&cache_lock);
#endif
    if (!(cache = pagecache[pci])) {
    	if (!addr) {
#if __FreeBSD_version > 500000
    	    mtx_unlock_spin(&cache_lock);
#endif
	    return 0;
	}
    	cache = pagecache[pci] = (struct pagecache *)
		kqemu_vmalloc(1024 * sizeof(struct pagecache));
	
	memset(cache, 0, 1024 * sizeof(struct pagecache));
    }
    if (!addr) {
	int i;
        cache[ppn & 1023].addr = (caddr_t) 0;
	for (i = 1023; i >= 0; i--, cache++)
	    if (cache->addr)
		break;
	if (i < 0) {
	    kqemu_vfree(pagecache[pci]);
	    pagecache[pci] = 0;
	}
#if __FreeBSD_version > 500000
	mtx_unlock_spin(&cache_lock);
#endif
	return 0;
    }
    cache[ppn & 1023].addr = (caddr_t) (((unsigned long) addr) & ~PAGE_MASK);
#if __FreeBSD_version > 500000
    mtx_unlock_spin(&cache_lock);
#endif
    return ppn;
}

static caddr_t find_page(vm_offset_t paddr, int free)
{
    unsigned long ppn = (unsigned long)(paddr >> PAGE_SHIFT);
    struct pagecache *cache;
    caddr_t addr;
#if __FreeBSD_version > 500000
    mtx_lock_spin(&cache_lock);
#endif
    if (!(cache = pagecache[ppn >> 10])) {
#if __FreeBSD_version > 500000
	mtx_unlock_spin(&cache_lock);
#endif
    	return 0;
    }
    addr = (caddr_t)(((unsigned long)cache[ppn & 1023].addr) 
        	   | ((unsigned long)paddr & PAGE_MASK));
#if __FreeBSD_version > 500000
    mtx_unlock_spin(&cache_lock);
#endif
    if (free && addr)
	cache_page(paddr, 0);
    return addr;
}

/* lock the page at virtual address 'user_addr' and return its
   page index. Return -1 if error */
unsigned long CDECL kqemu_lock_user_page(unsigned long user_addr)
{
    int rc;
    caddr_t addr = (caddr_t) user_addr;
    vm_page_t m;
    vm_offset_t paddr;
    
    /*kqemu_log("kqemu_lock_user_page(0x%08x)\n", addr);*/
    
    rc = vm_fault_quick(addr, VM_PROT_READ|VM_PROT_WRITE);
    if (rc < 0) {    
	/*kqemu_log("vm_fault_quick failed rc=%d\n",rc);*/
	return -1;	
    }
    paddr = vtophys(addr);
    m = PHYS_TO_VM_PAGE(paddr);
    vm_page_wire(m);
    
    return cache_page(paddr, addr);
}

void CDECL kqemu_unlock_user_page(unsigned long page_index)
{
    vm_page_t m;
    vm_offset_t paddr;
    /*kqemu_log("kqemu_unlock_user_page(0x%08x)\n",page_index);*/

    paddr = (vm_offset_t)(page_index << PAGE_SHIFT);
    m = PHYS_TO_VM_PAGE(paddr);
    vm_page_unwire(m, 1);
    cache_page(paddr, 0);
}

unsigned long CDECL kqemu_alloc_zeroed_page(void)
{
    void *addr;
    vm_offset_t paddr;

    /*kqemu_log("kqemu_alloc_zeroed_page()\n");*/
    addr = contigmalloc(PAGE_SIZE, M_KQEMU, M_WAITOK, 0, ~0ul, PAGE_SIZE, 0);
    if (!addr) {
	/*kqemu_log("contigmalloc failed\n");*/
        return -1;
    }
    memset(addr, 0, PAGE_SIZE);
    paddr = vtophys(addr);
    return cache_page(paddr, addr);
}

void CDECL kqemu_free_page(unsigned long page_index)
{
    vm_offset_t paddr;
    caddr_t addr;
    /*kqemu_log("kqemu_free_page(0x%08x)\n", page_index);*/
    paddr = (vm_offset_t) (page_index << PAGE_SHIFT);
    if ((addr = find_page(paddr,1))) {    
	contigfree((void *) addr, PAGE_SIZE, M_KQEMU);
    }
}

void * CDECL kqemu_page_kaddr(unsigned long page_index)
{
    vm_offset_t paddr;
    /*kqemu_log("kqemu_page_kaddr(0x%08x)\n", page_index);*/
    paddr = (vm_offset_t) (page_index << PAGE_SHIFT);
    return (void *) find_page(paddr, 0);
}

/* contraint: each page of the vmalloced area must be in the first 4
   GB of physical memory */
void * CDECL kqemu_vmalloc(unsigned int size)
{
    /*kqemu_log("kqemu_vmalloc(0x%08x)\n", size);*/
    return malloc(size, M_KQEMU, M_WAITOK);
}

void CDECL kqemu_vfree(void *ptr)
{
    /*kqemu_log("kqemu_vfree(0x%08x)\n", ptr);*/
    return free(ptr, M_KQEMU);
}

unsigned long CDECL kqemu_vmalloc_to_phys(const void *vaddr)
{
    caddr_t addr = (caddr_t)vaddr;
    vm_offset_t paddr = vtophys(addr);
    return cache_page(paddr, addr);
}

#if __FreeBSD_version < 500000
static int
curpriority_cmp(struct proc *p)
{
        int c_class, p_class;

        c_class = RTP_PRIO_BASE(curproc->p_rtprio.type);
        p_class = RTP_PRIO_BASE(p->p_rtprio.type);
        if (p_class != c_class)
                return (p_class - c_class);
        if (p_class == RTP_PRIO_NORMAL)
                return (((int)p->p_priority - (int)curpriority) / PPQ);
        return ((int)p->p_rtprio.prio - (int)curproc->p_rtprio.prio);
}

/* return TRUE if a signal is pending (i.e. the guest must stop
   execution) */
int CDECL kqemu_schedule(void)
{
    struct proc *p = curproc;
    if (curpriority_cmp(p) > 0) {
        int s = splhigh();
	p->p_priority = MAXPRI;
        setrunqueue(p);
        p->p_stats->p_ru.ru_nvcsw++;
        mi_switch();
        splx(s);
    }
    return issignal(curproc) != 0;
}

#else

/* return TRUE if a signal is pending (i.e. the guest must stop
   execution) */
int CDECL kqemu_schedule(void)
{
    struct thread *td = curthread;
    struct proc *p = td->td_proc;
    int rc;
    mtx_lock_spin(&sched_lock);
    sched_prio(td, td->td_ksegrp->kg_user_pri);
    mi_switch(SW_INVOL, NULL);
    mtx_unlock_spin(&sched_lock);

    PROC_LOCK(p);
    mtx_lock(&p->p_sigacts->ps_mtx);
    rc = cursig(td);
    mtx_unlock(&p->p_sigacts->ps_mtx);
    PROC_UNLOCK(p);
    return rc;
}

#endif


static char log_buf[4096];

void CDECL kqemu_log(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(log_buf, sizeof(log_buf), fmt, ap);
    printf("kqemu: %s", log_buf);
    va_end(ap);
}

/*********************************************************/


#define KQEMU_MAX_INSTANCES 4

struct kqemu_instance {
#if __FreeBSD_version > 500000
    TAILQ_ENTRY(kqemu_instance) kqemu_ent;
    struct cdev *kqemu_dev;
#endif
    struct kqemu_state *state;
};

static int kqemu_ref_count = 0;
static int max_locked_pages;
#if __FreeBSD_version < 500000
static dev_t kqemu_dev;
#else
static struct clonedevs *kqemuclones;
static TAILQ_HEAD(,kqemu_instance) kqemuhead = TAILQ_HEAD_INITIALIZER(kqemuhead);
static eventhandler_tag clonetag;
#endif


static	d_open_t	kqemu_open;
static	d_close_t	kqemu_close;
static	d_ioctl_t	kqemu_ioctl;

static struct cdevsw kqemu_cdevsw = {
#if __FreeBSD_version < 500000
	/* open */	kqemu_open,
	/* close */	kqemu_close,
	/* read */	noread,
	/* write */	nowrite,
	/* ioctl */	kqemu_ioctl,
	/* poll */	nopoll,
	/* mmap */	nommap,
	/* strategy */	nostrategy,
	/* name */	"kqemu",
	/* maj */	KQEMU_MAJOR,
	/* dump */	nodump,
	/* psize */	nopsize,
	/* flags */	0,
	/* bmaj */	-1
#else
	.d_version =	D_VERSION,
	.d_open =	kqemu_open,
	.d_close =	kqemu_close,
	.d_ioctl =	kqemu_ioctl,
	.d_name =	"kqemu",
#ifdef D_NEEDGIANT
	.d_flags =	D_NEEDGIANT,
#endif
#endif
};

#if __FreeBSD_version > 500000
static void
kqemu_clone(void *arg, char *name, int namelen, struct cdev **dev)
{
    int unit, r;
    if (*dev != NULL)
	return;

    if (strcmp(name, "kqemu") == 0)
	unit = -1;
    else if (dev_stdclone(name, NULL, "kqemu", &unit) != 1)
	return;		/* Bad name */
    if (unit != -1 && unit > KQEMU_MAX_INSTANCES)
	return;

    r = clone_create(&kqemuclones, &kqemu_cdevsw, &unit, dev, 0);
    if (r) {
	    *dev = make_dev(&kqemu_cdevsw, unit2minor(unit),
		    UID_ROOT, GID_WHEEL, 0660, "kqemu%d", unit);
	    if (*dev != NULL) {
		    dev_ref(*dev);
		    (*dev)->si_flags |= SI_CHEAPCLONE;
	    }
    }
}
#endif

static void kqemu_destroy(struct kqemu_instance *ks)
{
    struct cdev *dev = ks->kqemu_dev;

    if (ks->state) {
	kqemu_delete(ks->state);
	ks->state = NULL;
    }

    free(ks, M_KQEMU);
    dev->si_drv1 = NULL;
#if __FreeBSD_version > 500000
    mtx_lock_spin(&cache_lock);
    TAILQ_REMOVE(&kqemuhead, ks, kqemu_ent);
#endif
    if (!--kqemu_ref_count) {
	int i;
	for (i = 1023; i >= 0; i--)
	    kqemu_vfree(pagecache[i]);
        memset(pagecache, 0, 1024 * sizeof(void *));
    }
#if __FreeBSD_version > 500000
    mtx_unlock_spin(&cache_lock);

    destroy_dev(dev);
#endif
}

int
#if __FreeBSD_version < 500000
kqemu_open(dev, flags, fmt, p)
	dev_t		dev;
	int		flags, fmt;
	struct proc	*p;
{
#else
kqemu_open(dev, flags, fmt, td)
	struct cdev	*dev;
	int		flags, fmt;
	struct thread	*td;
{
	struct proc	*p = td->td_proc;
#endif
    struct kqemu_instance *ks;
    
    if (dev->si_drv1 || kqemu_ref_count >= KQEMU_MAX_INSTANCES)
    	return(EBUSY);

    if ((flags & (FREAD|FWRITE)) == FREAD)
    	return(EPERM);

    ks = (struct kqemu_instance *) malloc(sizeof(*ks), M_KQEMU, M_WAITOK);
    if (ks == NULL)
        return(ENOMEM);
    memset(ks, 0, sizeof *ks);
    
    dev->si_drv1 = ks;
#if __FreeBSD_version > 500000
    ks->kqemu_dev = dev;
    mtx_lock_spin(&cache_lock);
    TAILQ_INSERT_TAIL(&kqemuhead, ks, kqemu_ent);
#endif
    kqemu_ref_count++;
#if __FreeBSD_version > 500000
    mtx_unlock_spin(&cache_lock);
#endif
    kqemu_log("opened by pid=%d\n", p->p_pid);
    return(0);
}

int
#if __FreeBSD_version < 500000
kqemu_close(dev, flags, fmt, p)
	dev_t		dev;
	int		flags, fmt;
	struct proc	*p;
{
#else
kqemu_close(dev, flags, fmt, td)
	struct cdev	*dev;
	int		flags, fmt;
	struct thread	*td;
{
	struct proc	*p = td->td_proc;
#endif
    struct kqemu_instance *ks = (struct kqemu_instance *) dev->si_drv1;

    kqemu_destroy(ks);

    kqemu_log("closed by pid=%d\n", p->p_pid);
    return(0);
}

int
#if __FreeBSD_version < 500000
kqemu_ioctl(dev, cmd, cmdarg, flags, p)
	dev_t		dev;
	unsigned long	cmd;
	caddr_t		cmdarg;
	int		flags;
	struct proc	*p;
{
#else
kqemu_ioctl(dev, cmd, cmdarg, flags, td)
	struct cdev	*dev;
	unsigned long	cmd;
	caddr_t		cmdarg;
	int		flags;
	struct thread	*td;
{
#endif
    struct kqemu_instance *ks = (struct kqemu_instance *) dev->si_drv1;
    struct kqemu_state *s = ks->state;
    long ret;
    int error = 0;

    switch (cmd) {
    case KQEMU_INIT:
    	/*kqemu_log("KQEMU_INIT data=0x%08x\n",cmdarg);*/
    {
        if (s) {
	    error = (EIO);
	    break;
	}

        if (!(s = kqemu_init((struct kqemu_init *)cmdarg, max_locked_pages))) {
	    error = (ENOMEM);
	    break;
	}

        ks->state = s;
	break;
    }
    case KQEMU_EXEC:
    	/*kqemu_log("KQEMU_EXEC data=0x%08x\n",cmdarg);*/
    {
        struct kqemu_cpu_state *ctx;
	
        if (!s) {
	    error = (EIO);
	    break;
	}
            
        ctx = kqemu_get_cpu_state(s);
	memcpy((void *)ctx, (void *)cmdarg, sizeof(struct kqemu_cpu_state));

        ret = kqemu_exec(s);
#if __FreeBSD_version > 500000
	td->td_retval[0] = ret;
#else
	p->p_retval[0] = ret;
#endif
	memcpy((void *)cmdarg, (void *)ctx, sizeof(struct kqemu_cpu_state));

        break;
    }
    case KQEMU_GET_VERSION:
    	/*kqemu_log("KQEMU_GET_VERSION data=0x%08x\n",cmdarg);*/
    {
    	*(int *)cmdarg = KQEMU_VERSION;
	break;
    }
    default:
    	/*kqemu_log("ioctl unknown 0x%08x\n",cmd);*/
        error = (ENXIO);
    }
    return(error);
}

static int
init_module(void)
{
#if __FreeBSD_version < 500000
    int rc;
#endif
    printf("QEMU Accelerator Module version %d.%d.%d, Copyright (c) 2005 Fabrice Bellard\n"
	   "FreeBSD wrapper port, Copyright (c) 2005  Antony T Curtis\n"
           "This is a proprietary product. Read the LICENSE file for more information\n"
           "Redistribution of this module is prohibited without authorization\n",
           (KQEMU_VERSION >> 16),
           (KQEMU_VERSION >> 8) & 0xff,
           (KQEMU_VERSION) & 0xff);

    if (!(pagecache = (struct pagecache **)
          kqemu_vmalloc(1024 * sizeof(void *))))
	return(ENOMEM);
    memset(pagecache, 0, 1024 * sizeof(void *));

#if __FreeBSD_version > 500000
    mtx_init(&cache_lock, "pagecache lock", NULL, MTX_SPIN);
#endif

    max_locked_pages = physmem / (2 * KQEMU_MAX_INSTANCES);
    if (max_locked_pages > 32768)
        max_locked_pages = 32768;

#if __FreeBSD_version < 500000
    if ((rc = cdevsw_add(&kqemu_cdevsw))) {
    	kqemu_log("error registering cdevsw, rc=%d\n", rc);
	return(ENOENT);
    }
	
    kqemu_dev = make_dev(&kqemu_cdevsw, 0, UID_ROOT, GID_WHEEL, 0660, "kqemu");
#else
    clone_setup(&kqemuclones);
    clonetag = EVENTHANDLER_REGISTER(dev_clone, kqemu_clone, 0, 1000);
    if (!clonetag)
	return ENOMEM;
#endif

    kqemu_log("KQEMU installed, max_instances=%d max_locked_mem=%dkB.\n",
              KQEMU_MAX_INSTANCES, max_locked_pages * 4);

    kqemu_ref_count = 0;
    return 0;
}

static void
cleanup_module(void)
{
#if __FreeBSD_version < 500000
    int rc;
#else
    struct kqemu_instance *ks;
#endif
    
#if __FreeBSD_version < 500000
    destroy_dev(kqemu_dev);
    if ((rc = cdevsw_remove(&kqemu_cdevsw)))
	kqemu_log("error unregistering, rc=%d\n", rc);
#else
    EVENTHANDLER_DEREGISTER(dev_clone, clonetag);
    mtx_lock_spin(&cache_lock);
    while ((ks = TAILQ_FIRST(&kqemuhead)) != NULL) {
	mtx_unlock_spin(&cache_lock);
	kqemu_destroy(ks);
	mtx_lock_spin(&cache_lock);
    }
    mtx_unlock_spin(&cache_lock);
    mtx_destroy(&cache_lock);
    clone_cleanup(&kqemuclones);
#endif

    kqemu_vfree(pagecache);
    pagecache = 0;
}

static int
kqemu_modevent(module_t mod, int type, void *data)
{
    int err = 0;
    switch (type) {
    case MOD_LOAD:
    	err = init_module();
	break;
    case MOD_UNLOAD:
    	if (kqemu_ref_count > 0) {
	    err = EBUSY;
	    break;
	}
	/* fall through */
    case MOD_SHUTDOWN:
        cleanup_module();
    	break;
    default:
        err = EINVAL;
    	break;
    }
    return(err);
}

static moduledata_t kqemu_mod = {
	"kqemu_driver",
	kqemu_modevent,
	NULL
};

DECLARE_MODULE(kqemu, kqemu_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);

