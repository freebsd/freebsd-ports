PORTNAME=	glitter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.3
PORTREVISION=	1
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
		aho-corasick-0.7.19 \
		ansi_term-0.12.1 \
		anyhow-1.0.64 \
		atty-0.2.14 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		clap-2.34.0 \
		colored-2.0.0 \
		either-1.8.0 \
		fancy-regex-0.10.0 \
		heck-0.3.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		itoa-1.0.3 \
		lazy_static-1.4.0 \
		libc-0.2.132 \
		maplit-1.0.2 \
		memchr-2.5.0 \
		ms-0.1.1 \
		once_cell-1.14.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.43 \
		quote-1.0.21 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		rustversion-1.0.9 \
		ryu-1.0.11 \
		serde-1.0.144 \
		serde_derive-1.0.144 \
		serde_json-1.0.85 \
		spinoff-0.5.3 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		strum-0.24.1 \
		strum_macros-0.24.3 \
		syn-1.0.99 \
		textwrap-0.11.0 \
		unicode-ident-1.0.3 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		which-4.3.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
