PORTNAME=	rigsofrods-pagedgeometry
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0.20240708
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	monwarez@mailoo.org
COMMENT=	OGRE plugin for real-time dense forests
WWW=		https://www.ogre3d.org/tikiwiki/PagedGeometry+Engine

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/zlib.txt

LIB_DEPENDS=	libOgreMain.so:graphics/ogre3d

USES=		cmake dos2unix pathfix pkgconfig
DOS2UNIX_GLOB=	*.cpp *.h *.txt
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	RigsOfRods
GH_PROJECT=	ogre-pagedgeometry
GH_TAGNAME=	428a57a
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DPAGEDGEOMETRY_BUILD_SAMPLES=FALSE

post-patch:
	@${REINPLACE_CMD} -e '/install.*DOC_FILES/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
