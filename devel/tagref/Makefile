PORTNAME=	tagref
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.5
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tagref helps you maintain cross-references in your code
WWW=		https://github.com/stepchowfun/tagref

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	stepchowfun

CARGO_CRATES=	aho-corasick-1.0.4 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		bitflags-1.3.2 \
		bitflags-2.4.0 \
		bstr-1.6.0 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		colored-1.9.4 \
		errno-0.3.2 \
		errno-dragonfly-0.1.2 \
		fnv-1.0.7 \
		globset-0.4.13 \
		hermit-abi-0.1.19 \
		hermit-abi-0.3.2 \
		ignore-0.4.20 \
		is-terminal-0.4.9 \
		lazy_static-1.4.0 \
		libc-0.2.147 \
		linux-raw-sys-0.4.5 \
		log-0.4.20 \
		memchr-2.5.0 \
		once_cell-1.18.0 \
		proc-macro2-1.0.66 \
		quote-1.0.33 \
		regex-1.9.3 \
		regex-automata-0.3.6 \
		regex-syntax-0.7.4 \
		rustix-0.38.8 \
		same-file-1.0.6 \
		serde-1.0.186 \
		serde_derive-1.0.186 \
		strsim-0.8.0 \
		syn-2.0.29 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thread_local-1.1.7 \
		unicode-ident-1.0.11 \
		unicode-width-0.1.10 \
		vec_map-0.8.2 \
		walkdir-2.3.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
