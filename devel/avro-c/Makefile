# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.9.2
DISTVERSIONPREFIX=	release-
CATEGORIES=	devel
PKGNAMESUFFIX=	-c

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for Apache Avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	fails to build

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libsnappy.so:archivers/snappy

USES=		cmake compiler:c++11-lang pathfix pkgconfig

USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	lang/c

GH_ACCOUNT=	apache
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} '/SNAPPY_PKG/ s|libsnappy|snappy|; /add_subdirectory(docs)/d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} '1 s|/bin/bash|/bin/sh|' ${WRKSRC}/version.sh

.include <bsd.port.mk>
