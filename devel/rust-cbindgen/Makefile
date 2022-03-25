PORTNAME=	cbindgen
DISTVERSION=	0.21.0
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
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		cfg-if-0.1.10 \
		clap-3.1.6 \
		cloudabi-0.0.3 \
		getrandom-0.1.15 \
		hashbrown-0.9.1 \
		heck-0.4.0 \
		hermit-abi-0.1.16 \
		indexmap-1.6.0 \
		itoa-0.4.6 \
		lazy_static-1.4.0 \
		libc-0.2.77 \
		lock_api-0.3.4 \
		log-0.4.11 \
		memchr-2.4.1 \
		os_str_bytes-6.0.0 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		ppv-lite86-0.2.9 \
		proc-macro2-1.0.21 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		remove_dir_all-0.5.3 \
		ryu-1.0.5 \
		scopeguard-1.1.0 \
		serde-1.0.116 \
		serde_derive-1.0.116 \
		serde_json-1.0.57 \
		serial_test-0.5.0 \
		serial_test_derive-0.5.0 \
		smallvec-1.4.2 \
		strsim-0.10.0 \
		syn-1.0.41 \
		tempfile-3.1.0 \
		termcolor-1.1.3 \
		textwrap-0.15.0 \
		toml-0.5.6 \
		unicode-xid-0.2.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

.include <bsd.port.mk>
