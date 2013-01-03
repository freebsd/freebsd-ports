# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_CodeCoverage
PORTVERSION=	1.2.7
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Library that provides PHP code coverage information

LICENSE=	BSD

BUILD_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-File_Iterator>=1.3.0:${PORTSDIR}/devel/pear-File_Iterator \
		pear-PHP_TokenStream>=1.1.3:${PORTSDIR}/devel/pear-PHP_TokenStream \
		pear-Text_Template>=1.1.1:${PORTSDIR}/textproc/pear-Text_Template \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit
RUN_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-File_Iterator>=1.3.0:${PORTSDIR}/devel/pear-File_Iterator \
		pear-PHP_TokenStream>=1.1.3:${PORTSDIR}/devel/pear-PHP_TokenStream \
		pear-Text_Template>=1.1.1:${PORTSDIR}/textproc/pear-Text_Template \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit

PEAR_CHANNEL=	phpunit
PEAR_AUTOINSTALL=	yes

OPTIONS_DEFINE=	DOM XDEBUG
DOM_DESC=	Enable DOM support
XDEBUG_DESC=	Enable Xdebug support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOM}
USE_PHP+=	dom
.endif

.if ${PORT_OPTIONS:MXDEBUG}
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/xdebug.so:${PORTSDIR}/devel/php-xdebug
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
