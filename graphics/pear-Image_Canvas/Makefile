# Ports collection makefile for:  pear-Image_Canvas
# Date created:			  21 Oct 2005
# Whom:				  Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	Image_Canvas
PORTVERSION=	0.3.2
CATEGORIES=	graphics www pear

MAINTAINER=	numisemis@yahoo.com
COMMENT=	An OO PEAR common interface to image drawing

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Image/Color.php:${PORTSDIR}/graphics/pear-Image_Color

USE_PHP=	gd
USE_DOS2UNIX=	yes

FILES=		Image/Canvas.php Image/Canvas/Color.php Image/Canvas/GD.php \
		Image/Canvas/ImageMap.php Image/Canvas/PDF.php Image/Canvas/PS.php \
		Image/Canvas/SVG.php Image/Canvas/SWF.php Image/Canvas/Tool.php \
		Image/Canvas/WithMap.php Image/Canvas/Fonts/fontmap.txt \
		Image/Canvas/Fonts/README Image/Canvas/GD/JPG.php \
		Image/Canvas/GD/PNG.php
TESTS=		canvas_body.php gradients.php imagemap.php jpg.php \
		lineends.php pdf.php pear-icon.png png.php ps.php \
		README svg.php text.php
DOCS=		ChangeLog README TODO
EXAMPLES=	canvas.php pear-icon.png
_EXAMPLESDIR=	docs/examples

LATEST_LINK=	pear-Image_Canvas

post-patch:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${DISTVERSION}|" ${WRKSRC}/${file}
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"

.include <bsd.port.post.mk>
