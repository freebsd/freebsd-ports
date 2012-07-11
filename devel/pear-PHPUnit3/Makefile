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

OPTIONS=	PEAR_IMAGE_GRAPHVIZ "PEAR::Image::GraphViz support" off \
		PEAR_LOG "PEAR::Log support" off \
		JSON "Enable JSON support" off \
		PDO "Enable PDO support" off \
		PDO_SQLITE "Enable PDO_SQLite support" off \
		TOKENIZER "Enable Tokenizer support" off \
		PDO_MYSQL "Enable PDO_MySQL support" off \
		XDEBUG "Enable Xdebug support" off

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

USE_PHP=	dom spl pcre

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_LOG)
RUN_DEPENDS+=	${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log
.endif

.if defined(WITH_PEAR_IMAGE_GRAPHVIZ)
RUN_DEPENDS+=	${PEARDIR}/Image/GraphViz.php:${PORTSDIR}/graphics/pear-Image_GraphViz
.endif

.if defined(WITH_JSON)
USE_PHP+=	json
.endif

.if defined(WITH_PDO)
USE_PHP+=	pdo
.endif

.if defined(WITH_PDO_MYSQL)
USE_PHP+=	pdo_mysql
.endif

.if defined(WITH_PDO_SQLITE)
USE_PHP+=	pdo_sqlite
.endif

.if defined(WITH_TOKENIZER)
USE_PHP+=	tokenizer
.endif

.if defined(WITH_XDEBUG)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/xdebug.so:${PORTSDIR}/devel/php-xdebug
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
