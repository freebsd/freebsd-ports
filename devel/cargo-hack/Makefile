PORTNAME=	cargo-hack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.46
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

CARGO_CRATES=	anyhow-1.0.104 \
		autocfg-1.5.1 \
		bitflags-2.13.2 \
		block2-0.6.2 \
		build-context-0.1.4 \
		cargo-config2-0.1.45 \
		cfg-if-1.0.5 \
		cfg_aliases-0.2.2 \
		ctrlc-3.5.2 \
		dispatch2-0.3.1 \
		easy-ext-1.0.3 \
		equivalent-1.0.3 \
		errno-0.3.14 \
		fastrand-2.5.0 \
		fs-err-3.3.2 \
		hashbrown-0.17.1 \
		indexmap-2.14.2 \
		itoa-1.0.18 \
		lexopt-0.3.2 \
		libc-0.2.191 \
		linux-raw-sys-0.12.1 \
		memchr-2.8.3 \
		nix-0.31.3 \
		objc2-0.6.5 \
		objc2-encode-4.1.0 \
		once_cell-1.21.4 \
		proc-macro2-1.0.107 \
		quote-1.0.47 \
		rustix-1.1.6 \
		same-file-1.0.6 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		serde_json-1.0.154 \
		serde_spanned-1.1.2 \
		syn-3.0.9 \
		tempfile-3.27.0 \
		termcolor-1.4.1 \
		toml-1.2.0+spec-1.1.0 \
		toml_datetime-1.1.2+spec-1.1.0 \
		toml_edit-0.25.18+spec-1.1.0 \
		toml_parser-1.1.5+spec-1.1.0 \
		toml_writer-1.2.0+spec-1.1.0 \
		unicode-ident-1.0.27 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		winnow-1.0.4 \
		zmij-1.0.23 \
		test-helper@git+https://github.com/taiki-e/test-helper.git?rev=b931ac1a34794aede5b019c613e50157a35a7ec4\#b931ac1a34794aede5b019c613e50157a35a7ec4

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
