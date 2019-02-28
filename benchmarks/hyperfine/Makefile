# $FreeBSD$

PORTNAME=	hyperfine
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	2
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

CARGO_CRATES=	aho-corasick-0.6.9 \
		ansi_term-0.11.0 \
		approx-0.3.0 \
		atty-0.2.11 \
		bitflags-1.0.4 \
		cfg-if-0.1.6 \
		clap-2.32.0 \
		clicolors-control-0.2.0 \
		cloudabi-0.0.3 \
		colored-1.6.1 \
		console-0.6.2 \
		csv-1.0.2 \
		csv-core-0.1.4 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		indicatif-0.9.0 \
		itoa-0.4.3 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.2.0 \
		libc-0.2.49 \
		lock_api-0.1.5 \
		memchr-2.1.1 \
		num-0.1.42 \
		num-bigint-0.1.44 \
		num-complex-0.1.43 \
		num-integer-0.1.39 \
		num-iter-0.1.37 \
		num-rational-0.1.42 \
		num-traits-0.2.6 \
		owning_ref-0.4.0 \
		parking_lot-0.6.4 \
		parking_lot_core-0.3.1 \
		proc-macro2-0.4.24 \
		quote-0.6.10 \
		rand-0.3.22 \
		rand-0.4.3 \
		rand-0.5.5 \
		rand_core-0.2.2 \
		rand_core-0.3.0 \
		redox_syscall-0.1.42 \
		redox_termios-0.1.1 \
		regex-0.2.11 \
		regex-1.0.6 \
		regex-syntax-0.5.6 \
		regex-syntax-0.6.3 \
		rustc-serialize-0.3.24 \
		rustc_version-0.2.3 \
		ryu-0.2.7 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.82 \
		serde_derive-1.0.82 \
		serde_json-1.0.33 \
		smallvec-0.6.6 \
		stable_deref_trait-1.1.1 \
		statistical-0.1.1 \
		strsim-0.7.0 \
		syn-0.15.22 \
		term_size-0.3.1 \
		termion-1.5.1 \
		termios-0.3.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.2 \
		version_check-0.1.5 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hyperfine

.include <bsd.port.mk>
