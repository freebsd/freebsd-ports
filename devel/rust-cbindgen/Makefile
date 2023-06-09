PORTNAME=	cbindgen
DISTVERSION=	0.24.3
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
PKGNAMEPREFIX=	rust-
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Generate C bindings from Rust code
WWW=		https://github.com/eqrion/cbindgen

LICENSE=	MPL20

RUN_DEPENDS=	cargo:lang/${RUST_DEFAULT}

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
