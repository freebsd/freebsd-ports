# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>

PORTNAME=	avro
PORTVERSION=	1.10.2
DISTVERSIONPREFIX=	release-
CATEGORIES=	devel
PKGNAMESUFFIX=	-cpp

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ library for Apache Avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libsnappy.so:archivers/snappy

USES=		cmake compiler:c++11-lang

USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	lang/c++

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	apache
USE_GITHUB=	yes

post-install:
	${LN} -s libavrocpp.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libavrocpp.so.1

.include <bsd.port.mk>
