# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	pdo_cassandra
PORTVERSION=	0.2.1
PORTREVISION=	4
CATEGORIES=	databases
PKGNAMEPREFIX=	php5-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PDO driver for Apache Cassandra

LICENSE=	APACHE20

BROKEN=		fails to compile

LIB_DEPENDS=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	mkoppanen
GH_PROJECT=	php-${PORTNAME}
GH_TAGNAME=	7debd5b

USES=		pkgconfig
USE_PHP_BUILD=	yes
USE_PHP=	pdo
USE_PHPEXT=	yes
PHP_DEFAULT=	5.4
IGNORE_WITH_PHP=52
USE_GCC=	yes

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
