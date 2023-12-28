PORTNAME=	svlint
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
CATEGORIES=	cad devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SystemVerilog linter
WWW=		https://github.com/dalance/svlint

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	dalance

CARGO_CRATES=	aho-corasick-1.1.2 \
		anyhow-1.0.77 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		bytecount-0.6.7 \
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
		getrandom-0.2.11 \
		hashbrown-0.12.3 \
		hashbrown-0.14.3 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		indexmap-1.9.3 \
		indexmap-2.1.0 \
		lazy_static-1.4.0 \
		libc-0.2.151 \
		libloading-0.8.1 \
		libredox-0.0.1 \
		memchr-2.6.4 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		nom-greedyerror-0.5.0 \
		nom-packrat-0.7.0 \
		nom-packrat-macros-0.7.0 \
		nom-recursive-0.5.0 \
		nom-recursive-macros-0.5.0 \
		nom-tracable-0.9.1 \
		nom-tracable-macros-0.9.1 \
		nom_locate-4.2.0 \
		once_cell-1.19.0 \
		os_str_bytes-6.6.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.71 \
		quote-1.0.33 \
		redox_syscall-0.4.1 \
		redox_users-0.4.4 \
		regex-1.10.2 \
		regex-automata-0.4.3 \
		regex-syntax-0.8.2 \
		rustversion-1.0.14 \
		same-file-1.0.6 \
		serde-1.0.193 \
		serde_derive-1.0.193 \
		serde_regex-1.1.0 \
		serde_spanned-0.6.5 \
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
		syn-2.0.43 \
		term-0.7.0 \
		termcolor-1.4.0 \
		textwrap-0.16.0 \
		thiserror-1.0.52 \
		thiserror-impl-1.0.52 \
		toml-0.8.8 \
		toml_datetime-0.6.5 \
		toml_edit-0.21.0 \
		unicode-ident-1.0.12 \
		version_check-0.9.4 \
		walkdir-2.4.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5 \
		winnow-0.5.31

PLIST_FILES=	bin/${PORTNAME} \
		bin/mdgen

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/mdgen

.include <bsd.port.mk>
