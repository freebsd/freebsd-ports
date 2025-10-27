PORTNAME=	cargo-hack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.39
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rust: Cargo subcommand for testing and continuous integration
WWW=		https://github.com/taiki-e/cargo-hack

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	taiki-e

CARGO_CRATES=	anyhow-1.0.100 \
		autocfg-1.5.0 \
		bitflags-2.10.0 \
		build-context-0.1.3 \
		cargo-config2-0.1.39 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.1 \
		ctrlc-3.5.0 \
		dispatch-0.2.0 \
		easy-ext-1.0.2 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		fastrand-2.3.0 \
		fs-err-3.1.3 \
		hashbrown-0.16.0 \
		indexmap-2.12.0 \
		itoa-1.0.15 \
		lexopt-0.3.1 \
		libc-0.2.177 \
		linux-raw-sys-0.11.0 \
		memchr-2.7.6 \
		nix-0.30.1 \
		once_cell-1.21.3 \
		proc-macro2-1.0.103 \
		quote-1.0.41 \
		rustix-1.1.2 \
		ryu-1.0.20 \
		same-file-1.0.6 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.145 \
		serde_spanned-1.0.3 \
		syn-2.0.108 \
		tempfile-3.23.0 \
		termcolor-1.4.1 \
		toml-0.9.8 \
		toml_datetime-0.7.3 \
		toml_edit-0.23.7 \
		toml_parser-1.0.4 \
		toml_writer-1.0.4 \
		unicode-ident-1.0.20 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		winnow-0.7.13 \
		test-helper@git+https://github.com/taiki-e/test-helper.git?rev=f38a7f5\#f38a7f5895cb5f562195c6116cffc139d712acf5

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
