#pragma once

#include <sys/param.h>
#include <sys/cdefs.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <errno.h>
#include <endian.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include <libintl.h>

/* asm/bitsperlong.h */
/*
 * In FreeBSD, __ILP32__ / __LP64__ are canonical, but gcc does not correctly
 * emit __ILP32__ in 32-bit mode, at least on i386.
 */
#if __SIZEOF_LONG__ == 4 /* defined(__ILP32__) */
#define	__BITS_PER_LONG	32
#elif __SIZEOF_LONG__ == 8 /* defined(__LP64__) */
#define	__BITS_PER_LONG	64
#else
#error "I'm a teapot"
#endif

/* asm/types.h */
typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint64_t __u64;
typedef int8_t __s8;
typedef int16_t __s16;
typedef int32_t __s32;
typedef int64_t __s64;

/* linux/types.h */
typedef uint16_t __be16;
typedef uint32_t __be32;
typedef uint64_t __be64;
typedef uint16_t __le16;
typedef uint32_t __le32;
typedef uint64_t __le64;
#define	__aligned_u64	__u64 __attribute__((aligned(8)))

/* search.h */
#if __FreeBSD_version < 1600000
static inline void
tdestroy(void *vroot __unused, void (*freefct)(void *) __unused)
{

	/* XXX: Just leak the memory for now. */
}
#endif

/* our libc++ defines in this way */
#ifndef ENODATA
#define ENODATA 9919
#endif

#ifndef EUCLEAN
#define EUCLEAN 8818
#endif

#if BYTE_ORDER == LITTLE_ENDIAN
#define __LITTLE_ENDIAN_BITFIELD
#else
#define __BIG_ENDIAN_BITFIELD
#endif

#ifndef KERNEL_VERSION
#define KERNEL_VERSION(a, b, c) (((a) << 16) + ((b) << 8) + ((c) > 255 ? 255 : (c)))
#endif

/* bpf stuff */
typedef struct pt_regs bpf_user_pt_regs_t;
struct pt_regs {
/*
 * C ABI says these regs are callee-preserved. They aren't saved on kernel entry
 * unless syscall needs a complete, fully filled "struct pt_regs".
 */
	unsigned long r15;
	unsigned long r14;
	unsigned long r13;
	unsigned long r12;
	unsigned long rbp;
	unsigned long rbx;
/* These regs are callee-clobbered. Always saved on kernel entry. */
	unsigned long r11;
	unsigned long r10;
	unsigned long r9;
	unsigned long r8;
	unsigned long rax;
	unsigned long rcx;
	unsigned long rdx;
	unsigned long rsi;
	unsigned long rdi;
/*
 * On syscall entry, this is syscall#. On CPU exception, this is error code.
 * On hw interrupt, it's IRQ number:
 */
	unsigned long orig_rax;
/* Return frame for iretq */
	unsigned long rip;
	unsigned long cs;
	unsigned long eflags;
	unsigned long rsp;
	unsigned long ss;
/* top of stack page */
};
#define __NR_perf_event_open (-1)

/* netlink stuff */
typedef __sa_family_t __kernel_sa_family_t;
struct ifinfomsg {
	unsigned char	ifi_family;
	unsigned char	__ifi_pad;
	unsigned short	ifi_type;		/* ARPHRD_* */
	int		ifi_index;		/* Link index	*/
	unsigned	ifi_flags;		/* IFF_* flags	*/
	unsigned	ifi_change;		/* IFF_* change mask */
};
struct tcmsg {
	unsigned char	tcm_family;
	unsigned char	tcm__pad1;
	unsigned short	tcm__pad2;
	int		tcm_ifindex;
	__u32		tcm_handle;
	__u32		tcm_parent;
/* tcm_block_index is used instead of tcm_parent
 * in case tcm_ifindex == TCM_IFINDEX_MAGIC_BLOCK
 */
#define tcm_block_index tcm_parent
	__u32		tcm_info;
};
struct genlmsghdr {
	__u8	cmd;
	__u8	version;
	__u16	reserved;
};

#define AF_PACKET 0
#define GENL_HDRLEN 0
#define CTRL_ATTR_FAMILY_ID 0
#define GENL_ID_CTRL 0
#define CTRL_CMD_GETFAMILY 0
#define CTRL_ATTR_FAMILY_NAME 0
#define RTM_SETLINK 0
#define RTM_GETLINK 0
#define RTM_NEWQDISC 0
#define RTM_DELQDISC 0
#define RTM_NEWTFILTER 0
#define RTM_DELTFILTER 0
#define RTM_GETTFILTER 0
#define ETH_P_ALL 0

#define IFLA_MAX 0
#define IFLA_XDP 0
#define IFLA_XDP_ATTACHED 0
#define IFLA_XDP_DRV_PROG_ID 0
#define IFLA_XDP_EXPECTED_FD 0
#define IFLA_XDP_FD 0
#define IFLA_XDP_FLAGS 0
#define IFLA_XDP_HW_PROG_ID 0
#define IFLA_XDP_MAX 0
#define IFLA_XDP_PROG_ID 0
#define IFLA_XDP_SKB_PROG_ID 0
#define XDP_ATTACHED_MULTI 0
#define XDP_ATTACHED_NONE 0
#define XDP_FLAGS_DRV_MODE 0
#define XDP_FLAGS_HW_MODE 0
#define XDP_FLAGS_MASK 0
#define XDP_FLAGS_MODES 0
#define XDP_FLAGS_REPLACE 0
#define XDP_FLAGS_SKB_MODE 0

#define TCA_KIND 0
#define TCA_OPTIONS 0
#define TCA_MAX 0

void       tdestroy(void *, void (*)(void *));
