PORTNAME=	pthreads
PORTVERSION=	2.9.1
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/${PORTNAME}-win32
PKGNAMEPREFIX=	mingw32-
DISTNAME=	${PORTNAME}-w32-${PORTVERSION:S/./-/g}-release

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POSIX threads library for Windows compiled with MinGW32
WWW=		https://sourceware.org/pthreads-win32/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Last upstream release was in 2012 and mingw32 project is defunct
EXPIRATION_DATE=	2023-11-20

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:devel/mingw32-bin-msvcrt

USES=		gmake

do-build:
	@${MAKE_CMD} -C ${WRKSRC} CROSS=${PKGNAMEPREFIX} GC

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/mingw32/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/mingw32/lib
.for f in pthread.h sched.h semaphore.h
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${PREFIX}/mingw32/include/$f
.endfor

.for f in libpthreadGC2.a pthreadGC2.dll
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${PREFIX}/mingw32/lib/$f
.endfor
	${LN} -sf libpthreadGC2.a ${STAGEDIR}${PREFIX}/mingw32/lib/libpthread.a

.include <bsd.port.mk>
