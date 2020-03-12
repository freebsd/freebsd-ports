# $FreeBSD$

PORTNAME=	cargo-tree
DISTVERSION=	0.29.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rust's cargo subcommand to visualize dependency graph as a tree #'

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo ssl

CARGO_CRATES=	ansi_term-0.11.0 \
		anyhow-1.0.26 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		cargo_metadata-0.9.1 \
		clap-2.33.0 \
		fixedbitset-0.1.9 \
		heck-0.3.1 \
		hermit-abi-0.1.6 \
		itoa-0.4.5 \
		lazy_static-1.4.0 \
		libc-0.2.66 \
		ordermap-0.3.5 \
		petgraph-0.4.13 \
		proc-macro-error-0.4.5 \
		proc-macro-error-attr-0.4.5 \
		proc-macro2-1.0.8 \
		quote-1.0.2 \
		rustversion-1.0.2 \
		ryu-1.0.2 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.104 \
		serde_derive-1.0.104 \
		serde_json-1.0.45 \
		strsim-0.8.0 \
		structopt-0.3.8 \
		structopt-derive-0.4.1 \
		syn-1.0.14 \
		syn-mid-0.4.0 \
		textwrap-0.11.0 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cargo-tree

.include <bsd.port.mk>
