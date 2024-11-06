PORTNAME=	cargo-hack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.33
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

CARGO_CRATES=	anyhow-1.0.92 \
		autocfg-1.4.0 \
		bitflags-2.6.0 \
		build-context-0.1.3 \
		cargo-config2-0.1.29 \
		cfg-if-1.0.0 \
		cfg_aliases-0.2.1 \
		ctrlc-3.4.5 \
		easy-ext-1.0.2 \
		equivalent-1.0.1 \
		errno-0.3.9 \
		fastrand-2.1.1 \
		fs-err-3.0.0 \
		hashbrown-0.15.0 \
		home-0.5.9 \
		indexmap-2.6.0 \
		itoa-1.0.11 \
		lexopt-0.3.0 \
		libc-0.2.161 \
		linux-raw-sys-0.4.14 \
		memchr-2.7.4 \
		nix-0.29.0 \
		once_cell-1.20.2 \
		proc-macro2-1.0.89 \
		quote-1.0.37 \
		rustix-0.38.38 \
		ryu-1.0.18 \
		same-file-1.0.6 \
		serde-1.0.214 \
		serde_derive-1.0.214 \
		serde_json-1.0.132 \
		serde_spanned-0.6.8 \
		slab-0.4.9 \
		syn-2.0.87 \
		tempfile-3.13.0 \
		termcolor-1.4.1 \
		toml_datetime-0.6.8 \
		toml_edit-0.22.22 \
		unicode-ident-1.0.13 \
		winapi-util-0.1.9 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.6.20

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
