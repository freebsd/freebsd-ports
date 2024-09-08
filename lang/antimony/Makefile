PORTNAME=	antimony
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	3
CATEGORIES=	lang
PKGNAMESUFFIX=	-language

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Antimony programming language
WWW=		https://antimony-lang.github.io/antimony/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo nodejs:run

USE_GITHUB=	yes
GH_ACCOUNT=	antimony-lang

CARGO_CRATES=	aho-corasick-1.0.1 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		cc-1.0.66 \
		clap-2.33.3 \
		either-1.6.1 \
		heck-0.3.1 \
		hermit-abi-0.1.17 \
		inkwell-0.4.0 \
		inkwell_internals-0.9.0 \
		lazy_static-1.4.0 \
		libc-0.2.139 \
		llvm-sys-100.2.4 \
		memchr-2.6.3 \
		once_cell-1.17.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.78 \
		qbe-1.0.0 \
		quote-1.0.35 \
		regex-1.10.4 \
		regex-automata-0.4.4 \
		regex-syntax-0.8.2 \
		rust-embed-5.9.0 \
		rust-embed-impl-5.9.0 \
		rust-embed-utils-5.1.0 \
		same-file-1.0.6 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		syn-1.0.53 \
		syn-2.0.48 \
		textwrap-0.11.0 \
		thiserror-1.0.56 \
		thiserror-impl-1.0.56 \
		unicode-ident-1.0.9 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		walkdir-2.3.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/sb

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sb

.include <bsd.port.mk>
