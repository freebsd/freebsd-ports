PORTNAME=	libuiohook
DISTVERSION=	1.2.2-11
DISTVERSIONSUFFIX=	-gf259ff3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library to provide global keyboard and mouse hooks from userland
WWW=		https://github.com/kwhat/libuiohook

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER.md

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libxkbfile.so:x11/libxkbfile

USES=		cmake pkgconfig xorg
USE_XORG=	x11 xcb xinerama xt xtst
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kwhat

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
