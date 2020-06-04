# $FreeBSD$

PORTNAME=	cbindgen
DISTVERSION=	0.14.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
PKGNAMEPREFIX=	rust-
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Generate C bindings from Rust code

LICENSE=	MPL20

RUN_DEPENDS=	cargo:lang/${RUST_DEFAULT}

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.13 \
		bitflags-1.2.1 \
		c2-chacha-0.2.3 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		getrandom-0.1.13 \
		heck-0.3.1 \
		itoa-0.4.4 \
		libc-0.2.66 \
		log-0.4.8 \
		ppv-lite86-0.2.6 \
		proc-macro2-1.0.6 \
		quote-1.0.2 \
		rand-0.7.2 \
		rand_chacha-0.2.1 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		remove_dir_all-0.5.2 \
		ryu-1.0.2 \
		serde-1.0.104 \
		serde_derive-1.0.104 \
		serde_json-1.0.44 \
		strsim-0.8.0 \
		syn-1.0.11 \
		tempfile-3.1.0 \
		textwrap-0.11.0 \
		toml-0.5.5 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		wasi-0.7.0 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

.include <bsd.port.mk>
