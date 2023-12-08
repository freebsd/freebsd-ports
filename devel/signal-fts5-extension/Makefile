PORTNAME=	signal-fts5-extension
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	7
CATEGORIES=	devel

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	FTS5 extension for signal_tokenizer
WWW=		https://github.com/signalapp/Signal-FTS5-Extension

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_PROJECT=	Signal-FTS5-Extension
CARGO_CRATES=	atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.12.0 \
		cast-0.3.0 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		criterion-0.3.6 \
		criterion-plot-0.4.5 \
		crossbeam-channel-0.5.6 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.13 \
		crossbeam-utils-0.8.14 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		either-1.8.1 \
		half-1.8.2 \
		hermit-abi-0.1.19 \
		hermit-abi-0.2.6 \
		itertools-0.10.5 \
		itoa-0.4.8 \
		itoa-1.0.5 \
		js-sys-0.3.60 \
		lazy_static-1.4.0 \
		libc-0.2.139 \
		log-0.4.17 \
		memchr-2.5.0 \
		memoffset-0.7.1 \
		num-traits-0.2.15 \
		num_cpus-1.15.0 \
		once_cell-1.17.0 \
		oorandom-11.1.3 \
		plotters-0.3.4 \
		plotters-backend-0.3.4 \
		plotters-svg-0.3.3 \
		proc-macro2-1.0.50 \
		quote-1.0.23 \
		rayon-1.6.1 \
		rayon-core-1.10.2 \
		regex-1.7.1 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.28 \
		ryu-1.0.12 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.152 \
		serde_cbor-0.11.2 \
		serde_derive-1.0.152 \
		serde_json-1.0.91 \
		syn-1.0.107 \
		textwrap-0.11.0 \
		tinytemplate-1.2.1 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		unicode-ident-1.0.6 \
		unicode-normalization-0.1.22 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.10 \
		walkdir-2.3.2 \
		wasm-bindgen-0.2.83 \
		wasm-bindgen-backend-0.2.83 \
		wasm-bindgen-macro-0.2.83 \
		wasm-bindgen-macro-support-0.2.83 \
		wasm-bindgen-shared-0.2.83 \
		web-sys-0.3.60 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	lib/libsignal_tokenizer.a

do-install:
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/libsignal_tokenizer.a ${STAGEDIR}${LOCALBASE}/lib/

.include <bsd.port.mk>
