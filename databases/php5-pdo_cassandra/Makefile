# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	pdo_cassandra
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	https://github.com/${GITHUB_USER}/php-${PORTNAME}/tarball/${GITREVISION}/
PKGNAMEPREFIX=	php5-
DISTNAME=	${GITHUB_USER}-php-${PORTNAME}-${GITTAG}-14-g${GITREVISION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PDO driver for Apache Cassandra

LICENSE=	AL2

LIB_DEPENDS=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs

GITREVISION=	7debd5b
GITTAG=		0.8-support
GITHUB_USER=	mkoppanen
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${GITHUB_USER}-php-${PORTNAME}-${GITREVISION}

USES=		pkgconfig
USE_PHP_BUILD=	yes
USE_PHP=	pdo
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=52

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/thrift/bsd.thrift.mk"

THRIFT_MAJOR_VER=	${THRIFT_PORTVERSION:R:R}
THRIFT_MINOR_VER=	${THRIFT_PORTVERSION:R:E}
THRIFT_PATCH_VER=	${THRIFT_PORTVERSION:E}

.if ${THRIFT_MAJOR_VER} >= 0 || ${THRIFT_MINOR_VER} >= 9 || ${THRIFT_PATCH_VER} >= 1
LIB_DEPENDS+=	libthrift.so:${PORTSDIR}/devel/thrift-cpp
BUILD_DEPENDS+=	${LOCALBASE}/bin/thrift:${PORTSDIR}/devel/thrift
.else
LIB_DEPENDS+=	libthrift.so:${PORTSDIR}/devel/thrift
.endif

post-configure:
.if ${THRIFT_PORTVERSION} == "0.8.0"
	${REINPLACE_CMD} 's/\([^:]\)apache::thrift/\1 ::apache::thrift/g' ${WRKSRC}/gen-cpp/Cassandra.h
	${REINPLACE_CMD} 's/\([^:]\)apache::thrift/\1 ::apache::thrift/g' ${WRKSRC}/gen-cpp/Cassandra.cpp
.endif

.include <bsd.port.post.mk>
