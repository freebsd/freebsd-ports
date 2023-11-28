PORTNAME=	ospray-studio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.1
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Application to showcase OSPRay's rendering capabilities
WWW=		https://www.ospray.org/ospray_studio/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbenchmark.so:devel/benchmark \
		libglfw.so:graphics/glfw \
		libospray.so:graphics/ospray \
		librkcommon.so:devel/rkcommon \
		libtbb.so:devel/onetbb

USES=		cmake gl pkgconfig
USE_GL=		gl glu
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ospray
GH_PROJECT=	${PORTNAME:S/-/_/}

CMAKE_OFF=	USE_PYSG
CMAKE_OFF+=	OSPRAY_INSTALL # otherwise it installs all dependencies, see https://github.com/ospray/ospray_studio/issues/8

PLIST_FILES=	bin/ospStudio \
		lib/libospray_sg.so

post-install:
	@${RM} -rf ${STAGEDIR}${LOCALBASE}/share/doc/ospray_studio

.include <bsd.port.mk>
