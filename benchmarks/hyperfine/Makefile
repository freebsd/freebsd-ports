PORTNAME=	hyperfine
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0
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

CARGO_CRATES=	aho-corasick-0.7.18 \
		anyhow-1.0.55 \
		approx-0.5.1 \
		arrayvec-0.7.2 \
		assert_cmd-2.0.4 \
		atty-0.2.14 \
		autocfg-0.1.8 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		cfg-if-1.0.0 \
		clap-3.1.5 \
		clap_complete-3.1.1 \
		cloudabi-0.0.3 \
		colored-2.0.0 \
		console-0.15.0 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		encode_unicode-0.3.6 \
		fastrand-1.7.0 \
		float-cmp-0.9.0 \
		fuchsia-cprng-0.1.1 \
		getrandom-0.2.5 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		indexmap-1.8.0 \
		indicatif-0.16.2 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-0.4.8 \
		itoa-1.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.119 \
		memchr-2.4.1 \
		normalize-line-endings-0.3.0 \
		num-0.2.1 \
		num-bigint-0.2.6 \
		num-complex-0.2.4 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.2.4 \
		num-traits-0.2.14 \
		number_prefix-0.4.0 \
		once_cell-1.10.0 \
		os_str_bytes-6.0.0 \
		ppv-lite86-0.2.16 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		proc-macro2-1.0.36 \
		quote-1.0.15 \
		rand-0.6.5 \
		rand-0.8.5 \
		rand_chacha-0.1.1 \
		rand_chacha-0.3.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.6.3 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.2.11 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rust_decimal-1.22.0 \
		ryu-1.0.9 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		shell-words-1.1.0 \
		statistical-1.0.0 \
		strsim-0.10.0 \
		syn-1.0.86 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		terminal_size-0.1.17 \
		termtree-0.2.4 \
		textwrap-0.15.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		unicode-xid-0.2.2 \
		wait-timeout-0.2.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hyperfine

.include <bsd.port.mk>
