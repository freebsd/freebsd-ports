PORTNAME=	tagref
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tagref helps you maintain cross-references in your code
WWW=		https://github.com/stepchowfun/tagref

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	stepchowfun

CARGO_CRATES=	aho-corasick-1.1.5 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		bitflags-2.13.2 \
		bstr-1.13.1 \
		clap-4.6.7 \
		clap_builder-4.6.7 \
		clap_derive-4.6.7 \
		clap_lex-1.1.1 \
		colorchoice-1.0.5 \
		colored-3.1.1 \
		crossbeam-deque-0.8.8 \
		crossbeam-epoch-0.9.21 \
		crossbeam-utils-0.8.23 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		globset-0.4.20 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		ignore-0.4.33 \
		indexmap-2.14.2 \
		is_terminal_polyfill-1.70.2 \
		itoa-1.0.18 \
		libc-0.2.189 \
		libyaml-rs-0.3.0 \
		linux-raw-sys-0.12.1 \
		log-0.4.34 \
		memchr-2.8.3 \
		once_cell_polyfill-1.70.2 \
		proc-macro2-1.0.107 \
		quote-1.0.47 \
		regex-1.13.1 \
		regex-automata-0.4.18 \
		regex-syntax-0.8.11 \
		rustix-1.1.4 \
		ryu-1.0.23 \
		same-file-1.0.6 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		strsim-0.11.1 \
		syn-3.0.5 \
		terminal_size-0.4.4 \
		unicode-ident-1.0.24 \
		utf8parse-0.2.2 \
		walkdir-2.5.0 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		yaml_serde-0.10.7

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
