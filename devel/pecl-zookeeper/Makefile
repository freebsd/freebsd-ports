# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	zookeeper
PORTVERSION=	0.6.2
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP extension for interfacing with Apache ZooKeeper

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzookeeper_mt.so:devel/libzookeeper

IGNORE_WITH_PHP=56
USE_PHP=	session:build
USES=		php:pecl

PORTDATA=	zookeeper-api.php

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/zookeeper-api.php ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
