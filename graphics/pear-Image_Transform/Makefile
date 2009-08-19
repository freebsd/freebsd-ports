# Ports collection makefile for:  pear-Image_Transform
# Date created:			  01 Mai 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image_Transform
PORTVERSION=	0.9.3
CATEGORIES=	graphics www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A standard interface to manipulate images using different libraries.

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	gd

#CATEGORY=	Image
FILES=		Image/Transform.php \
		Image/Transform/Driver/Cairowrapper.php \
		Image/Transform/Driver/ColorsDefs.php \
		Image/Transform/Driver/GD.php \
		Image/Transform/Driver/GD1.php \
		Image/Transform/Driver/IM.php \
		Image/Transform/Driver/Imagick/ImageTypes.php \
		Image/Transform/Driver/Imagick2.php \
		Image/Transform/Driver/Imagick3.php \
		Image/Transform/Driver/Imlib.php \
		Image/Transform/Driver/NetPBM.php

EXAMPLES=	resize.php test.gif \
		test.jpg test.php \
		test.png test.tif \
		test_netpbm.php
_EXAMPLESDIR=	Examples

DOCS=		README
_DOCSDIR=	Docs

TESTS=		tests/AllTests.php \
		tests/Image/TransformTest/Base.php \
		tests/Image/TransformTest/Driver/Cairowrapper.php \
		tests/Image/TransformTest/Driver/GD.php \
		tests/Image/TransformTest/Driver/IM.php \
		tests/Image/TransformTest/Driver/Imagick3.php \
		tests/Image/TransformTest/Driver/Imlib.php \
		tests/Image/TransformTest/Driver/NetPBM.php \
		tests/Image/TransformTest/Helper.php \
		tests/Image/TransformTest.php \
		tests/images/alpha-gradient.png \
		tests/images/alpha.png \
		tests/images/base_4x4-flip.png \
		tests/images/base_4x4-mirror.png \
		tests/images/base_4x4-resized-2x2.png \
		tests/images/base_4x4.png \
		tests/images/bggrid.png \
		tests/images/circle.png \
		tests/images/crop.png \
		tests/images/expected/crop_111x111-at-30x30.png \
		tests/images/expected/crop_32x32-at-0x0.png \
		tests/images/expected/crop_40x41-at-0x0.png \
		tests/images/expected/fit150x200px.jpg \
		tests/images/expected/fit200x100px.jpg \
		tests/images/expected/flip-alpha.png \
		tests/images/expected/flip.png \
		tests/images/expected/greyscale.png \
		tests/images/expected/mirror.png \
		tests/images/expected/mixed.jpg \
		tests/images/expected/resizePixel.jpg \
		tests/images/expected/resizePixel.png \
		tests/images/expected/resizeTo150x150px.jpg \
		tests/images/expected/resizeTo150x150px.png \
		tests/images/expected/rotate120.png \
		tests/images/expected/rotate90.png \
		tests/images/expected/scaleByFactor0_33.jpg \
		tests/images/expected/scaleByPct31_5.jpg \
		tests/images/expected/scaleByXTo200px.jpg \
		tests/images/expected/scaleByYTo112px.jpg \
		tests/images/expected/scalePct31_5s.jpg \
		tests/images/grid.png \
		tests/images/icon_15x16.png \
		tests/images/imageinfo_96x32.bmp \
		tests/images/imageinfo_96x32.gif \
		tests/images/imageinfo_96x32.jpeg \
		tests/images/imageinfo_96x32.png \
		tests/images/imageinfo_96x32.wbmp \
		tests/images/imageinfo_96x32.xbm \
		tests/images/mirror-flip.png \
		tests/images/mixed.jpg \
		tests/images/mixed.png \
		tests/images/plasma.png \
		tests/images/resizePixel.png \
		tests/test_common.php \
		imgtests/images/image1.jpg \
		imgtests/images/norfolk_broads.jpg \
		imgtests/images/norfolk_broads.png \
		imgtests/index.php \
		imgtests/norfolk_broads.jpg-GD \
		imgtests/test.php \
		imgtests/text.php
_TESTSDIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
