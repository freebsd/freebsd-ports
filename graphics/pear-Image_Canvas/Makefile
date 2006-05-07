# Ports collection makefile for:  pear-Image_Canvas
# Date created:			  21 Oct 2005
# Whom:				  Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	Image_Canvas
PORTVERSION=	0.2.4
CATEGORIES=	graphics www pear

MAINTAINER=	numisemis@yahoo.com
COMMENT=	An OO PEAR common interface to image drawing

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Image/Color.php:${PORTSDIR}/graphics/pear-Image_Color

USE_PHP=	gd

CATEGORY=	Image
FILES=		Canvas.php Canvas/Color.php Canvas/GD.php \
		Canvas/ImageMap.php Canvas/PDF.php Canvas/SVG.php \
		Canvas/Tool.php Canvas/WithMap.php Canvas/Fonts/fontmap.txt \
		Canvas/Fonts/README Canvas/GD/JPG.php Canvas/GD/PNG.php

TESTS=		canvas_body.php gradients.php imagemap.php jpg.php \
		lineends.php pdf.php pear-icon.png png.php README svg.php \
		text.php

DOCS=		ChangeLog README examples/canvas.php examples/pear-icon.png

LATEST_LINK=	pear-Image_Canvas

post-patch:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${DISTVERSION}|" ${WRKSRC}/${file}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"

.include <bsd.port.post.mk>
