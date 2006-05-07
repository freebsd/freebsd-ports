# New ports collection makefile for:	mingw32-pthreads
# Date created:				28 April 2006
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	pthreads
PORTVERSION=	2.7.0
CATEGORIES=	devel
MASTER_SITES=	ftp://sources.redhat.com/pub/${PORTNAME}-win32/
PKGNAMEPREFIX=	mingw32-
DISTNAME=	${PORTNAME}-w32-${PORTVERSION:S/./-/g}-release

MAINTAINER=	ed@fxq.nl
COMMENT=	POSIX threads library for Windows compiled with MinGW32

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:${PORTSDIR}/devel/mingw32-bin-msvcrt

USE_GMAKE=	yes

do-build:
	@${GMAKE} -C ${WRKSRC} MAKE=${GMAKE} CROSS=${PKGNAMEPREFIX} GC

do-install:
.for f in pthread.h sched.h semaphore.h
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/mingw32/include/$f
.endfor

.for f in libpthreadGC2.a pthreadGC2.dll
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/mingw32/lib/$f
.endfor
	${LN} -sf libpthreadGC2.a ${PREFIX}/mingw32/lib/libpthread.a

.include <bsd.port.mk>
