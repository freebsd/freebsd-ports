# New ports collection makefile for: linuxthreads
# Version required:	2.1.2
# Date created:		14 Jan 1999
# Whom:			Richard Seaman, Jr. <dick@tar.com>
#
# $FreeBSD$
#

DISTNAME=      glibc-linuxthreads-2.1.2
PKGNAME=       linuxthreads-2.1.2
CATEGORIES=    devel
MASTER_SITES=  ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR= glibc
ONLY_FOR_ARCHS= i386

MAINTAINER=    jasone@freebsd.org

threads_files := _atomic_lock.S README.FreeBSD clone.S clone.h \
	freebsd-compat.h getgr_r.c gethostby_r.c getnetby_r.c getprotoby_r.c \
	getpw_r.c getservby_r.c lclone.c libc_calls.c libc_thread.c sched.c \
	uthread_file.c

WRKSRC=		${WRKDIR}/${PKGNAME}

SRC_BASE=	/usr/src
LIBSRC_BASE=	${SRC_BASE}/lib

post-extract:
	@mv ${WRKDIR}/linuxthreads ${WRKDIR}/${PKGNAME}
.for src in no-tsd.c oldsemaphore.c weaks.c sysdeps/pthread/semaphore.h
	@mv ${WRKSRC}/$(src) ${WRKSRC}/$(src).unused
.endfor
	@cd ${FILESDIR} ; \
		${CP} -p ${threads_files} ${WRKSRC}/.

post-build:
	@cd ${FILESDIR} ; \
		${MKDIR} ${WRKSRC}/libgcc_r ; \
		${LN} -s ${FILESDIR}/Makefile.libgcc_r ${WRKSRC}/libgcc_r/Makefile
	@cd ${WRKSRC}/libgcc_r ; \
		${MAKE}

pre-install:
	@cd ${WRKSRC}/libgcc_r ; \
		${MAKE} install

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m /usr/lib
	${CAT} ${PKGDIR}/MESSAGE

#	@sh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
