PORTNAME=	brotli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTEPOCH=	1
CATEGORIES=	archivers devel

PATCH_SITES=	https://github.com/google/${PORTNAME}/commit/
PATCHFILES=	741610efd335a8b6ff9be4c9bed643e0a74fdb6a.patch:-p1

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm
WWW=		https://github.com/google/brotli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing cpe pkgconfig
CPE_VENDOR=	google
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

PLIST_SUB=	SHLIBVER=${DISTVERSION:R}

CMAKE_OFF=	BUILD_TESTING
CMAKE_ARGS=	-DSHARE_INSTALL_PREFIX=share

OPTIONS_DEFINE=		STATIC
OPTIONS_SUB=		yes

STATIC_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-static-libs

.include <bsd.port.mk>
