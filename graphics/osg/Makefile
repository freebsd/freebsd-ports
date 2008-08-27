# New ports collection makefile for:	Open Scene Graph
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	osg
PORTVERSION=	2.6.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.openscenegraph.org/downloads/stable_releases/OpenSceneGraph-2.6/
DISTNAME=	OpenSceneGraph-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ OpenGL scene graph library for real-time rendering

USE_ZIP=	yes
USE_CMAKE=	yes
USE_GL=		glu

LIB_DEPENDS=    jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

post-patch:
	@${REINPLACE_CMD} -e 's|"64"|""|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
