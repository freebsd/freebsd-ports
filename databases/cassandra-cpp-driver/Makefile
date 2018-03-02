# Created by: gahr
# $FreeBSD$

PORTNAME=	cassandra-cpp-driver
PORTVERSION=	2.8.1
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	DataStax C/C++ Driver for Apache Cassandra

LICENSE=	APACHE20

LIB_DEPENDS=	libuv.so:devel/libuv

BROKEN_powerpc64=	fails to compile: reader.h: warning: comparison is always true due to limited range of data type

USE_GITHUB=	yes
GH_ACCOUNT=	datastax
GH_PROJECT=	cpp-driver

USES=		cmake:outsource pkgconfig pathfix ssl
CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING=lib \
		-DCASS_BUILD_STATIC:BOOL=ON

USE_LDCONFIG=	yes

PLIST_FILES=	include/cassandra.h \
		lib/libcassandra.so \
		lib/libcassandra.so.2 \
		lib/libcassandra.so.${PORTVERSION} \
		lib/libcassandra_static.a \
		libdata/pkgconfig/cassandra.pc \
		libdata/pkgconfig/cassandra_static.pc

.include <bsd.port.mk>
