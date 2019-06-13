# $FreeBSD$

PORTNAME=	hyperfine
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
PORTREVISION=	0
CATEGORIES=	benchmarks

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Command-line benchmarking tool

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BROKEN_i386=	LLVM ERROR: No support for lowering a copy into EFLAGS when used by this instruction

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

PLIST_FILES=	bin/hyperfine

CARGO_CRATES=	aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		approx-0.1.1 \
		approx-0.3.2 \
		atty-0.2.11 \
		autocfg-0.1.4 \
		bitflags-1.1.0 \
		cfg-if-0.1.9 \
		cgmath-0.16.1 \
		clap-2.33.0 \
		clicolors-control-1.0.0 \
		cloudabi-0.0.3 \
		colored-1.8.0 \
		console-0.7.5 \
		csv-1.0.7 \
		csv-core-0.1.5 \
		encode_unicode-0.3.5 \
		fuchsia-cprng-0.1.1 \
		indicatif-0.11.0 \
		itoa-0.4.4 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		libc-0.2.58 \
		lock_api-0.2.0 \
		memchr-2.2.0 \
		num-0.2.0 \
		num-bigint-0.2.2 \
		num-complex-0.2.1 \
		num-integer-0.1.41 \
		num-iter-0.1.39 \
		num-rational-0.2.1 \
		num-traits-0.1.43 \
		num-traits-0.2.8 \
		number_prefix-0.2.8 \
		numtoa-0.1.0 \
		parking_lot-0.8.0 \
		parking_lot_core-0.5.0 \
		proc-macro2-0.4.30 \
		quote-0.6.12 \
		rand-0.4.6 \
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
		regex-1.1.6 \
		regex-syntax-0.6.6 \
		rgb-0.8.13 \
		rustc_version-0.2.3 \
		ryu-0.2.8 \
		scopeguard-1.0.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.92 \
		serde_derive-1.0.92 \
		serde_json-1.0.39 \
		smallvec-0.6.9 \
		statistical-1.0.0 \
		strsim-0.8.0 \
		syn-0.15.34 \
		term_size-0.3.1 \
		termion-1.5.2 \
		termios-0.3.1 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winconsole-0.10.0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hyperfine

.include <bsd.port.mk>
