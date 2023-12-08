PORTNAME=	tagref
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.4
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tagref helps you maintain cross-references in your code
WWW=		https://github.com/stepchowfun/tagref

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	stepchowfun

CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bstr-0.2.15 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		colored-1.9.3 \
		crossbeam-utils-0.8.3 \
		fnv-1.0.7 \
		globset-0.4.6 \
		hermit-abi-0.1.18 \
		ignore-0.4.17 \
		lazy_static-1.4.0 \
		libc-0.2.93 \
		log-0.4.14 \
		memchr-2.3.4 \
		once_cell-1.7.2 \
		regex-1.4.5 \
		regex-syntax-0.6.23 \
		same-file-1.0.6 \
		strsim-0.8.0 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thread_local-1.1.3 \
		unicode-width-0.1.8 \
		vec_map-0.8.2 \
		walkdir-2.3.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
