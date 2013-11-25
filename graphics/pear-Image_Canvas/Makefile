# Created by: Simun Mikecin <numisemis@yahoo.com>
# $FreeBSD$

PORTNAME=	Image_Canvas
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	graphics www pear

MAINTAINER=	numisemis@yahoo.com
COMMENT=	An OO PEAR common interface to image drawing

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Image/Color.php:${PORTSDIR}/graphics/pear-Image_Color

USE_PHP=	gd
USE_DOS2UNIX=	yes

PEAR_AUTOINSTALL=	yes

LATEST_LINK=	pear-Image_Canvas

post-patch:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${DISTVERSION}|" ${WRKSRC}/${file}
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"

.include <bsd.port.post.mk>
