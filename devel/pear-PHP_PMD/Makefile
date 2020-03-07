# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_PMD
PORTVERSION=	1.5.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpmd.org/get/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP Mess Detector

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	skipv=2.*

USES=		pear php
PEAR_CHANNEL=	phpmd
USE_PHP=	dom simplexml
NO_ARCH=	yes

.include <bsd.port.mk>
