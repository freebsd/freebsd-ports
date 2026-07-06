PORTNAME=	moon
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.1
CATEGORIES=	devel

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Repository management, organization and task orchestration tool
WWW=		https://moonrepo.dev/ \
		https://github.com/moonrepo/moon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo llvm ssl
USE_GITHUB=	yes
GH_ACCOUNT=	moonrepo

BUILD_DEPENDS=	protoc:devel/protobuf

CARGO_INSTALL_PATH=	crates/cli

MAKE_ENV+=	LIBCLANG_PATH=${LLVM_PREFIX}/lib \
		OPENSSL_NO_VENDOR=1

PLIST_FILES=	bin/moon \
		bin/moonx

.include <bsd.port.mk>
