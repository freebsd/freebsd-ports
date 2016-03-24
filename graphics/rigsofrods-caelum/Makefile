# Created by: Thibault Payet <monwarez@mailoo.org>
# $FreeBSD$

PORTNAME=	rigsofrods-caelum
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	monwarez@mailoo.org
COMMENT=	OGRE plugin for atmospheric effects

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/lgpl.txt

LIB_DEPENDS=	libOgreMain.so:graphics/ogre3d

USE_GITHUB=	yes
GH_ACCOUNT=	RigsOfRods
GH_PROJECT=	ogre-caelum

USES=		cmake dos2unix pathfix pkgconfig
CMAKE_ARGS=	-DCaelum_BUILD_SAMPLES=FALSE
DOS2UNIX_GLOB=	CMake* *.pc.in
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/install.*DOC_FILES/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
