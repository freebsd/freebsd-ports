# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	Image_Graph
PORTVERSION=	0.8.0
CATEGORIES=	graphics www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	OO PEAR graph rendering package

RUN_DEPENDS=	${PEARDIR}/Log.php:sysutils/pear-Log \
		${PEARDIR}/Image/Canvas.php:graphics/pear-Image_Canvas

USE_PHP=	yes
USES=		dos2unix pear
DOS2UNIX_REGEX=	.*php$$

.include <bsd.port.mk>
