# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.8.2
DISTVERSIONPREFIX=	release-
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	-c

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for Apache Avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	fails to build: error: No atomic implementation
BROKEN_armv6=	fails to build: error: No atomic implementation
BROKEN_armv7=	fails to build: error: No atomic implementation
BROKEN_mips=	fails to build: error: No atomic implementation
BROKEN_mips64=	fails to build: error: No atomic implementation
BROKEN_sparc64=	fails to build

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libsnappy.so:archivers/snappy

USES=		cmake pkgconfig
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	lang/c

GH_ACCOUNT=	apache
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} '/SNAPPY_PKG/ s|libsnappy|snappy|; /add_subdirectory(docs)/d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} '1 s|/bin/bash|/bin/sh|' ${WRKSRC}/version.sh
	@${REINPLACE_CMD} 's|lib/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
