# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	racer
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.22
CATEGORIES=	devel

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Rust code completion helper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	racer-rust

PLIST_FILES=	bin/racer

MAKE_ENV=	RUSTC_BOOTSTRAP=1

CARGO_CRATES=	aho-corasick-0.6.9 \
		ansi_term-0.11.0 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		bitflags-1.0.4 \
		byteorder-1.3.1 \
		cfg-if-0.1.6 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		derive_more-0.13.0 \
		either-1.5.0 \
		ena-0.11.0 \
		env_logger-0.6.0 \
		fuchsia-cprng-0.1.1 \
		humantime-1.2.0 \
		itoa-0.4.3 \
		jobserver-0.1.12 \
		lazy_static-1.2.0 \
		lazycell-1.2.1 \
		libc-0.2.49 \
		lock_api-0.1.5 \
		log-0.4.6 \
		memchr-2.1.3 \
		memoffset-0.2.1 \
		nodrop-0.1.13 \
		num_cpus-1.9.0 \
		owning_ref-0.4.0 \
		parking_lot-0.7.1 \
		parking_lot_core-0.4.0 \
		proc-macro2-0.4.27 \
		quick-error-1.2.2 \
		quote-0.6.11 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.3 \
		rand_os-0.1.2 \
		rand_pcg-0.1.1 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		regex-1.1.0 \
		regex-syntax-0.6.5 \
		remove_dir_all-0.5.1 \
		rls-span-0.5.1 \
		rustc-ap-arena-407.0.0 \
		rustc-ap-graphviz-407.0.0 \
		rustc-ap-rustc_cratesio_shim-407.0.0 \
		rustc-ap-rustc_data_structures-407.0.0 \
		rustc-ap-rustc_errors-407.0.0 \
		rustc-ap-rustc_target-407.0.0 \
		rustc-ap-serialize-407.0.0 \
		rustc-ap-syntax-407.0.0 \
		rustc-ap-syntax_pos-407.0.0 \
		rustc-hash-1.0.1 \
		rustc-rayon-0.1.2 \
		rustc-rayon-core-0.1.2 \
		rustc_version-0.2.3 \
		ryu-0.2.7 \
		scoped-tls-1.0.0 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.87 \
		serde_derive-1.0.87 \
		serde_json-1.0.38 \
		smallvec-0.6.8 \
		stable_deref_trait-1.1.1 \
		strsim-0.7.0 \
		syn-0.15.26 \
		tempfile-3.0.6 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		void-1.0.2 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

.include <bsd.port.mk>
