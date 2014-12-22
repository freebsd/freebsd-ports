# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_CodeCoverage
PORTVERSION=	1.2.7
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Library that provides PHP code coverage information

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	pear-File_Iterator>=1.3.0:${PORTSDIR}/devel/pear-File_Iterator \
		pear-PHP_TokenStream>=1.1.3:${PORTSDIR}/devel/pear-PHP_TokenStream \
		pear-Text_Template>=1.1.1:${PORTSDIR}/textproc/pear-Text_Template \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit
RUN_DEPENDS=	pear-File_Iterator>=1.3.0:${PORTSDIR}/devel/pear-File_Iterator \
		pear-PHP_TokenStream>=1.1.3:${PORTSDIR}/devel/pear-PHP_TokenStream \
		pear-Text_Template>=1.1.1:${PORTSDIR}/textproc/pear-Text_Template \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit

USES=	pear
PEAR_CHANNEL=	phpunit

OPTIONS_DEFINE=	DOM XDEBUG
DOM_DESC=	Enable DOM support
XDEBUG_DESC=	Enable Xdebug support

DOM_USE=	PHP=dom
XDEBUG_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/xdebug.so:${PORTSDIR}/devel/php-xdebug

.include <bsd.port.mk>
