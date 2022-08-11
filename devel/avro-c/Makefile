PORTNAME=	avro
PORTVERSION=	1.11.0
CATEGORIES=	devel
MASTER_SITES=	APACHE/avro/stable/c
PKGNAMESUFFIX=	-c
DISTNAME=	avro-c-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for Apache Avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	fails to build

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libsnappy.so:archivers/snappy

USES=		cmake compiler:c++11-lang cpe pathfix pkgconfig

USE_LDCONFIG=	yes

CPE_VENDOR=	apache

post-patch:
	@${REINPLACE_CMD} '/SNAPPY_PKG/ s|libsnappy|snappy|; /add_subdirectory(docs)/d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} '1 s|/bin/bash|/bin/sh|' ${WRKSRC}/version.sh

.include <bsd.port.mk>
