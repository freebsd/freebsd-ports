PORTNAME=	cargo-pgrx
PORTVERSION=	0.16.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	arcade@b1t.name
COMMENT=	Framework for developing PostgreSQL extensions in Rust

LICENSE=	MIT

LIB_DEPENDS+=	libzstd.so:archivers/zstd

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	pgcentralfoundation
GH_PROJECT=	pgrx

CARGO_BUILD_ARGS=	-p cargo-pgrx
CARGO_INSTALL_PATH=	cargo-pgrx

# this disables openssl-sys, though I'm not yet fully sure about impact
CARGO_FEATURES=	--no-default-features ureq/platform-verifier ureq/rustls

PLIST_FILES=	bin/${PORTNAME}
NO_MANCOMPRESS=

.include <bsd.port.mk>
