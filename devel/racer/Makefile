# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	racer
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.5
PORTREVISION=	1
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

CARGO_CRATES=	aho-corasick-0.6.6 \
		ansi_term-0.11.0 \
		arrayvec-0.4.7 \
		atty-0.2.10 \
		bitflags-1.0.3 \
		byteorder-1.2.3 \
		cfg-if-0.1.4 \
		clap-2.32.0 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		derive_more-0.11.0 \
		dtoa-0.4.3 \
		either-1.5.0 \
		ena-0.9.3 \
		env_logger-0.5.10 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		humantime-1.1.1 \
		itoa-0.4.2 \
		lazy_static-1.0.1 \
		lazycell-1.0.0 \
		libc-0.2.42 \
		log-0.4.3 \
		memchr-2.0.1 \
		memoffset-0.2.1 \
		nodrop-0.1.12 \
		num_cpus-1.8.0 \
		owning_ref-0.3.3 \
		parking_lot-0.5.5 \
		parking_lot_core-0.2.14 \
		proc-macro2-0.3.8 \
		proc-macro2-0.4.6 \
		quick-error-1.2.2 \
		quote-0.5.2 \
		quote-0.6.3 \
		rand-0.4.2 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-1.0.1 \
		regex-syntax-0.6.1 \
		remove_dir_all-0.5.1 \
		rls-span-0.4.0 \
		rustc-ap-arena-237.0.0 \
		rustc-ap-rustc_cratesio_shim-237.0.0 \
		rustc-ap-rustc_data_structures-237.0.0 \
		rustc-ap-rustc_errors-237.0.0 \
		rustc-ap-rustc_target-237.0.0 \
		rustc-ap-serialize-237.0.0 \
		rustc-ap-syntax-237.0.0 \
		rustc-ap-syntax_pos-237.0.0 \
		rustc-hash-1.0.1 \
		rustc-rayon-0.1.1 \
		rustc-rayon-core-0.1.1 \
		rustc_version-0.2.2 \
		scoped-tls-0.1.2 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.70 \
		serde_derive-1.0.70 \
		serde_json-1.0.22 \
		smallvec-0.6.5 \
		stable_deref_trait-1.1.0 \
		strsim-0.7.0 \
		syn-0.13.11 \
		syn-0.14.4 \
		tempfile-3.0.2 \
		termcolor-0.3.6 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.5 \
		ucd-util-0.1.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.1 \
		void-1.0.2 \
		winapi-0.3.5 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-0.1.6

.include <bsd.port.mk>
