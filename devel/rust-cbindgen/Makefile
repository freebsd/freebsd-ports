# $FreeBSD$

PORTNAME=	cbindgen
DISTVERSION=	0.8.6
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
		atty-0.2.11 \
		autocfg-0.1.2 \
		bitflags-1.0.4 \
		cfg-if-0.1.7 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		fuchsia-cprng-0.1.1 \
		itoa-0.4.4 \
		libc-0.2.54 \
		log-0.4.6 \
		numtoa-0.1.0 \
		proc-macro2-0.4.30 \
		quote-0.6.12 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		remove_dir_all-0.5.1 \
		ryu-0.2.8 \
		serde-1.0.91 \
		serde_derive-1.0.91 \
		serde_json-1.0.39 \
		strsim-0.8.0 \
		syn-0.15.34 \
		tempfile-3.0.7 \
		termion-1.5.2 \
		textwrap-0.11.0 \
		toml-0.4.10 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		vec_map-0.8.1 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

.include <bsd.port.mk>
