PORTNAME=	directx
PORTVERSION=	20020518
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://www.libsdl.org/extras/win32/cygwin/
PKGNAMEPREFIX=	mingw32-
DISTNAME=	${PORTNAME}-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DirectX header files for use with MinGW
WWW=		https://www.libsdl.org/extras/win32/cygwin/README.txt

DEPRECATED=	Last upstream release was in 2002 and mingw32 project is more or less dead
EXPIRATION_DATE=	2023-11-20

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:devel/mingw32-bin-msvcrt

NO_BUILD=	yes

NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/mingw32/include
.for f in d3dtypes.h ddraw.h dinput.h directx.h dsound.h
	${INSTALL_DATA} ${WRKSRC}/include/w32api/$f \
	    ${STAGEDIR}${PREFIX}/mingw32/include/
.endfor

.include <bsd.port.mk>
