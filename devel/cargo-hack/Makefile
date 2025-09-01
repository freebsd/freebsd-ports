PORTNAME=	cargo-hack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.37
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

CARGO_CRATES=	anyhow-1.0.99 \
		autocfg-1.5.0 \
		bitflags-2.9.3 \
		build-context-0.1.3 \
		cargo-config2-0.1.35 \
		cfg-if-1.0.3 \
		cfg_aliases-0.2.1 \
		ctrlc-3.4.7 \
		easy-ext-1.0.2 \
		equivalent-1.0.2 \
		errno-0.3.13 \
		fastrand-2.3.0 \
		fs-err-3.1.1 \
		hashbrown-0.15.5 \
		indexmap-2.11.0 \
		itoa-1.0.15 \
		lexopt-0.3.1 \
		libc-0.2.175 \
		linux-raw-sys-0.9.4 \
		memchr-2.7.5 \
		nix-0.30.1 \
		once_cell-1.21.3 \
		proc-macro2-1.0.101 \
		quote-1.0.40 \
		rustix-1.0.8 \
		ryu-1.0.20 \
		same-file-1.0.6 \
		serde-1.0.219 \
		serde_derive-1.0.219 \
		serde_json-1.0.143 \
		serde_spanned-1.0.0 \
		syn-2.0.106 \
		tempfile-3.21.0 \
		termcolor-1.4.1 \
		toml-0.9.5 \
		toml_datetime-0.7.0 \
		toml_edit-0.23.4 \
		toml_parser-1.0.2 \
		toml_writer-1.0.2 \
		unicode-ident-1.0.18 \
		winapi-util-0.1.10 \
		windows-link-0.1.3 \
		windows-sys-0.59.0 \
		windows-sys-0.60.2 \
		windows-targets-0.52.6 \
		windows-targets-0.53.3 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_gnullvm-0.53.0 \
		windows_aarch64_msvc-0.52.6 \
		windows_aarch64_msvc-0.53.0 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnu-0.53.0 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_gnullvm-0.53.0 \
		windows_i686_msvc-0.52.6 \
		windows_i686_msvc-0.53.0 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnu-0.53.0 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_gnullvm-0.53.0 \
		windows_x86_64_msvc-0.52.6 \
		windows_x86_64_msvc-0.53.0 \
		winnow-0.7.13 \
		test-helper@git+https://github.com/taiki-e/test-helper.git?rev=f38a7f5\#f38a7f5895cb5f562195c6116cffc139d712acf5

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
