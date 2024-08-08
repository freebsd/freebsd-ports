PORTNAME=	cargo-hack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.30
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

CARGO_CRATES=	anyhow-1.0.86 \
		autocfg-1.3.0 \
		bitflags-2.6.0 \
		build-context-0.1.2 \
		cargo-config2-0.1.26 \
		cfg-if-1.0.0 \
		cfg_aliases-0.1.1 \
		ctrlc-3.4.4 \
		easy-ext-1.0.2 \
		equivalent-1.0.1 \
		errno-0.3.9 \
		fastrand-2.1.0 \
		fs-err-2.11.0 \
		hashbrown-0.14.5 \
		home-0.5.9 \
		indexmap-2.2.6 \
		itoa-1.0.11 \
		lexopt-0.3.0 \
		libc-0.2.155 \
		linux-raw-sys-0.4.14 \
		memchr-2.7.4 \
		nix-0.28.0 \
		proc-macro2-1.0.86 \
		quote-1.0.36 \
		rustix-0.38.34 \
		ryu-1.0.18 \
		same-file-1.0.6 \
		serde-1.0.204 \
		serde_derive-1.0.204 \
		serde_json-1.0.120 \
		serde_spanned-0.6.6 \
		slab-0.4.9 \
		syn-2.0.71 \
		tempfile-3.10.1 \
		termcolor-1.4.1 \
		toml_datetime-0.6.6 \
		toml_edit-0.22.15 \
		unicode-ident-1.0.12 \
		winapi-util-0.1.8 \
		windows-sys-0.52.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.6.13

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
