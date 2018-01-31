# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_CodeCoverage
DISTVERSION=	5.2.2
CATEGORIES=	devel pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Library that provides PHP code coverage information

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pear-File_Iterator>=1.4.2:devel/pear-File_Iterator \
		pear-PHP_TokenStream>=1.4.11:devel/pear-PHP_TokenStream \
		pear-Text_Template>=1.2.0:textproc/pear-Text_Template \
		pear-channel-phpunit>=20110327:devel/pear-channel-phpunit
RUN_DEPENDS=	pear-File_Iterator>=1.4.2:devel/pear-File_Iterator \
		pear-PHP_TokenStream>=1.4.11:devel/pear-PHP_TokenStream \
		pear-Text_Template>=1.2.0:textproc/pear-Text_Template \
		pear-channel-phpunit>=20110327:devel/pear-channel-phpunit

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	php-code-coverage

NO_BUILD=	yes

OPTIONS_DEFINE=	DOM XDEBUG
DOM_DESC=	Enable DOM support
XDEBUG_DESC=	Enable Xdebug support

DOM_USE=	PHP=dom
XDEBUG_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/xdebug.so:devel/pecl-xdebug

PHP_DIR=	share/PHP

PLIST_FILES=	${PHP_DIR}/${PORTNAME}/CodeCoverage.php

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/src/CodeCoverage.php \
		${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}

.include <bsd.port.mk>
