# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	fXSL
PORTVERSION=	1.1.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.netpirates.net/get/
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}TheSeer_
EXTRACT_SUFX=	.tgz

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	XSL wrapper / extension to the PHP 5.x XSLTProcessor

LICENSE=	BSD3CLAUSE

BROKEN_powerpc64=	fails to package: Signal 11

USE_PHP=	dom xml xsl
PEAR_CHANNEL=	theseer
USES=	pear

.include <bsd.port.mk>
