# New ports collection makefile for:   linuxthreads
# Version required:	0.71
# Date created:		14 Jan 1999
# Whom:			Richard Seaman, Jr. <dick@tar.com>
#
# $FreeBSD$
#

DISTNAME=      linuxthreads
PKGNAME=       linuxthreads-0.71
CATEGORIES=    devel
MASTER_SITES=  ftp://ftp.inria.fr/INRIA/Projects/cristal/Xavier.Leroy/
ONLY_FOR_ARCHS= i386

#MAINTAINER=    dick@tar.com
MAINTAINER=    jasone@freebsd.org

threads_files=	_atomic_lock.S  libc_spinlock.h   uthread_rwlock.c \
		uthread_rwlockattr.c libc_private.h uthread_file.c \
		clone.S clone.h lclone.c sched.c spinlock.c libc_calls.c \
		README.FreeBSD getgr_r.c syscalls.c libc_thread.c pthread_stack.h \
		stack.c stack_attr.c pthread_rw.h pthread_private.h

WRKSRC=		${WRKDIR}/${PKGNAME}

SRC_BASE=	/usr/src
LIBSRC_BASE=	${SRC_BASE}/lib

post-extract:
	@mv ${WRKSRC}/semaphore.h ${WRKSRC}/semaphore.h.unused
	@mv ${WRKSRC}/semaphore.c ${WRKSRC}/semaphore.c.unused
	@rm ${WRKSRC}/.depend
	@rm ${WRKSRC}/.cvsignore
	@cd ${FILESDIR} ; \
		${CP} -p ${threads_files} ${WRKSRC}/.  ;  \
		${CP} -p Examples/ex6.c ${WRKSRC}/Examples/.

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
	@sh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m /usr/lib
	${CAT} ${PKGDIR}/MESSAGE
	@echo ""
	@echo "Also see the file README.FreeBSD"
	@echo ""

.include <bsd.port.mk>
