PORTNAME=	svlint
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.3
PORTREVISION=	11
CATEGORIES=	cad devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SystemVerilog linter
WWW=		https://github.com/dalance/svlint

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	dalance

CARGO_CRATES=	aho-corasick-1.1.3 \
		anyhow-1.0.86 \
		atty-0.2.14 \
		autocfg-1.3.0 \
		bitflags-1.3.2 \
		bitflags-2.5.0 \
		bytecount-0.6.8 \
		cfg-if-1.0.0 \
		clap-3.2.25 \
		clap_complete-3.2.5 \
		clap_derive-3.2.25 \
		clap_lex-0.2.4 \
		colored-2.1.0 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		enquote-1.1.0 \
		equivalent-1.0.1 \
		getrandom-0.2.15 \
		hashbrown-0.12.3 \
		hashbrown-0.14.5 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		indexmap-1.9.3 \
		indexmap-2.2.6 \
		lazy_static-1.4.0 \
		libc-0.2.155 \
		libloading-0.8.3 \
		libredox-0.1.3 \
		memchr-2.7.2 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		nom-greedyerror-0.5.0 \
		nom-packrat-0.7.0 \
		nom-packrat-macros-0.7.0 \
		nom-recursive-0.5.1 \
		nom-recursive-macros-0.5.1 \
		nom-tracable-0.9.1 \
		nom-tracable-macros-0.9.1 \
		nom_locate-4.2.0 \
		once_cell-1.19.0 \
		os_str_bytes-6.6.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.85 \
		quote-1.0.36 \
		redox_users-0.4.5 \
		regex-1.10.4 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.3 \
		rustversion-1.0.17 \
		same-file-1.0.6 \
		serde-1.0.203 \
		serde_derive-1.0.203 \
		serde_regex-1.1.0 \
		serde_spanned-0.6.6 \
		str-concat-0.2.0 \
		strsim-0.10.0 \
		sv-filelist-parser-0.1.3 \
		sv-parser-0.13.3 \
		sv-parser-error-0.13.3 \
		sv-parser-macros-0.13.3 \
		sv-parser-parser-0.13.3 \
		sv-parser-pp-0.13.3 \
		sv-parser-syntaxtree-0.13.3 \
		syn-1.0.109 \
		syn-2.0.66 \
		term-0.7.0 \
		termcolor-1.4.1 \
		textwrap-0.16.1 \
		thiserror-1.0.61 \
		thiserror-impl-1.0.61 \
		toml-0.8.14 \
		toml_datetime-0.6.6 \
		toml_edit-0.22.14 \
		unicode-ident-1.0.12 \
		version_check-0.9.4 \
		walkdir-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.8 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.5 \
		winnow-0.6.11

PLIST_FILES=	bin/${PORTNAME} \
		bin/mdgen

.include <bsd.port.mk>
