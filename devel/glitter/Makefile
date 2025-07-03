PORTNAME=	glitter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.6
PORTREVISION=	11
CATEGORIES=	devel
PKGNAMESUFFIX=	-git-tool

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for generating and structuring Git commit messages
WWW=		https://github.com/milo123459/glitter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	milo123459

CARGO_CRATES=	Inflector-0.11.4 \
		aho-corasick-1.1.3 \
		ansi_term-0.12.1 \
		anyhow-1.0.81 \
		atty-0.2.14 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		bitflags-2.5.0 \
		clap-2.34.0 \
		colored-2.1.0 \
		either-1.10.0 \
		errno-0.3.8 \
		fancy-regex-0.13.0 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		home-0.5.9 \
		itoa-1.0.11 \
		lazy_static-1.4.0 \
		libc-0.2.153 \
		linux-raw-sys-0.4.13 \
		memchr-2.7.2 \
		ms-0.1.1 \
		once_cell-1.19.0 \
		paste-1.0.14 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.79 \
		quote-1.0.35 \
		regex-1.10.4 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.3 \
		rustix-0.38.32 \
		ryu-1.0.17 \
		serde-1.0.197 \
		serde_derive-1.0.197 \
		serde_json-1.0.115 \
		spinoff-0.8.0 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		syn-1.0.109 \
		syn-2.0.58 \
		textwrap-0.11.0 \
		unicode-ident-1.0.12 \
		unicode-segmentation-1.11.0 \
		unicode-width-0.1.11 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		which-6.0.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.4 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.4 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.4 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.4 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.4 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.4 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.4 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.4 \
		winsafe-0.0.19

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
