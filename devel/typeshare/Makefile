PORTNAME=	typeshare
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool to synchronize type definitions between Rust and other languages
WWW=		https://github.com/1password/typeshare

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	1password

CARGO_BUILD_ARGS=	--package=typeshare-cli
CARGO_INSTALL_PATH=	cli
CARGO_CRATES=	aho-corasick-0.7.19 \
		android_system_properties-0.1.5 \
		anyhow-1.0.65 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.12.0 \
		cfg-if-1.0.0 \
		chrono-0.4.22 \
		clap-3.2.22 \
		clap_complete-3.2.5 \
		clap_complete_command-0.3.4 \
		clap_complete_fig-3.2.4 \
		clap_lex-0.2.4 \
		core-foundation-sys-0.8.3 \
		crossbeam-channel-0.5.6 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.10 \
		crossbeam-utils-0.8.11 \
		dissimilar-1.0.4 \
		either-1.8.0 \
		expect-test-1.4.0 \
		fnv-1.0.7 \
		globset-0.4.9 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		iana-time-zone-0.1.50 \
		ignore-0.4.18 \
		indexmap-1.9.1 \
		itertools-0.10.5 \
		itoa-1.0.3 \
		joinery-2.1.0 \
		js-sys-0.3.60 \
		lazy_format-1.10.0 \
		lazy_static-1.4.0 \
		libc-0.2.133 \
		log-0.4.17 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		once_cell-1.15.0 \
		os_str_bytes-6.3.0 \
		proc-macro2-1.0.60 \
		quote-1.0.28 \
		rayon-1.5.3 \
		rayon-core-1.9.3 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		ryu-1.0.11 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.164 \
		serde_derive-1.0.164 \
		serde_json-1.0.85 \
		strsim-0.10.0 \
		syn-2.0.18 \
		termcolor-1.1.3 \
		textwrap-0.15.1 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		thread_local-1.1.4 \
		toml-0.5.9 \
		unicode-ident-1.0.4 \
		walkdir-2.3.2 \
		wasm-bindgen-0.2.87 \
		wasm-bindgen-backend-0.2.87 \
		wasm-bindgen-macro-0.2.87 \
		wasm-bindgen-macro-support-0.2.87 \
		wasm-bindgen-shared-0.2.87 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
