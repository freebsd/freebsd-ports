PORTNAME=	wasm-server-runner
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Cargo runner for WASM
WWW=		https://github.com/jakobhellermann/wasm-server-runner/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS+=	libzstd.so:archivers/zstd

USES=		cargo llvm
USE_GITHUB=	yes
GH_ACCOUNT=	jakobhellermann

PLIST_FILES=	bin/wasm-server-runner

.include <bsd.port.mk>
