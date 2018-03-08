# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	PEAR_Info
PORTVERSION=	1.9.2
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Show Information about your PEAR install and its packages

BUILD_DEPENDS=	${PEARDIR}/Console/Getargs.php:devel/pear-Console_Getargs@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Console/Getargs.php:devel/pear-Console_Getargs@${PHP_FLAVOR}

OPTIONS_DEFINE=	PHPUNIT
OPTIONS_DEFAULT=PHPUNIT
PHPUNIT_DESC=	PEAR::PHPUnit support

USES=		pear

PHPUNIT_RUN_DEPENDS=	phpunit:devel/phpunit@${PHP_FLAVOR}

.include <bsd.port.mk>
