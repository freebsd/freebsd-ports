PORTNAME=	tagref
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tagref helps you maintain cross-references in your code
WWW=		https://github.com/stepchowfun/tagref

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	stepchowfun

CARGO_CRATES=	aho-corasick-1.1.4 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		bitflags-2.11.0 \
		bstr-1.12.1 \
		clap-4.6.0 \
		clap_builder-4.6.0 \
		clap_derive-4.6.0 \
		clap_lex-1.1.0 \
		colorchoice-1.0.5 \
		colored-3.1.1 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		errno-0.3.14 \
		globset-0.4.18 \
		heck-0.5.0 \
		ignore-0.4.25 \
		is_terminal_polyfill-1.70.2 \
		libc-0.2.183 \
		linux-raw-sys-0.12.1 \
		log-0.4.29 \
		memchr-2.8.0 \
		once_cell_polyfill-1.70.2 \
		proc-macro2-1.0.106 \
		quote-1.0.45 \
		regex-1.12.3 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.10 \
		rustix-1.1.4 \
		same-file-1.0.6 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		strsim-0.11.1 \
		syn-2.0.117 \
		terminal_size-0.4.4 \
		unicode-ident-1.0.24 \
		utf8parse-0.2.2 \
		walkdir-2.5.0 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.61.2

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
