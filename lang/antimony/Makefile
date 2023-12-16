PORTNAME=	antimony
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	9
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

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		cc-1.0.66 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		either-1.6.1 \
		heck-0.3.1 \
		hermit-abi-0.1.17 \
		inkwell-0.1.0-beta.2 \
		inkwell_internals-0.3.0 \
		instant-0.1.9 \
		lazy_static-1.4.0 \
		libc-0.2.81 \
		llvm-sys-100.2.0 \
		lock_api-0.4.2 \
		memchr-2.4.0 \
		once_cell-1.5.2 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.2 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.24 \
		qbe-1.0.0 \
		quote-1.0.7 \
		redox_syscall-0.1.57 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		rust-embed-5.9.0 \
		rust-embed-impl-5.9.0 \
		rust-embed-utils-5.1.0 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		smallvec-1.6.1 \
		strsim-0.8.0 \
		structopt-0.3.21 \
		structopt-derive-0.4.14 \
		syn-1.0.53 \
		textwrap-0.11.0 \
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
