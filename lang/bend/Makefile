PORTNAME=	bend
DISTVERSION=	0.2.36
CATEGORIES=	lang
PKGNAMESUFFIX=	-language

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Massively parallel, high-level programming language
WWW=		https://higherorderco.com

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE

BUILD_DEPENDS=	rust-nightly>0:lang/rust-nightly
RUN_DEPENDS=	hvm:devel/hvm

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	HigherOrderCO
GH_PROJECT=	Bend

CARGO_BUILDDEP=	no
CARGO_CRATES=	TSPL-0.0.12 \
		anstream-0.6.14 \
		anstyle-1.0.7 \
		anstyle-parse-0.2.4 \
		anstyle-query-1.1.0 \
		anstyle-wincon-3.0.3 \
		cc-1.0.99 \
		cfg-if-1.0.0 \
		clap-4.5.7 \
		clap_builder-4.5.7 \
		clap_derive-4.5.5 \
		clap_lex-0.7.1 \
		colorchoice-1.0.1 \
		console-0.15.8 \
		either-1.12.0 \
		encode_unicode-0.3.6 \
		equivalent-1.0.1 \
		hashbrown-0.14.5 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		highlight_error-0.1.1 \
		hvm-2.0.19 \
		indexmap-2.2.6 \
		insta-1.39.0 \
		interner-0.2.1 \
		is_terminal_polyfill-1.70.0 \
		itertools-0.11.0 \
		lazy_static-1.4.0 \
		libc-0.2.155 \
		linked-hash-map-0.5.6 \
		loaned-0.1.2 \
		num_cpus-1.16.0 \
		proc-macro2-1.0.85 \
		psm-0.1.21 \
		quote-1.0.36 \
		same-file-1.0.6 \
		similar-2.5.0 \
		stacker-0.1.15 \
		stdext-0.3.3 \
		strsim-0.11.1 \
		syn-2.0.66 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.2 \
		walkdir-2.5.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.8 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.52.5

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
