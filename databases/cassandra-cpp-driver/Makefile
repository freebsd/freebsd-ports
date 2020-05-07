# Created by: gahr
# $FreeBSD$

PORTNAME=	cassandra-cpp-driver
PORTVERSION=	2.15.1
PORTREVISION=	0
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	DataStax C/C++ Driver for Apache Cassandra

LICENSE=	APACHE20

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		cmake compiler:c++11-lang pkgconfig pathfix ssl
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	datastax
GH_PROJECT=	cpp-driver

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING=lib \
		-DCASS_BUILD_STATIC:BOOL=ON

PLIST_FILES=	include/cassandra.h \
		include/dse.h \
		lib/libcassandra.so \
		lib/libcassandra.so.2 \
		lib/libcassandra.so.${PORTVERSION} \
		lib/libcassandra_static.a \
		libdata/pkgconfig/cassandra.pc \
		libdata/pkgconfig/cassandra_static.pc

post-patch:
	${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
