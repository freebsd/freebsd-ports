PORTNAME=	tkrzw
DISTVERSION=	1.0.32
CATEGORIES=	databases
MASTER_SITES=	https://dbmx.net/${PORTNAME}/pkg/

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Set of implementations of DBM, successor of Kyoto Cabinet
WWW=		https://dbmx.net/tkrzw/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-lzma --enable-zlib

SHLIB_VER=		1.75.0
SHLIB_VER_MAJOR=	1
PLIST_SUB+=		SHLIB_VER=${SHLIB_VER} \
			SHLIB_VER_MAJOR=${SHLIB_VER_MAJOR}

OPTIONS_DEFINE=		CPU_OPTS LZ4 ZSTD
OPTIONS_DEFAULT=	LZ4 ZSTD

CPU_OPTS_DESC=		Use CPU-specific optimizations
CPU_OPTS_CONFIGURE_ON=	--enable-opt-native

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_ON=	--enable-lz4

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_CONFIGURE_ON=	--enable-zstd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tkrzw*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtkrzw*

.include <bsd.port.mk>
