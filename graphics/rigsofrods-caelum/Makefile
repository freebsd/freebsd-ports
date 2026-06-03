PORTNAME=	rigsofrods-caelum
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	monwarez@mailoo.org
COMMENT=	OGRE plugin for atmospheric effects
WWW=		https://www.ogre3d.org/tikiwiki/Caelum

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/lgpl.txt

LIB_DEPENDS=	libOgreMain.so:graphics/ogre3d19

USES=		cmake dos2unix pathfix pkgconfig
DOS2UNIX_GLOB=	CMake* *.pc.in
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	RigsOfRods
GH_PROJECT=	ogre-caelum
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCaelum_BUILD_SAMPLES=FALSE

post-patch:
	@${REINPLACE_CMD} -e '/install.*DOC_FILES/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
