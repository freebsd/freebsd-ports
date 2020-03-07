# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	PEAR_Info
PORTVERSION=	1.9.2
PORTREVISION=	2
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Show Information about your PEAR install and its packages

LICENSE=	PHP301

BUILD_DEPENDS=	${PEARDIR}/Console/Getargs.php:devel/pear-Console_Getargs@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Console/Getargs.php:devel/pear-Console_Getargs@${PHP_FLAVOR}

OPTIONS_DEFINE=	PHPUNIT
OPTIONS_DEFAULT=PHPUNIT
PHPUNIT_DESC=	PEAR::PHPUnit support

USES=		pear

PHPUNIT_RUN_DEPENDS=	phpunit:devel/phpunit6@${PHP_FLAVOR}

.include <bsd.port.mk>
