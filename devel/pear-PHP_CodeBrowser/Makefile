# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_CodeBrowser
PORTVERSION=	1.0.2
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Code browser that augments the code with information

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PEAR_PKGNAMEPREFIX}Console_CommandLine>=1.2.2:devel/pear-Console_CommandLine@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}File_Iterator>=1.4.2:devel/pear-File_Iterator@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Log>=1.13.1:sysutils/pear-Log@${PHP_FLAVOR}
RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Console_CommandLine>=1.2.2:devel/pear-Console_CommandLine@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}File_Iterator>=1.4.2:devel/pear-File_Iterator@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Log>=1.13.1:sysutils/pear-Log@${PHP_FLAVOR}

USES=	pear php
PEAR_CHANNEL=	phpunit

.include <bsd.port.mk>
