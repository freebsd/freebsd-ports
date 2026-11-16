PORTNAME=	brotli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	archivers devel
MASTER_SITES+=	https://github.com/google/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
DISTFILES+=	testdata.txz
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

PATCH_SITES=	https://github.com/google/brotli/commit/
PATCHFILES=	e230f474b87134e8c6c85b630084c612057f253e.patch:-p1

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm
WWW=		https://github.com/google/brotli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake cpe pathfix
CPE_VENDOR=	google
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

PLIST_SUB=	SHLIBVER=${DISTVERSION:R}

TEST_TARGET=	test

CMAKE_ARGS=	-DSHARE_INSTALL_PREFIX=share

OPTIONS_DEFINE=		STATIC
OPTIONS_SUB=		yes

STATIC_CMAKE_BOOL=	BROTLI_BUILD_FOR_PACKAGE

post-extract:
	${MV} ${WRKDIR}/tests/testdata/* ${WRKSRC}/tests/testdata/

.include <bsd.port.mk>
