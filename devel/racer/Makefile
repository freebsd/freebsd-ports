# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	racer
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.16
CATEGORIES=	devel

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Rust code completion helper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	racer-rust

PLIST_FILES=	bin/racer

## https://github.com/alexcrichton/scoped-tls/issues/5
# error[E0554]: #![feature] may not be used on the stable release channel
#   --> cargo-crates/scoped-tls-0.1.2/src/lib.rs:47:34
#    |
# 47 | #![cfg_attr(feature = "nightly", feature(macro_vis_matcher))]
#    |                                  ^^^^^^^^^^^^^^^^^^^^^^^^^^^

# error[E0554]: #![feature] may not be used on the stable release channel
#   --> cargo-crates/scoped-tls-0.1.2/src/lib.rs:48:34
#    |
# 48 | #![cfg_attr(feature = "nightly", feature(allow_internal_unstable))]
#    |                                  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
MAKE_ENV=	RUSTC_BOOTSTRAP=1

CARGO_CRATES=	aho-corasick-0.6.9 \
		ansi_term-0.11.0 \
		arrayvec-0.4.8 \
		atty-0.2.11 \
		bitflags-1.0.4 \
		byteorder-1.2.7 \
		cfg-if-0.1.6 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		derive_more-0.13.0 \
		either-1.5.0 \
		ena-0.9.3 \
		env_logger-0.6.0 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		humantime-1.1.1 \
		itoa-0.4.3 \
		lazy_static-1.2.0 \
		lazycell-1.2.0 \
		libc-0.2.44 \
		lock_api-0.1.5 \
		log-0.4.6 \
		memchr-2.1.1 \
		memoffset-0.2.1 \
		nodrop-0.1.13 \
		num_cpus-1.8.0 \
		owning_ref-0.4.0 \
		parking_lot-0.6.4 \
		parking_lot_core-0.2.14 \
		parking_lot_core-0.3.1 \
		proc-macro2-0.4.24 \
		quick-error-1.2.2 \
		quote-0.6.10 \
		rand-0.4.3 \
		rand-0.5.5 \
		rand-0.6.1 \
		rand_chacha-0.1.0 \
		rand_core-0.2.2 \
		rand_core-0.3.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_pcg-0.1.1 \
		rand_xorshift-0.1.0 \
		redox_syscall-0.1.43 \
		redox_termios-0.1.1 \
		regex-1.0.6 \
		regex-syntax-0.6.3 \
		remove_dir_all-0.5.1 \
		rls-span-0.4.0 \
		rustc-ap-arena-297.0.0 \
		rustc-ap-graphviz-297.0.0 \
		rustc-ap-rustc_cratesio_shim-297.0.0 \
		rustc-ap-rustc_data_structures-297.0.0 \
		rustc-ap-rustc_errors-297.0.0 \
		rustc-ap-rustc_target-297.0.0 \
		rustc-ap-serialize-297.0.0 \
		rustc-ap-syntax-297.0.0 \
		rustc-ap-syntax_pos-297.0.0 \
		rustc-hash-1.0.1 \
		rustc-rayon-0.1.1 \
		rustc-rayon-core-0.1.1 \
		rustc_version-0.2.3 \
		ryu-0.2.7 \
		scoped-tls-0.1.2 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.80 \
		serde_derive-1.0.80 \
		serde_json-1.0.33 \
		smallvec-0.6.6 \
		stable_deref_trait-1.1.1 \
		strsim-0.7.0 \
		syn-0.15.22 \
		tempfile-3.0.5 \
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
		version_check-0.1.5 \
		void-1.0.2 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

.include <bsd.port.mk>
