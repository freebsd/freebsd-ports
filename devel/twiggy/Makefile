PORTNAME=	twiggy
DISTVERSION=	0.6.0
PORTREVISION=	23
CATEGORIES=	devel www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code size profiler for Wasm
WWW=		https://rustwasm.github.io/twiggy/ \
		https://github.com/rustwasm/twiggy

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/../LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/../LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	rustwasm

WRKSRC_SUBDIR=	${PORTNAME}

CARGO_CRATES=	aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		approx-0.1.1 \
		arrayvec-0.4.7 \
		atty-0.2.11 \
		backtrace-0.3.9 \
		backtrace-sys-0.1.24 \
		bitflags-1.0.4 \
		bumpalo-2.1.0 \
		byteorder-1.2.6 \
		cc-1.0.24 \
		cfg-if-0.1.9 \
		cgmath-0.16.1 \
		clap-2.32.0 \
		colored-1.8.0 \
		cpp_demangle-0.2.12 \
		csv-1.0.7 \
		csv-core-0.1.4 \
		diff-0.1.11 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fallible-iterator-0.2.0 \
		fixedbitset-0.1.9 \
		flate2-1.0.2 \
		frozen-1.0.0 \
		fuchsia-cprng-0.1.1 \
		gimli-0.18.0 \
		glob-0.2.11 \
		goblin-0.0.22 \
		heck-0.3.0 \
		itoa-0.4.4 \
		lazy_static-1.2.0 \
		libc-0.2.49 \
		log-0.4.5 \
		memchr-2.2.0 \
		miniz-sys-0.1.10 \
		nodrop-0.1.12 \
		num-traits-0.1.43 \
		num-traits-0.2.6 \
		object-0.12.0 \
		ordermap-0.3.5 \
		parity-wasm-0.38.0 \
		petgraph-0.4.13 \
		plain-0.2.3 \
		proc-macro2-0.4.18 \
		quote-0.6.8 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rdrand-0.4.0 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-1.1.7 \
		regex-syntax-0.6.6 \
		rgb-0.8.13 \
		rustc-demangle-0.1.15 \
		ryu-0.2.8 \
		scroll-0.9.0 \
		scroll_derive-0.9.4 \
		serde-1.0.93 \
		serde_derive-1.0.93 \
		stable_deref_trait-1.1.1 \
		strsim-0.7.0 \
		structopt-0.2.18 \
		structopt-derive-0.2.18 \
		syn-0.14.9 \
		syn-0.15.22 \
		synstructure-0.10.1 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		typed-arena-1.4.1 \
		ucd-util-0.1.1 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.1 \
		uuid-0.7.1 \
		vec_map-0.8.1 \
		wasm-bindgen-0.2.40 \
		wasm-bindgen-backend-0.2.40 \
		wasm-bindgen-macro-0.2.40 \
		wasm-bindgen-macro-support-0.2.40 \
		wasm-bindgen-shared-0.2.40 \
		wasmparser-0.31.1 \
		winapi-0.3.5 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winconsole-0.10.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
