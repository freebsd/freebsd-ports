# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	directx
PORTVERSION=	20020518
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/extras/win32/cygwin/
PKGNAMEPREFIX=	mingw32-
DISTNAME=	${PORTNAME}-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DirectX header files for use with MinGW

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:devel/mingw32-bin-msvcrt

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/mingw32/include
.for f in d3dtypes.h ddraw.h dinput.h directx.h dsound.h
	${INSTALL_DATA} ${WRKSRC}/include/w32api/$f \
	    ${STAGEDIR}${PREFIX}/mingw32/include/
.endfor

.include <bsd.port.mk>
