# New ports collection makefile for: linuxthreads
# Date created:		14 Jan 1999
# Whom:			Richard Seaman, Jr. <dick@tar.com>
#
# $FreeBSD$
#

PORTNAME=	linuxthreads
PORTVERSION=	2.2.3
PORTREVISION=	19
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	glibc
DISTNAME=	glibc-linuxthreads-${PORTVERSION}

MAINTAINER=	tegge@freebsd.org
COMMENT=	POSIX pthreads implementation using rfork to generate kernel threads

.if defined(LINUXTHREADS_WRAP_API)
USE_PERL5_BUILD=true
.endif

.include <bsd.port.pre.mk>

# This port only works on i386 right now.
ONLY_FOR_ARCHS=	i386

.if ${OSVERSION} < 400015
BROKEN="Requires FreeBSD 4.0 or newer"
.endif
.if ${OSVERSION} >= 500035
USING_GCC3=true
MAKE_ENV+= USING_GCC3=true
.endif
.if defined(LINUXTHREADS_INSTALL_LIBLTHREAD_PIC_ARCHIVE)
MAKE_ENV+=	INSTALL_LIBLTHREAD_PIC_ARCHIVE=yes
.endif
.if defined(LINUXTHREADS_MAX_STACK_SIZE)
MAKE_ENV+=	LINUXTHREADS_STACK_SIZE=${LINUXTHREADS_MAX_STACK_SIZE}
.endif
.if defined(LINUXTHREADS_MAX_THREADS)
MAKE_ENV+=	LINUXTHREADS_MAX_THREADS=${LINUXTHREADS_MAX_THREADS}
.endif
.if defined(LINUXTHREADS_DETECT_UNSAFE_EXIT)
MAKE_ENV+=	LINUXTHREADS_DETECT_UNSAFE_EXIT=yes
.endif
.if defined(LINUXTHREADS_WRAP_API)
MAKE_ENV+=	LINUXTHREADS_WRAP_API=yes
MAKE_ENV+=	LINUXTHREADS_WRAP_LD="sh ${FILESDIR}/ldwrap"
.endif
.if defined(LINUXTHREADS_NO_POSIX_PRIORITY_SCHEDULING)
MAKE_ENV+=	LINUXTHREADS_NO_POSIX_PRIORITY_SCHEDULING=yes
.endif
.if defined(LINUXTHREADS_ALT_RESTARTSIG)
MAKE_ENV+=	LINUXTHREADS_ALT_RESTARTSIG=${LINUXTHREADS_ALT_RESTARTSIG}
.endif

threads_files := README.FreeBSD clone.S clone.h freebsd-compat.h getgr_r.c \
	gethostby_r.c getnetby_r.c getprotoby_r.c getpw_r.c getservby_r.c \
	lclone.c libc_calls.c libc_thread.c sched.c uthread_file.c \
	wraputhread.c localtime.c getlogin.c telldir.c ttyname.c

threads_files2 := _pthreadtypes.h

WRKSRC=		${WRKDIR}/${PKGNAME}
SRC_BASE=	/usr/src
LIBSRC_BASE=	${SRC_BASE}/lib

pre-fetch:
.if !defined(LINUXTHREADS_WITH_CONDWAIT_PATCH)
	@${ECHO}
	@${ECHO} You can use an experimental patch to reduce the number of
	@${ECHO} condition variable triggered context switches by defining
	@${ECHO} LINUXTHREADS_WITH_CONDWAIT_PATCH
	@${ECHO}
.endif
.if !defined(LINUXTHREADS_DETECT_UNSAFE_EXIT)
	@${ECHO}
	@${ECHO} "Some unsafe calls to exit() can be detected by defining"
	@${ECHO} "LINUXTHREADS_DETECT_UNSAFE_EXIT, see files/README.FreeBSD"
	@${ECHO} "for more info."
	@${ECHO}
.endif
.if !defined(LINUXTHREADS_MAX_STACK_SIZE)
	@${ECHO}
	@${ECHO} "The maximum stack size (default 2097152) can be overridden"
	@${ECHO} "by defining LINUXTHREADS_MAX_STACK_SIZE,"
	@${ECHO} "see files/README.FreeBSD for more info."
	@${ECHO}
.endif
.if !defined(LINUXTHREADS_MAX_THREADS)
	@${ECHO}
	@${ECHO} "The maximum number of threads (default 1024) can be"
	@${ECHO} "overriden by defining LINUXTHREADS_MAX_THREADS,"
	@${ECHO} "see files/README.FreeBSD for more info."
	@${ECHO}
.endif
.if !defined(LINUXTHREADS_WRAP_API)
	@${ECHO}
	@${ECHO} "Some conflicts with native threads can be avoided by defining"
	@${ECHO} "LINUXTHREADS_WRAP_API, see files/README.FreeBSD"
	@${ECHO} "for more info."
	@${ECHO}
.endif
.if !defined(LINUXTHREADS_NO_POSIX_PRIORITY_SCHEDULING)
	@${ECHO}
	@${ECHO} "Use of POSIX priority scheduling can be turned off by"
	@${ECHO} "defining LINUXTHREADS_NO_POSIX_PRIORITY_SCHEDULING,"
	@${ECHO} "see files/README.FreeBSD for more info."
	@${ECHO}
.endif
.if !defined(LINUXTHREADS_ALT_RESTARTSIG)
	@${ECHO}
	@${ECHO} "An alternate restart signal can be selected by"
	@${ECHO} "defining LINUXTHREADS_ALT_RESTARTSIG,"
	@${ECHO} "see files/README.FreeBSD for more info."
	@${ECHO}
.endif
	@if ${TEST} -f /usr/src/gnu/lib/libgcc/Makefile; then \
	  : ; \
	else \
	  ${ECHO_MSG} ">>The linuxthreads port needs source code for libgcc"; \
	  ${ECHO_MSG} ">>Please install FreeBSD source code in /usr/src"; \
	  ${FALSE}; \
	fi
.if defined(USING_GCC3)
	@if ${TEST} -f /usr/src/gnu/lib/libstdc++/Makefile; then \
	  : ; \
	else \
	  ${ECHO_MSG} ">>The linuxthreads port needs source code for libstdc++"; \
	  ${ECHO_MSG} ">>Please install FreeBSD source code in /usr/src"; \
	  ${FALSE}; \
	fi
	@if ${TEST} -f /usr/src/gnu/lib/libsupc++/Makefile; then \
	  : ; \
	else \
	  ${ECHO_MSG} ">>The linuxthreads port needs source code for libsupc++"; \
	  ${ECHO_MSG} ">>Please install FreeBSD source code in /usr/src"; \
	  ${FALSE}; \
	fi
.endif

post-extract:
	@${MV} ${WRKDIR}/linuxthreads ${WRKSRC}
	@${MV} ${WRKDIR}/linuxthreads_db ${WRKSRC}
.for src in lockfile.c no-tsd.c oldsemaphore.c weaks.c \
	sysdeps/pthread/semaphore.h
	@${MV} ${WRKSRC}/$(src) ${WRKSRC}/$(src).unused
.endfor
	@cd ${FILESDIR} ; \
		${CP} -p ${threads_files} ${WRKSRC}/.
	@${SED} -f ${FILESDIR}/strptime.sed \
	    /usr/src/lib/libc/stdtime/strptime.c \
	    > ${WRKSRC}/strptime.c
	@${MKDIR} ${WRKSRC}/sys
	@cd ${FILESDIR} ; \
		${CP} -p ${threads_files2} ${WRKSRC}/sys/.
	@${MKDIR} ${WRKSRC}/libgcc_r
	@${TEST} -f ${WRKSRC}/libgcc_r/Makefile || \
	${LN} -s ${FILESDIR}/Makefile.libgcc_r ${WRKSRC}/libgcc_r/Makefile
	@${SED} -e 's/^LIB=[ 	]*gcc$$/LIB=	lgcc_r/;' \
	     -e 's=$${.CURDIR}=/usr/src/gnu/lib/libgcc=g' \
	  /usr/src/gnu/lib/libgcc/Makefile \
	  > ${WRKSRC}/libgcc_r/Makefile.inc.tmp && \
	${MV} ${WRKSRC}/libgcc_r/Makefile.inc.tmp \
	   ${WRKSRC}/libgcc_r/Makefile.inc
.if defined(USING_GCC3)
	@${MKDIR} ${WRKSRC}/libstdc++
	@${TEST} -f ${WRKSRC}/libstdc++/Makefile || \
	${LN} -s ${FILESDIR}/Makefile.libstdc++ ${WRKSRC}/libstdc++/Makefile
	@${SED} -e 's/^LIB=[ 	]*stdc\+\+$$/LIB=	lstdc++/;' \
	     -e 's=$${.CURDIR}=/usr/src/gnu/lib/libstdc++=g' \
	  /usr/src/gnu/lib/libstdc++/Makefile \
	  > ${WRKSRC}/libstdc++/Makefile.inc.tmp && \
	${MV} ${WRKSRC}/libstdc++/Makefile.inc.tmp \
	   ${WRKSRC}/libstdc++/Makefile.inc
	@${MKDIR} ${WRKSRC}/libsupc++
	@${TEST} -f ${WRKSRC}/libsupc++/Makefile || \
	${LN} -s ${FILESDIR}/Makefile.libsupc++ ${WRKSRC}/libsupc++/Makefile
	@${SED} -e 's/^LIB=[ 	]*supc\+\+$$/LIB=	lsupc++/;' \
	     -e 's=$${.CURDIR}=/usr/src/gnu/lib/libsupc++=g' \
	  /usr/src/gnu/lib/libsupc++/Makefile \
	  > ${WRKSRC}/libsupc++/Makefile.inc.tmp && \
	${MV} ${WRKSRC}/libsupc++/Makefile.inc.tmp \
	   ${WRKSRC}/libsupc++/Makefile.inc
.endif

.if defined(LINUXTHREADS_WITH_CONDWAIT_PATCH) || defined(LINUXTHREADS_WRAP_API)
post-patch:
.if defined(LINUXTHREADS_WITH_CONDWAIT_PATCH)
	@${ECHO_MSG} "===>  Applying experimental patch condwait-patch"
	@if ${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/condwait-patch; then \
	  ${ECHO_MSG} "===>  Patch condwait-patch applied successfully"; \
	else \
	  ${ECHO_MSG} ">>Patch condwait-patch failed to apply cleanly"; \
	  ${FALSE}; \
	fi
.endif
.if defined(LINUXTHREADS_WRAP_API)
	perl -pi -e '$$func=$$1 if m/^extern\s+\S+\s+\*?(\S+)\s+\(/; $$alias="#ifdef COMPILING_WRAPUTHREAD\n\t__attribute__((weak, alias(\"_$$func\")))\n#endif\n"; $$wrap="#ifndef COMPILING_LINUXTHREADS\n\t__asm__(\"linuxthreads_$$func\")\n#endif\n"; $$alias="" if ( $$func =~ m/^(pthread_spin|_pthread_cleanup|pthread_rwlockattr_[gs]etkind_np|pthread_kill_other_threads_np)/ ); s=__THROW=\n$$wrap$$alias\t__THROW= unless m/^#/;' ${WRKSRC}/sysdeps/pthread/pthread.h  ${WRKSRC}/sysdeps/unix/sysv/linux/bits/sigthread.h
.endif
.endif

pre-build:
	@cd ${WRKSRC}/libgcc_r ; \
		${SETENV} ${MAKE_ENV} ${MAKE}
.if defined(USING_GCC3)
	cd ${WRKSRC}/libstdc++ ; \
		${SETENV} ${MAKE_ENV} ${MAKE}
	@cd ${WRKSRC}/libsupc++ ; \
		${SETENV} ${MAKE_ENV} ${MAKE}
.endif

pre-install:
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 0755 ${PREFIX}/lib
	@cd ${WRKSRC}/libgcc_r ; \
		${SETENV} ${MAKE_ENV} ${MAKE} install
.if defined(USING_GCC3)
	@cd ${WRKSRC}/libstdc++ ; \
		${SETENV} ${MAKE_ENV} ${MAKE} install
	@cd ${WRKSRC}/libsupc++ ; \
		${SETENV} ${MAKE_ENV} ${MAKE} install
.endif

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m /usr/lib
	${CAT} ${PKGMESSAGE}

#	@sh ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.if (defined(NOPROFILE) && ${OSVERSION} < 600007) || (defined(NO_PROFILE) && ${OSVERSION} >= 600007)
PLIST_SUB=	PROFILE:="@comment "
.else
PLIST_SUB=	PROFILE:=""
.endif
.if (defined(NOPIC) && ${OSVERSION} < 600007) || (defined(NO_PIC) && ${OSVERSION} >= 600007)
PLIST_SUB+=	PIC:="@comment "
.else
PLIST_SUB+=	PIC:=""
.endif
.if defined(INSTALL_PIC_ARCHIVE)
PLIST_SUB+=	PICARCHIVE:=""
.else
PLIST_SUB+=	PICARCHIVE:="@comment "
.endif
.if defined(INSTALL_PIC_ARCHIVE) || ${OSVERSION} >= 501101
PLIST_SUB+=	LIBLGCC_R_PICARCHIVE:=""
.else
PLIST_SUB+=	LIBLGCC_R_PICARCHIVE:="@comment "
.endif
.if defined(INSTALL_PIC_ARCHIVE) || defined(LINUXTHREADS_INSTALL_LIBLTHREAD_PIC_ARCHIVE)
PLIST_SUB+=	LIBLTHREADPICARCHIVE:=""
.else
PLIST_SUB+=	LIBLTHREADPICARCHIVE:="@comment "
.endif
.if defined(USING_GCC3)
PLIST_SUB+=	GCC3ONLY:=""
.if defined(LINUXTHREADS_WRAP_API)
PLIST_SUB+=	LTHREADSHMAJOR:="5"
.else
PLIST_SUB+=	LTHREADSHMAJOR:="3"
.endif
.else
PLIST_SUB+=	GCC3ONLY:="@comment "
.if defined(LINUXTHREADS_WRAP_API)
PLIST_SUB+=	LTHREADSHMAJOR:="4"
.else
PLIST_SUB+=	LTHREADSHMAJOR:="2"
.endif
.endif
.if ${OSVERSION} >= 600033
PLIST_SUB+=	LIBSTDCPPMAJOR:="5"
.else
PLIST_SUB+=	LIBSTDCPPMAJOR:="4"
.endif

.include <bsd.port.post.mk>
