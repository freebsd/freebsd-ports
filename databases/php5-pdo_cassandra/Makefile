# New ports collection makefile for:	php5-pdo_cassandra
# Date created:		2011-08-03
# Whom:			Gasol Wu <gasol.wu@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pdo_cassandra
PORTVERSION=	0.2.1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/${GITHUB_USER}/php-${PORTNAME}/tarball/${GITREVISION}/
PKGNAMEPREFIX=	php5-
DISTNAME=	${GITHUB_USER}-php-${PORTNAME}-${GITTAG}-14-g${GITREVISION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PDO driver for Apache Cassandra

LIB_DEPENDS=	boost_iostreams:${PORTSDIR}/devel/boost-libs \
		thrift:${PORTSDIR}/devel/thrift

GITREVISION=	7debd5b
GITTAG=		0.8-support
GITHUB_USER=	mkoppanen
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${GITHUB_USER}-php-${PORTNAME}-${GITREVISION}

USE_PHP_BUILD=	yes
USE_PHP=	pdo
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4 52

.include <bsd.port.mk>
