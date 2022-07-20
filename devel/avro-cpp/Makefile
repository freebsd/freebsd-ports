PORTNAME=	avro
PORTVERSION=	1.11.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/avro/stable/cpp
PKGNAMESUFFIX=	-cpp
DISTNAME=	avro-cpp-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ library for Apache Avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libsnappy.so:archivers/snappy

USES=		cmake compiler:c++11-lang cpe

USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	apache

post-install:
	${LN} -s libavrocpp.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libavrocpp.so.1

.include <bsd.port.mk>
