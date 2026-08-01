PORTNAME=	mimalloc
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/microsoft/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}-source

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	General-purpose allocator with excellent performance characteristics
WWW=		https://github.com/microsoft/mimalloc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang pathfix
USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS=	--strip-components 1 --no-same-permission --no-same-owner
NO_WRKSUBDIR=	yes

CMAKE_ON=	MI_INSTALL_TOPLEVEL
CMAKE_OFF=	MI_BUILD_OBJECT MI_BUILD_TESTS

CMAKE_TESTING_ON=	MI_BUILD_TESTS

# ci pipeline creates transient tags
PORTSCOUT=	ignore:1

PLIST_SUB=	MIMALLOC_LIBVER=${DISTVERSION:R}

.include <bsd.port.mk>
