PORTNAME=	avro
PORTVERSION=	1.12.0
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	APACHE/avro/avro-${PORTVERSION}/cpp
PKGNAMESUFFIX=	-cpp
DISTNAME=	avro-cpp-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ library for Apache Avro
WWW=		https://avro.apache.org/ \
		https://github.com/apache/avro

BROKEN=		Lots of cmake warnings, does not find snappy, does not link libfmt dynamically

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libsnappy.so:archivers/snappy

USES=		cmake compiler:c++17-lang cpe

USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	apache

post-install:
	${LN} -s libavrocpp.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libavrocpp.so.1

.include <bsd.port.mk>
