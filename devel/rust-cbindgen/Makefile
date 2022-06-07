PORTNAME=	cbindgen
DISTVERSION=	0.24.3
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
PKGNAMEPREFIX=	rust-
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Generate C bindings from Rust code

LICENSE=	MPL20

RUN_DEPENDS=	cargo:lang/${RUST_DEFAULT}

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		clap-3.1.6 \
		fastrand-1.7.0 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.8.0 \
		instant-0.1.12 \
		itoa-1.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.121 \
		lock_api-0.4.6 \
		log-0.4.16 \
		memchr-2.4.1 \
		os_str_bytes-6.0.0 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		proc-macro2-1.0.36 \
		quote-1.0.17 \
		redox_syscall-0.2.12 \
		remove_dir_all-0.5.3 \
		ryu-1.0.9 \
		scopeguard-1.1.0 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		serial_test-0.5.1 \
		serial_test_derive-0.5.1 \
		smallvec-1.8.0 \
		strsim-0.10.0 \
		syn-1.0.89 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		textwrap-0.15.0 \
		toml-0.5.8 \
		unicode-xid-0.2.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

.include <bsd.port.mk>
