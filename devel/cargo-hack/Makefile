PORTNAME=	cargo-hack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.45
PORTREVISION=	1
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

CARGO_CRATES=	anyhow-1.0.102 \
		autocfg-1.5.1 \
		bitflags-2.11.1 \
		block2-0.6.2 \
		build-context-0.1.4 \
		cargo-config2-0.1.44 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.1 \
		ctrlc-3.5.2 \
		dispatch2-0.3.1 \
		easy-ext-1.0.3 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		fastrand-2.4.1 \
		fs-err-3.3.0 \
		hashbrown-0.17.1 \
		indexmap-2.14.0 \
		itoa-1.0.18 \
		lexopt-0.3.2 \
		libc-0.2.186 \
		linux-raw-sys-0.12.1 \
		memchr-2.8.1 \
		nix-0.31.3 \
		objc2-0.6.4 \
		objc2-encode-4.1.0 \
		once_cell-1.21.4 \
		proc-macro2-1.0.106 \
		quote-1.0.45 \
		rustix-1.1.4 \
		same-file-1.0.6 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.150 \
		serde_spanned-1.1.1 \
		syn-2.0.117 \
		tempfile-3.27.0 \
		termcolor-1.4.1 \
		toml-1.1.2+spec-1.1.0 \
		toml_datetime-1.1.1+spec-1.1.0 \
		toml_edit-0.25.12+spec-1.1.0 \
		toml_parser-1.1.2+spec-1.1.0 \
		toml_writer-1.1.1+spec-1.1.0 \
		unicode-ident-1.0.24 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		winnow-1.0.3 \
		zmij-1.0.21 \
		test-helper@git+https://github.com/taiki-e/test-helper.git?rev=82e3b012a49fb16587e165986674290ef682a5b0\#82e3b012a49fb16587e165986674290ef682a5b0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
