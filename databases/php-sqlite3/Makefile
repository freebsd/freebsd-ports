# New ports collection makefile for:	php-sqlite3
# Date created:			26 Sep 2006
# Whom:				Simon Cornelius P. Umacob <simoncpu@infoweapons.com>
#
# $FreeBSD$
#

PORTNAME=		sqlite3
PORTVERSION=		0.4
CATEGORIES=		databases
MASTER_SITES=		SF/php-${PORTNAME}/source%20code/release%20${PORTVERSION}
PKGNAMEPREFIX=		php-
EXTRACT_SUFX=		.tgz
#DISTFILES=		sqlite3-0.4.tgz

MAINTAINER=		simoncpu@infoweapons.com
COMMENT=		A port for the PHP sqlite3 extension

BUILD_DEPENDS=		sqlite3>=3.0:${PORTSDIR}/databases/sqlite3

CONFIGURE_ARGS=		--with-sqlite3=${LOCALBASE}
USE_PHP=		yes
USE_PHPIZE=		yes
USE_PHPEXT=		yes
USE_PHP_BUILD=		yes

.include <bsd.port.mk>
