PORTNAME=	horde_lz4
PORTVERSION=	1.0.10
PORTREVISION=	1
CATEGORIES=	archivers pear
MASTER_SITES=	http://pear.horde.org/get/
PKGNAMEPREFIX=	${PECL_PKGNAMEPREFIX}
DIST_SUBDIR=	PECL

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Horde LZ4 Compression Extension for php

LICENSE=	MIT

USES=		cpe php:ext tar:tgz

CPE_VENDOR=	horde

OPTIONS_DEFINE=	LZ4
OPTIONS_DEFAULT=LZ4

LZ4_DESC=	Use archivers/liblz4 instead of bundled lz4
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_WITH=	liblz4
LZ4_USES=	pkgconfig

CONFIGURE_ARGS=	--enable-horde_lz4

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/horde_lz4.so

.include <bsd.port.mk>
