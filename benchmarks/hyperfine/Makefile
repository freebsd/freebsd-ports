# $FreeBSD$

PORTNAME=	hyperfine
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
PORTREVISION=	1
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

CARGO_CRATES=	ansi_term-0.11.0 \
		approx-0.1.1 \
		approx-0.3.2 \
		atty-0.2.13 \
		autocfg-0.1.6 \
		bitflags-1.2.0 \
		bstr-0.2.8 \
		byteorder-1.3.2 \
		cfg-if-0.1.10 \
		cgmath-0.16.1 \
		clap-2.33.0 \
		clicolors-control-1.0.1 \
		cloudabi-0.0.3 \
		colored-1.8.0 \
		console-0.9.0 \
		csv-1.1.1 \
		csv-core-0.1.6 \
		encode_unicode-0.3.6 \
		fuchsia-cprng-0.1.1 \
		indicatif-0.12.0 \
		itoa-0.4.4 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.62 \
		memchr-2.2.1 \
		num-0.2.0 \
		num-bigint-0.2.3 \
		num-complex-0.2.3 \
		num-integer-0.1.41 \
		num-iter-0.1.39 \
		num-rational-0.2.2 \
		num-traits-0.1.43 \
		num-traits-0.2.8 \
		number_prefix-0.3.0 \
		proc-macro2-1.0.5 \
		quote-1.0.2 \
		rand-0.4.6 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		regex-1.3.1 \
		regex-automata-0.1.8 \
		regex-syntax-0.6.12 \
		rgb-0.8.14 \
		rust_decimal-1.0.3 \
		ryu-1.0.1 \
		serde-1.0.101 \
		serde_derive-1.0.101 \
		serde_json-1.0.41 \
		statistical-1.0.0 \
		strsim-0.8.0 \
		syn-1.0.5 \
		term_size-0.3.1 \
		termios-0.3.1 \
		textwrap-0.11.0 \
		unicode-width-0.1.6 \
		unicode-xid-0.2.0 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winconsole-0.10.0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hyperfine

.include <bsd.port.mk>
