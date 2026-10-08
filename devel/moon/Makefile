PORTNAME=	moon
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	devel

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Repository management, organization and task orchestration tool
WWW=		https://moonrepo.dev/ \
		https://github.com/moonrepo/moon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo llvm ssl
USE_GITHUB=	yes
GH_ACCOUNT=	moonrepo

CARGO_INSTALL_PATH=	crates/cli

# cc>=1.6 defeats aws-lc-sys -O0 jitter guard: aws/aws-lc-rs#1252
MAKE_ENV+=	AWS_LC_SYS_NO_JITTER_ENTROPY=1 \
		LIBCLANG_PATH=${LLVM_PREFIX}/lib \
		OPENSSL_NO_VENDOR=1

PLIST_FILES=	bin/moon \
		bin/moonx

.include <bsd.port.mk>
