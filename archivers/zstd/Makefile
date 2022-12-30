PORTNAME=	zstd
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/facebook/zstd/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast real-time compression algorithm
WWW=		https://facebook.github.io/zstd/ \
		https://github.com/facebook/zstd

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblz4.so:archivers/liblz4

USES=		gmake localbase:ldflags tar:zst

ALL_TARGET=	default
BINARY_ALIAS=	gmd5sum=md5sum
TEST_TARGET=	test
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_VARS=	CFLAGS+=-O3

post-build:
	cd ${WRKSRC}/programs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} zstd-frugal

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/programs/zstd-frugal ${STAGEDIR}${PREFIX}/bin/zstd-frugal
	${LN} -s zstd.1.gz ${STAGEDIR}${PREFIX}/man/man1/zstdmt.1.gz

.include <bsd.port.mk>
