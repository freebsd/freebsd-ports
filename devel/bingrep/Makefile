# $FreeBSD$

PORTNAME=	bingrep
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Grep through binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

CARGO_CRATES=	aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-0.1.7 \
		backtrace-0.3.42 \
		backtrace-sys-0.1.32 \
		base64-0.11.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		bstr-0.2.10 \
		byteorder-1.3.2 \
		cc-1.0.50 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		constant_time_eq-0.1.5 \
		cpp_demangle-0.2.14 \
		crossbeam-utils-0.7.0 \
		csv-1.1.3 \
		csv-core-0.1.6 \
		dirs-1.0.5 \
		encode_unicode-0.3.6 \
		env_logger-0.7.1 \
		failure-0.1.6 \
		failure_derive-0.1.6 \
		fuchsia-cprng-0.1.1 \
		getrandom-0.1.14 \
		glob-0.3.0 \
		goblin-0.2.0 \
		heck-0.3.1 \
		hermit-abi-0.1.6 \
		hexplay-0.2.1 \
		humantime-1.3.0 \
		itoa-0.4.5 \
		lazy_static-1.4.0 \
		libc-0.2.66 \
		log-0.4.8 \
		memchr-2.3.0 \
		memrange-0.1.3 \
		metagoblin-0.3.1 \
		plain-0.2.3 \
		prettytable-rs-0.8.0 \
		proc-macro-error-0.2.6 \
		proc-macro-error-0.4.5 \
		proc-macro-error-attr-0.4.5 \
		proc-macro2-1.0.8 \
		quick-error-1.2.3 \
		quote-1.0.2 \
		rand-0.3.23 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.4 \
		regex-1.3.3 \
		regex-automata-0.1.8 \
		regex-syntax-0.6.13 \
		rust-argon2-0.7.0 \
		rustc-demangle-0.1.16 \
		rustc-serialize-0.3.24 \
		rustversion-1.0.2 \
		ryu-1.0.2 \
		scroll-0.10.1 \
		scroll_derive-0.10.1 \
		serde-1.0.104 \
		strsim-0.8.0 \
		structopt-0.3.8 \
		structopt-derive-0.3.5 \
		structopt-derive-0.4.1 \
		syn-1.0.14 \
		syn-mid-0.4.0 \
		synstructure-0.12.3 \
		term-0.5.2 \
		termcolor-0.3.6 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		theban_interval_tree-0.7.1 \
		thread_local-1.0.1 \
		time-0.1.42 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.3 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-0.1.6

PLIST_FILES=	bin/bingrep

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bingrep

.include <bsd.port.mk>
