# Created by: gahr
# $FreeBSD$

PORTNAME=	cassandra-cpp-driver
PORTVERSION=	1.0.2
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	DataStax C/C++ Driver for Apache Cassandra

LICENSE=	APACHE20

LIB_DEPENDS=	libuv.so:${PORTSDIR}/devel/libuv

USE_GITHUB=	nodefault
GH_ACCOUNT=	datastax
GH_PROJECT=	cpp-driver

USES=		cmake:outsource
CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING=lib

USE_LDCONFIG=	yes
USE_OPENSSL=	yes

PLIST_FILES=	include/cassandra.h \
		lib/libcassandra.so \
		lib/libcassandra.so.1 \
		lib/libcassandra.so.1.0.2

.include <bsd.port.mk>
