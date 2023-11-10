PORTNAME=	cargo-depgraph
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Create dependency graphs for cargo projects using 'cargo metadata'
WWW=		https://github.com/jplatte/cargo-depgraph

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	graphviz>0:graphics/graphviz

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	jplatte

CARGO_CRATES=	anstream-0.3.2 \
		anstyle-1.0.1 \
		anstyle-parse-0.2.1 \
		anstyle-query-1.0.0 \
		anstyle-wincon-1.0.1 \
		anyhow-1.0.71 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		camino-1.1.4 \
		cargo-platform-0.1.2 \
		cargo_metadata-0.15.4 \
		cc-1.0.79 \
		clap-4.3.8 \
		clap_builder-4.3.8 \
		clap_lex-0.5.0 \
		colorchoice-1.0.0 \
		errno-0.3.1 \
		errno-dragonfly-0.1.2 \
		fixedbitset-0.4.2 \
		hashbrown-0.12.3 \
		hermit-abi-0.3.1 \
		indexmap-1.9.3 \
		io-lifetimes-1.0.11 \
		is-terminal-0.4.7 \
		itoa-1.0.6 \
		libc-0.2.147 \
		linux-raw-sys-0.3.8 \
		petgraph-0.6.3 \
		proc-macro2-1.0.63 \
		quote-1.0.28 \
		rustix-0.37.20 \
		ryu-1.0.13 \
		semver-1.0.17 \
		serde-1.0.164 \
		serde_derive-1.0.164 \
		serde_json-1.0.99 \
		strsim-0.10.0 \
		syn-2.0.22 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		unicode-ident-1.0.9 \
		utf8parse-0.2.1 \
		windows-sys-0.48.0 \
		windows-targets-0.48.0 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.48.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
