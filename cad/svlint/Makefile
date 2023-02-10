PORTNAME=	svlint
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	cad devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SystemVerilog linter
WWW=		https://github.com/dalance/svlint

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	dalance

CARGO_CRATES=	aho-corasick-0.7.20 \
		anyhow-1.0.68 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitvec-0.19.6 \
		bytecount-0.3.2 \
		bytecount-0.6.3 \
		cfg-if-1.0.0 \
		clap-3.2.23 \
		clap_derive-3.2.18 \
		clap_lex-0.2.4 \
		colored-2.0.0 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		enquote-1.1.0 \
		funty-1.1.0 \
		getrandom-0.2.8 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.9.2 \
		lazy_static-1.4.0 \
		lexical-core-0.7.6 \
		libc-0.2.139 \
		libloading-0.7.4 \
		memchr-2.5.0 \
		nom-5.1.2 \
		nom-6.1.2 \
		nom-greedyerror-0.3.1 \
		nom-packrat-0.5.0 \
		nom-packrat-macros-0.5.0 \
		nom-recursive-0.3.0 \
		nom-recursive-macros-0.3.0 \
		nom-tracable-0.7.0 \
		nom-tracable-macros-0.7.0 \
		nom_locate-1.0.0 \
		nom_locate-2.1.0 \
		nom_locate-3.0.2 \
		once_cell-1.17.0 \
		os_str_bytes-6.4.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.49 \
		quote-1.0.23 \
		radium-0.5.3 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.7.0 \
		regex-syntax-0.6.28 \
		rustversion-1.0.11 \
		ryu-1.0.12 \
		same-file-1.0.6 \
		serde-1.0.152 \
		serde_derive-1.0.152 \
		serde_regex-1.1.0 \
		static_assertions-1.1.0 \
		str-concat-0.2.0 \
		strsim-0.10.0 \
		sv-filelist-parser-0.1.3 \
		sv-parser-0.12.2 \
		sv-parser-error-0.12.2 \
		sv-parser-macros-0.12.2 \
		sv-parser-parser-0.12.2 \
		sv-parser-pp-0.12.2 \
		sv-parser-syntaxtree-0.12.2 \
		syn-1.0.107 \
		tap-1.0.1 \
		term-0.7.0 \
		termcolor-1.1.3 \
		textwrap-0.16.0 \
		thiserror-1.0.38 \
		thiserror-impl-1.0.38 \
		toml-0.5.10 \
		unicode-ident-1.0.6 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wyz-0.2.0

PLIST_FILES=	bin/${PORTNAME} \
		bin/mdgen

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/mdgen

.include <bsd.port.mk>
