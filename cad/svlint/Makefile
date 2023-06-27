PORTNAME=	svlint
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	cad devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SystemVerilog linter
WWW=		https://github.com/dalance/svlint

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	dalance

CARGO_CRATES=	aho-corasick-1.0.2 \
		anyhow-1.0.71 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bytecount-0.6.3 \
		cfg-if-1.0.0 \
		clap-3.2.25 \
		clap_derive-3.2.25 \
		clap_lex-0.2.4 \
		colored-2.0.0 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		enquote-1.1.0 \
		equivalent-1.0.0 \
		getrandom-0.2.10 \
		hashbrown-0.12.3 \
		hashbrown-0.14.0 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		indexmap-1.9.3 \
		indexmap-2.0.0 \
		lazy_static-1.4.0 \
		libc-0.2.147 \
		libloading-0.8.0 \
		memchr-2.5.0 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		nom-greedyerror-0.5.0 \
		nom-packrat-0.7.0 \
		nom-packrat-macros-0.7.0 \
		nom-recursive-0.5.0 \
		nom-recursive-macros-0.5.0 \
		nom-tracable-0.9.0 \
		nom-tracable-macros-0.9.0 \
		nom_locate-4.1.0 \
		once_cell-1.18.0 \
		os_str_bytes-6.5.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.63 \
		quote-1.0.28 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.8.4 \
		regex-syntax-0.7.2 \
		rustversion-1.0.12 \
		same-file-1.0.6 \
		serde-1.0.164 \
		serde_derive-1.0.164 \
		serde_regex-1.1.0 \
		serde_spanned-0.6.3 \
		str-concat-0.2.0 \
		strsim-0.10.0 \
		sv-filelist-parser-0.1.3 \
		sv-parser-0.13.1 \
		sv-parser-error-0.13.1 \
		sv-parser-macros-0.13.1 \
		sv-parser-parser-0.13.1 \
		sv-parser-pp-0.13.1 \
		sv-parser-syntaxtree-0.13.1 \
		syn-1.0.109 \
		syn-2.0.22 \
		term-0.7.0 \
		termcolor-1.2.0 \
		textwrap-0.16.0 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		toml-0.7.5 \
		toml_datetime-0.6.3 \
		toml_edit-0.19.11 \
		unicode-ident-1.0.9 \
		version_check-0.9.4 \
		walkdir-2.3.3 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.0 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.48.0 \
		winnow-0.4.7

PLIST_FILES=	bin/${PORTNAME} \
		bin/mdgen

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/mdgen

.include <bsd.port.mk>
