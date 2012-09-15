# Ports collection makefile for:  pear-PHPUnit3
# Date created:			  17 May 2007
# Whom:				  Gerrit Beine (<gerrit.beine@gmx.de>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit
PORTVERSION=	3.4.15
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.phpunit.de/get/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR regression testing framework for unit tests

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit \
		${PEARDIR}/Benchmark/Timer.php:${PORTSDIR}/benchmarks/pear-Benchmark
CONFLICTS=	pear-PHPUnit-[12]*

PEAR_CHANNEL=	phpunit
PEAR_AUTOINSTALL=	yes

LATEST_LINK=	pear-PHPUnit3

OPTIONS_DEFINE=	PEAR_IMAGE_GRAPHVIZ PEAR_LOG JSON PDO PDO_SQLITE TOKENIZER PDO_MYSQL XDEBUG
PEAR_IMAGE_GRAPHVIZ_DESC=	PEAR::Image::GraphViz support
PEAR_LOG_DESC=	PEAR::Log support
JSON_DESC=	Enable JSON support
PDO_DESC=	Enable PDO support
PDO_SQLITE_DESC=	Enable PDO_SQLite support
TOKENIZER_DESC=	Enable Tokenizer support
PDO_MYSQL_DESC=	Enable PDO_MySQL support
XDEBUG_DESC=	Enable Xdebug support

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

USE_PHP=	dom spl pcre

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPEAR_LOG}
RUN_DEPENDS+=	${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log
.endif
   
.if ${PORT_OPTIONS:MIMAGE_GRAPHVIZ}
RUN_DEPENDS+=	${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS+=	${PEARDIR}/Image/GraphViz.php:${PORTSDIR}/graphics/pear-Image_GraphViz
.endif

.if ${PORT_OPTIONS:MJSON}
USE_PHP+=	json
.endif

.if ${PORT_OPTIONS:MPDO}
USE_PHP+=	pdo
.endif

.if ${PORT_OPTIONS:MPDO_MYSQL}
USE_PHP+=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MPDO_SQLITE}
USE_PHP+=	pdo_sqlite
.endif

.if ${PORT_OPTIONS:MTOKENIZER}
USE_PHP+=	tokenizer
.endif

.if ${PORT_OPTIONS:MXDEBUG}
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/xdebug.so:${PORTSDIR}/devel/php-xdebug
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
