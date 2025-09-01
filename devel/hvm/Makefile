PORTNAME=	hvm
DISTVERSION=	g20240821
PORTREVISION=	7
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Massively parallel, optimal functional runtime in Rust
WWW=		https://higherorderco.com \
		https://github.com/HigherOrderCO/hvm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	HigherOrderCO
GH_PROJECT=	${PORTNAME:tu}
GH_TAGNAME=	6542760

CARGO_CRATES=	TSPL-0.0.13 \
		aho-corasick-1.1.3 \
		anstream-0.6.14 \
		anstyle-1.0.7 \
		anstyle-parse-0.2.4 \
		anstyle-query-1.0.3 \
		anstyle-wincon-3.0.3 \
		bstr-1.9.1 \
		cc-1.0.97 \
		clap-4.5.4 \
		clap_builder-4.5.2 \
		clap_lex-0.7.0 \
		colorchoice-1.0.1 \
		console-0.15.8 \
		encode_unicode-0.3.6 \
		globset-0.4.14 \
		hermit-abi-0.3.9 \
		highlight_error-0.1.1 \
		insta-1.39.0 \
		is_terminal_polyfill-1.70.0 \
		lazy_static-1.4.0 \
		libc-0.2.155 \
		linked-hash-map-0.5.6 \
		log-0.4.21 \
		memchr-2.7.2 \
		num_cpus-1.16.0 \
		proc-macro2-1.0.82 \
		quote-1.0.36 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.3 \
		same-file-1.0.6 \
		serde-1.0.200 \
		serde_derive-1.0.200 \
		similar-2.5.0 \
		strsim-0.11.1 \
		syn-2.0.64 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
		walkdir-2.5.0 \
		winapi-util-0.1.8 \
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

.include <bsd.port.mk>
