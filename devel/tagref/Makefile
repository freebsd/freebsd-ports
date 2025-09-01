PORTNAME=	tagref
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
PORTREVISION=	13
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tagref helps you maintain cross-references in your code
WWW=		https://github.com/stepchowfun/tagref

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	stepchowfun

CARGO_CRATES=	aho-corasick-1.1.2 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		bitflags-1.3.2 \
		bstr-1.9.0 \
		clap-2.34.0 \
		colored-1.9.4 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.19 \
		globset-0.4.14 \
		hermit-abi-0.1.19 \
		hermit-abi-0.3.6 \
		ignore-0.4.22 \
		is-terminal-0.4.12 \
		lazy_static-1.4.0 \
		libc-0.2.153 \
		log-0.4.20 \
		memchr-2.7.1 \
		proc-macro2-1.0.78 \
		quote-1.0.35 \
		regex-1.10.3 \
		regex-automata-0.4.5 \
		regex-syntax-0.8.2 \
		same-file-1.0.6 \
		serde-1.0.197 \
		serde_derive-1.0.197 \
		strsim-0.8.0 \
		syn-2.0.50 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		unicode-ident-1.0.12 \
		unicode-width-0.1.11 \
		vec_map-0.8.2 \
		walkdir-2.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-targets-0.52.0 \
		windows_aarch64_gnullvm-0.52.0 \
		windows_aarch64_msvc-0.52.0 \
		windows_i686_gnu-0.52.0 \
		windows_i686_msvc-0.52.0 \
		windows_x86_64_gnu-0.52.0 \
		windows_x86_64_gnullvm-0.52.0 \
		windows_x86_64_msvc-0.52.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
