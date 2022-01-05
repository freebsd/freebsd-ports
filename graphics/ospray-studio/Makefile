PORTNAME=	ospray-studio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Application to showcase OSPRay's rendering capabilities

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libglfw.so:graphics/glfw \
		libospray.so:graphics/ospray \
		librkcommon.so:devel/rkcommon \
		libtbb.so:devel/onetbb

USES=		cmake gl pkgconfig
USE_GL=		gl glu
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ospray
GH_PROJECT=	${PORTNAME:S/-/_/}

CMAKE_ON=	OSPRAY_INSTALL
CMAKE_OFF=	USE_PYSG

PLIST_FILES=	bin/ospStudio \
		lib/libospray_sg.so

do-install: # workaround for https://github.com/ospray/ospray_studio/issues/8
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ospStudio ${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/libospray_sg.so ${STAGEDIR}${LOCALBASE}/lib

.include <bsd.port.mk>
