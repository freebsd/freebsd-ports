# Ports collection makefile for:  pear-Image_3D
# Date created:			  01 Mai 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image_3D
PORTVERSION=	0.4.1
CATEGORIES=	graphics www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class allows the rendering of 3 dimensional objects

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	gd

LATEST_LINK=	pear-${PORTNAME}

CATEGORY=	Image
FILES=		Image/3D.php Image/3D/Color.php Image/3D/Coordinate.php \
		Image/3D/Driver.php Image/3D/Enlightenable.php \
		Image/3D/Matrix.php Image/3D/Paintable.php Image/3D/Point.php \
		Image/3D/Renderer.php Image/3D/Vector.php \
		Image/3D/Color/Metal.php Image/3D/Driver/ASCII.php \
		Image/3D/Driver/GD.php Image/3D/Driver/ImageCanvas.php \
		Image/3D/Driver/ImageMagick.php Image/3D/Driver/SVG.php \
		Image/3D/Driver/SVGControl.php Image/3D/Driver/ZBuffer.php \
		Image/3D/Matrix/Move.php Image/3D/Matrix/Rotation.php Image/3D/Matrix/Scale.php \
		Image/3D/Paintable/Light.php Image/3D/Paintable/Polygon.php \
		Image/3D/Paintable/Light/Ambient.php Image/3D/Paintable/Light/Point.php \
		Image/3D/Paintable/Light/Spotlight.php Image/3D/Paintable/Object/3ds.php \
		Image/3D/Paintable/Object/3dsChunks.php Image/3D/Paintable/Object/Bezier.php \
		Image/3D/Paintable/Object/Cone.php Image/3D/Paintable/Object/Cube.php \
		Image/3D/Paintable/Object/Map.php Image/3D/Paintable/Object/Pie.php \
		Image/3D/Paintable/Object/Polygon.php Image/3D/Paintable/Object/Sphere.php \
		Image/3D/Paintable/Object/Text.php Image/3D/Paintable/Object/Torus.php \
		Image/3D/Renderer/Isometric.php Image/3D/Renderer/Perspectively.php

DOCS=		AUTHORS COPYING TODO README
DATA=		TextData.dat
EXAMPLES=	3ds.php ascii.php ascii_demo.php bezier.php cone.php cubes.php \
		map.php pie.php pointlight.php sphere.php spotlights.php \
		text.php torus.php zbuffer.php models/Image_3D.3ds \
		models/cube.3ds
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
