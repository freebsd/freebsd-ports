PORTNAME=	ois
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Object Oriented Input System
WWW=		https://wgois.github.io/OIS/ \
		https://github.com/wgois/OIS

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		cmake xorg
USE_GITHUB=	yes
GH_ACCOUNT=	wgois
GH_PROJECT=	OIS
USE_XORG=	x11
USE_LDCONFIG=	yes

CXXFLAGS+=	-Wno-unused-value \
		-D__s16=int16_t \
		-D__s32=int32_t \
		-D__u16=uint16_t

OPTIONS_DEFINE=	DEMOS
OPTIONS_SUB=	yes

DEMOS_DESC=		Build demo applications
DEMOS_CMAKE_BOOL=	OIS_BUILD_DEMOS

post-install-DEMOS-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ConsoleApp ${STAGEDIR}${PREFIX}/bin/OIS-ConsoleDemo
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/FFConsoleApp ${STAGEDIR}${PREFIX}/bin/OIS-FFConsoleDemo

.include <bsd.port.mk>
