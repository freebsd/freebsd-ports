# New ports collection makefile for: linuxthreads
# Date created:		14 Jan 1999
# Whom:			Richard Seaman, Jr. <dick@tar.com>
#
# $FreeBSD$
#

PORTNAME=	linuxthreads
PORTVERSION=	2.2.3
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	glibc
DISTNAME=	glibc-linuxthreads-${PORTVERSION}

MAINTAINER=	tegge@freebsd.org

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
.if defined(INSTALL_LIBLTHREAD_PIC_ARCHIVE)
MAKE_ENV+=	INSTALL_LIBLTHREAD_PIC_ARCHIVE=yes
.endif

threads_files := README.FreeBSD clone.S clone.h freebsd-compat.h getgr_r.c \
	gethostby_r.c getnetby_r.c getprotoby_r.c getpw_r.c getservby_r.c \
	lclone.c libc_calls.c libc_thread.c sched.c uthread_file.c \
	wraputhread.c localtime.c

WRKSRC=		${WRKDIR}/${PKGNAME}
SRC_BASE=	/usr/src
LIBSRC_BASE=	${SRC_BASE}/lib

pre-fetch:
.if !defined(WITH_CONDWAIT_PATCH)
	@${ECHO}
	@${ECHO} You can use an experimental patch to reduce the number of
	@${ECHO} condition variable triggered context switches by defining
	@${ECHO} WITH_CONDWAIT_PATCH
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

.if defined(WITH_CONDWAIT_PATCH)
post-patch:
	@${ECHO_MSG} "===>  Applying experimental patch condwait-patch"
	@if ${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/condwait-patch; then \
	  ${ECHO_MSG} "===>  Patch condwait-patch applied successfully"; \
	else \
	  ${ECHO_MSG} ">>Patch condwait-patch failed to apply cleanly"; \
	  ${FALSE}; \
	fi
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

.if defined(NOPROFILE)
PLIST_SUB=	PROFILE:="@comment "
.else
PLIST_SUB=	PROFILE:=""
.endif
.if defined(NOPIC)
PLIST_SUB+=	PIC:="@comment "
.else
PLIST_SUB+=	PIC:=""
.endif
.if defined(INSTALL_PIC_ARCHIVE)
PLIST_SUB+=	PICARCHIVE:=""
.else
PLIST_SUB+=	PICARCHIVE:="@comment "
.endif
.if defined(INSTALL_PIC_ARCHIVE) || defined(INSTALL_LIBLTHREAD_PIC_ARCHIVE)
PLIST_SUB+=	LIBLTHREADPICARCHIVE:=""
.else
PLIST_SUB+=	LIBLTHREADPICARCHIVE:="@comment "
.endif
.if defined(USING_GCC3)
PLIST_SUB+=	GCC3ONLY:=""
PLIST_SUB+=	LTHREADSHMAJOR:="3"
.else
PLIST_SUB+=	GCC3ONLY:="@comment "
PLIST_SUB+=	LTHREADSHMAJOR:="2"
.endif

.include <bsd.port.post.mk>
