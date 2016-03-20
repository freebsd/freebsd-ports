# Created by: Thibault Payet <monwarez@mailoo.org>
# $FreeBSD$

PORTNAME=	rigsofrods-pagedgeometry
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	monwarez@mailoo.org
COMMENT=	OGRE plugin for real-time dense forests

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/zlib.txt

LIB_DEPENDS=	libOgreMain.so:graphics/ogre3d

USE_GITHUB=	yes
GH_ACCOUNT=	RigsOfRods
GH_PROJECT=	ogre-pagedgeometry

USES=		cmake dos2unix pathfix pkgconfig
DOS2UNIX_GLOB=	*.cpp *.h *.txt
CMAKE_ARGS=	-DPAGEDGEOMETRY_BUILD_SAMPLES=FALSE
USE_LDCONFIG=	yes

# XXX dialog(1) doesn't like ^M in LICENSE_FILE
post-extract:	dos2unix

post-patch:
	@${REINPLACE_CMD} -e '/install.*DOC_FILES/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
