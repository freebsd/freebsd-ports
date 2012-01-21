# Ports collection makefile for:  pear-Image_Barcode
# Date created:			  11 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Image_Barcode
PORTVERSION=	1.1.2
CATEGORIES=	graphics www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for barcode generation

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	gd

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_PHP_COMPAT "PEAR::PHP_Compat support" off

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_PHP_COMPAT)
RUN_DEPENDS+=	${PEARDIR}/PHP/Compat.php:${PORTSDIR}/devel/pear-PHP_Compat
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
