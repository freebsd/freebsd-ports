# New ports collection makefile for: linuxthreads
# Date created:		14 Jan 1999
# Whom:			Richard Seaman, Jr. <dick@tar.com>
#
# $FreeBSD$
#

PORTNAME=	linuxthreads
PORTVERSION=	2.1.3
PORTREVISION=	2
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

threads_files := README.FreeBSD clone.S clone.h freebsd-compat.h getgr_r.c \
	gethostby_r.c getnetby_r.c getprotoby_r.c getpw_r.c getservby_r.c \
	lclone.c libc_calls.c libc_thread.c sched.c uthread_file.c \
	wraputhread.c

WRKSRC=		${WRKDIR}/${PKGNAME}
SRC_BASE=	/usr/src
LIBSRC_BASE=	${SRC_BASE}/lib

post-extract:
	@mv ${WRKDIR}/linuxthreads ${WRKSRC}
	@mv ${WRKDIR}/linuxthreads_db ${WRKSRC}
.for src in lockfile.c no-tsd.c oldsemaphore.c weaks.c \
	sysdeps/pthread/semaphore.h
	@mv ${WRKSRC}/$(src) ${WRKSRC}/$(src).unused
.endfor
	@cd ${FILESDIR} ; \
		${CP} -p ${threads_files} ${WRKSRC}/.
	@${MKDIR} -p ${WRKSRC}/libgcc_r
	@test -f ${WRKSRC}/libgcc_r/Makefile || \
	${LN} -s ${FILESDIR}/Makefile.libgcc_r ${WRKSRC}/libgcc_r/Makefile

pre-build:
	@cd ${WRKSRC}/libgcc_r ; \
		${MAKE}

pre-install:
	@cd ${WRKSRC}/libgcc_r ; \
		${MAKE} install

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m /usr/lib
	${CAT} ${PKGMESSAGE}

#	@sh ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
