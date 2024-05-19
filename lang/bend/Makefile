PORTNAME=	bend
DISTVERSION=	0.2.7
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
CARGO_CRATES=	TSPL-0.0.9 \
		TSPL-0.0.12 \
		anstream-0.6.14 \
		anstyle-1.0.7 \
		anstyle-parse-0.2.4 \
		anstyle-query-1.0.3 \
		anstyle-wincon-3.0.3 \
		arrayvec-0.7.4 \
		autocfg-1.3.0 \
		bitflags-2.5.0 \
		cc-1.0.97 \
		cfg-if-1.0.0 \
		clap-4.5.4 \
		clap_builder-4.5.2 \
		clap_derive-4.5.4 \
		clap_lex-0.7.0 \
		colorchoice-1.0.1 \
		console-0.15.8 \
		either-1.12.0 \
		encode_unicode-0.3.6 \
		equivalent-1.0.1 \
		hashbrown-0.14.5 \
		heck-0.5.0 \
		highlight_error-0.1.1 \
		hvm-core-0.3.0-hvm32.compat.2 \
		indexmap-2.2.6 \
		insta-1.39.0 \
		interner-0.2.1 \
		is_terminal_polyfill-1.70.0 \
		itertools-0.11.0 \
		lazy_static-1.4.0 \
		libc-0.2.153 \
		linked-hash-map-0.5.6 \
		loaned-0.1.1 \
		lock_api-0.4.12 \
		nohash-hasher-0.2.0 \
		parking_lot-0.12.2 \
		parking_lot_core-0.9.10 \
		proc-macro2-1.0.82 \
		psm-0.1.21 \
		quote-1.0.36 \
		redox_syscall-0.5.1 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		similar-2.5.0 \
		smallvec-1.13.2 \
		stacker-0.1.15 \
		stdext-0.3.3 \
		strsim-0.11.1 \
		syn-2.0.64 \
		thiserror-1.0.60 \
		thiserror-impl-1.0.60 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
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
