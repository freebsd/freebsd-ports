# New ports collection makefile for:    linux_devel
# Version required:	0.1
# Date created:         Nov 26 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.8 1998/12/01 09:16:45 asami Exp $
#

DISTNAME=	linux_devel-0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	erich@FreeBSD.org

RUN_DEPENDS=	/compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

ONLY_FOR_ARCHS=	i386

NO_FILTER_SHLIBS=	yes

PREFIX=		/compat/linux
NO_MTREE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty

MANPREFIX=	${PREFIX}/usr
MANCOMPRESSED=	yes
MAN1=   strip.1 ar.1 as.1 gprof.1 ld.1 nm.1 objcopy.1 objdump.1 \
	ranlib.1 size.1 strings-gnu.1 bison.1 yacc.1 flex.1 ansi2knr.1 \
	make.1 gcc.1 g++.1 cccp.1 cpp.1 strace.1 gdb.1
MAN2=	alarm.2 brk.2 cfsetispeed.2 close.2 connect.2 dup.2 dup2.2 execve.2 \
	fchmod.2 setup.2 sgetmask.2 get_kernel_syms.2 getdents.2 \
	getdtablesize.2 getgroups.2 getpid.2 getpgid.2 getpgrp.2 getsockopt.2 \
	getuid.2 ipc.2 getrusage.2 listen.2 llseek.2 lock.2 mknod.2 mmap.2 \
	phys.2 truncate.2 prof.2 profil.2 ptrace.2 read.2 reboot.2 recvmsg.2 \
	semctl.2 semget.2 readdir.2 setitimer.2 setpgrp.2 umask.2 setuid.2 \
	shmat.2 shmctl.2 mpx.2 sigmask.2 sigvec.2 socketcall.2 shmget.2 \
	swapon.2 symlink.2 sysfs.2 sysinfo.2 syslog.2 setrlimit.2 setsid.2 \
	utime.2 utimes.2 setregid.2 shmdt.2 shmop.2 cfgetispeed.2 swapoff.2 \
	sync.2 umount.2 unimplemented.2 bdflush.2 wait4.2 getpagesize.2 \
	waitpid.2 write.2 tcflow.2 exit.2 chmod.2 chown.2 getppid.2 \
	getrlimit.2 gtty.2 lseek.2 ssetmask.2 stty.2 idle.2 sigprocmask.2 \
	tcflush.2 uname.2 getegid.2 stat.2 statfs.2 getgid.2 gethostid.2 \
	setfsgid.2 setfsuid.2 uselib.2 readlink.2 rmdir.2 shutdown.2 socket.2 \
	getpeername.2 select.2 intro.2 setegid.2 seteuid.2 siggetmask.2 \
	tcgetpgrp.2 wait3.2 vm86.2 sigblock.2 sigreturn.2 undocumented.2 \
	munmap.2 nice.2 obsolete.2 oldstat.2 sendto.2 ioctl.2 sethostid.2 \
	sigsuspend.2 socketpair.2 cfgetospeed.2 mprotect.2 msgop.2 bind.2 \
	stime.2 msgctl.2 termios.2 cfsetospeed.2 chdir.2 creat.2 fchdir.2 \
	fchown.2 tcsetattr.2 time.2 times.2 ulimit.2 unlink.2 ioperm.2 \
	mkdir.2 msgrcv.2 oldolduname.2 olduname.2 open.2 pause.2 personality.2 \
	rename.2 send.2 setgid.2 setpgid.2 vhangup.2 fork.2 fstat.2 iopl.2 \
	geteuid.2 init_module.2 setgroups.2 kill.2 fsync.2 gethostname.2 \
	getitimer.2 link.2 lstat.2 modify_ldt.2 modules.2 mount.2 oldlstat.2 \
	sethostname.2 setpriority.2 setsockopt.2 ustat.2 signal.2 _exit.2 \
	accept.2 access.2 acct.2 adjtimex.2 afs_syscall.2 break.2 cacheflush.2 \
	chroot.2 clone.2 create_module.2 delete_module.2 fcntl.2 flock.2 \
	fstatfs.2 ftruncate.2 getdomainname.2 getpriority.2 getsockname.2 \
	gettimeofday.2 killpg.2 msgget.2 msgsnd.2 oldfstat.2 pipe.2 quotactl.2 \
	recv.2 recvfrom.2 sbrk.2 semop.2 sendmsg.2 setdomainname.2 vfork.2 \
	setreuid.2 settimeofday.2 sigaction.2 sigpause.2 sigpending.2 \
	sigsetmask.2 tcdrain.2 tcgetattr.2 tcsendbreak.2 tcsetpgrp.2 wait.2
MAN3=	atol.3 bcmp.3 bcopy.3 bsearch.3 bzero.3 cos.3 exp.3 isalpha.3 \
	log.3 pathconf.3 readv.3 realloc.3 sigdelset.3 stdio.3 \
	swab.3 sysconf.3 tan.3 jn.3 cosh.3 ferror.3 div.3 labs.3 \
	psignal.3 pow.3 erf.3 memchr.3 mrand48.3 pclose.3 clearerr.3 \
	realpath.3 scandir.3 setenv.3 sin.3 y0.3 ftw.3 tmpnam.3 \
	toupper.3 va_end.3 y1.3 yn.3 regfree.3 isdigit.3 j0.3 \
	telldir.3 fgets.3 regcomp.3 ungetc.3 getgrent.3 isinf.3 \
	islower.3 isnan.3 isprint.3 ispunct.3 isupper.3 isxdigit.3 \
	j1.3 ldexp.3 ldiv.3 lgamma.3 putpwent.3 puts.3 qsort.3 \
	erand48.3 finite.3 gethostbyname.3 getmntent.3 getnetbyaddr.3 \
	gets.3 getservbyport.3 getutent.3 getwd.3 isatty.3 memmem.3 \
	memmove.3 mkstemp.3 mktemp.3 mktime.3 nrand48.3 raise.3 \
	scanf.3 setusershell.3 sigaddset.3 strcmp.3 tanh.3 strftime.3 \
	strncmp.3 strncpy.3 strpbrk.3 strcpy.3 strptime.3 strrchr.3 \
	strspn.3 memset.3 putenv.3 sinh.3 strdup.3 strfry.3 string.3 \
	strsep.3 strsignal.3 strstr.3 strtod.3 strtol.3 strtoul.3 \
	strxfrm.3 syslog.3 dn_comp.3 ffs.3 fprintf.3 popen.3 printf.3 \
	setprotoent.3 srand.3 tempnam.3 getopt.3 mblen.3 getprotoent.3 \
	res_mkquery.3 catgets.3 endusershell.3 erfc.3 exec.3 \
	getnetbyname.3 getnetent.3 getopt_long.3 getpass.3 \
	getprotobyname.3 getpwent.3 getpwnam.3 getusershell.3 glob.3 \
	globfree.3 gmtime.3 hcreate.3 inet_makeaddr.3 inet_netof.3 \
	inet_ntoa.3 infnan.3 initstate.3 intro.3 opendir.3 openlog.3 \
	setlocale.3 setservent.3 setstate.3 srand48.3 endhostent.3 \
	res_search.3 res_send.3 resolver.3 rewind.3 rewinddir.3 \
	rindex.3 asinh.3 atan.3 atan2.3 atof.3 closedir.3 closelog.3 \
	ctime.3 drand48.3 execl.3 fnmatch.3 fpathconf.3 fpurge.3 \
	fsetpos.3 isspace.3 localeconv.3 mbstowcs.3 ntohl.3 sqrt.3 \
	tmpfile.3 ttyname.3 asin.3 execle.3 localtime.3 memccpy.3 \
	hasmntopt.3 herror.3 log10.3 malloc.3 lrand48.3 putc.3 \
	setpwent.3 srandom.3 re_exec.3 abs.3 drem.3 endnetent.3 \
	exect.3 execv.3 execvp.3 hdestroy.3 mbtowc.3 memcmp.3 \
	memfrob.3 ntohs.3 on_exit.3 putchar.3 rand.3 random.3 \
	setjmp.3 sleep.3 strcasecmp.3 strncasecmp.3 htonl.3 getcwd.3 \
	getgrnam.3 isgraph.3 hypot.3 index.3 res_query.3 \
	res_querydomain.3 setbuf.3 readdir.3 frexp.3 getc.3 getchar.3 \
	tzset.3 confstr.3 fgetc.3 fgetgrent.3 fileno.3 fwrite.3 \
	fabs.3 fclose.3 feof.3 fgetpos.3 fputs.3 sscanf.3 vsscanf.3 \
	vscanf.3 wctomb.3 inet_addr.3 inet_lnaof.3 setvbuf.3 fseek.3 \
	sigfillset.3 sigemptyset.3 sprintf.3 strcat.3 strchr.3 \
	strcoll.3 wcstombs.3 writev.3 ceil.3 unsetenv.3 usleep.3 \
	clock.3 floor.3 crypt.3 setmntent.3 strncat.3 strtok.3 \
	va_arg.3 sigismember.3 sigsetops.3 stdarg.3 vfscanf.3 \
	vprintf.3 regexec.3 remove.3 inet_network.3 initgroups.3 \
	killpg.3 regerror.3 alloca.3 bstring.3 calloc.3 catopen.3 \
	ecvt.3 endprotoent.3 exit.3 endpwent.3 fopen.3 free.3 \
	ftell.3 ftime.3 gcvt.3 getdirentries.3 getenv.3 getpw.3 \
	getpwuid.3 getservent.3 hsearch.3 abort.3 acos.3 acosh.3 \
	addmntent.3 asctime.3 assert.3 atanh.3 atexit.3 atoi.3 \
	byteorder.3 catclose.3 copysign.3 ctermid.3 difftime.3 \
	dn_expand.3 endgrent.3 endmntent.3 endservent.3 fcvt.3 \
	fdopen.3 fflush.3 fgetpwent.3 fmod.3 fputc.3 fread.3 \
	freopen.3 fscanf.3 ftok.3 get_current_dir_name.3 getgrgid.3 \
	gethostbyaddr.3 htons.3 getprotobynumber.3 getservbyname.3 \
	inet.3 isalnum.3 iscntrl.3 jrand48.3 lcong48.3 longjmp.3 \
	memcpy.3 modf.3 perror.3 re_comp.3 res_init.3 rint.3 seed48.3 \
	seekdir.3 setbuffer.3 setgrent.3 sethostent.3 setlinebuf.3 \
	setnetent.3 strlen.3 siginterrupt.3 strcspn.3 strerror.3 \
	system.3 tolower.3 va_start.3 vfprintf.3 vsprintf.3 gdbm.3

pre-install:
	@[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}

do-install:
	zcat ${DISTDIR}/${DISTNAME}.tar.gz |(cd ${PREFIX}; pax -r)

.include <bsd.port.mk>
