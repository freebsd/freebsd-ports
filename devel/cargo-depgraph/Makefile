PORTNAME=	cargo-depgraph
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
PORTREVISION=	16
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rust: Create dependency graphs for cargo projects
WWW=		https://github.com/jplatte/cargo-depgraph

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	graphviz>0:graphics/graphviz

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	jplatte

CARGO_CRATES=	anstream-0.6.4 \
		anstyle-1.0.4 \
		anstyle-parse-0.2.3 \
		anstyle-query-1.0.1 \
		anstyle-wincon-3.0.2 \
		anyhow-1.0.75 \
		camino-1.1.6 \
		cargo-platform-0.1.5 \
		cargo_metadata-0.18.1 \
		clap-4.4.11 \
		clap_builder-4.4.11 \
		clap_lex-0.6.0 \
		colorchoice-1.0.0 \
		equivalent-1.0.1 \
		fixedbitset-0.4.2 \
		hashbrown-0.14.3 \
		indexmap-2.1.0 \
		itoa-1.0.9 \
		petgraph-0.6.4 \
		proc-macro2-1.0.70 \
		quote-1.0.33 \
		ryu-1.0.15 \
		semver-1.0.20 \
		serde-1.0.193 \
		serde_derive-1.0.193 \
		serde_json-1.0.108 \
		strsim-0.10.0 \
		syn-2.0.39 \
		thiserror-1.0.50 \
		thiserror-impl-1.0.50 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
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
