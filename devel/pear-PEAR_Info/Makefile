# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	PEAR_Info
PORTVERSION=	1.9.2
CATEGORIES=	devel www pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	Show Information about your PEAR install and its packages

BUILD_DEPENDS=	${PEARDIR}/Console/Getargs.php:devel/pear-Console_Getargs
RUN_DEPENDS=	${PEARDIR}/Console/Getargs.php:devel/pear-Console_Getargs

OPTIONS_DEFINE=	PEAR_PHPUNIT3
OPTIONS_DEFAULT=	PEAR_PHPUNIT3
PEAR_PHPUNIT3_DESC=	PEAR::PHPUnit3 support

USES=	pear

PEAR_PHPUNIT3_RUN_DEPENDS=	${PEARDIR}/PHPUnit/Autoload.php:devel/pear-PHPUnit3

.include <bsd.port.mk>
