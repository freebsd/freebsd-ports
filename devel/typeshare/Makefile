PORTNAME=	typeshare
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.0
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
CARGO_CRATES=	aho-corasick-1.1.3 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anyhow-1.0.82 \
		atty-0.2.14 \
		autocfg-1.2.0 \
		bitflags-1.3.2 \
		bstr-1.9.1 \
		bumpalo-3.16.0 \
		cc-1.0.94 \
		cfg-if-1.0.0 \
		chrono-0.4.38 \
		clap-3.2.25 \
		clap_complete-3.2.5 \
		clap_complete_command-0.3.4 \
		clap_complete_fig-3.2.4 \
		clap_lex-0.2.4 \
		cool_asserts-2.0.3 \
		core-foundation-sys-0.8.6 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.19 \
		dissimilar-1.0.7 \
		either-1.11.0 \
		equivalent-1.0.1 \
		expect-test-1.5.0 \
		flexi_logger-0.28.5 \
		glob-0.3.1 \
		globset-0.4.14 \
		hashbrown-0.12.3 \
		hashbrown-0.14.3 \
		hermit-abi-0.1.19 \
		iana-time-zone-0.1.60 \
		iana-time-zone-haiku-0.1.2 \
		ignore-0.4.22 \
		indent_write-2.2.0 \
		indexmap-1.9.3 \
		indexmap-2.2.6 \
		itertools-0.12.1 \
		itoa-1.0.11 \
		joinery-2.1.0 \
		js-sys-0.3.69 \
		lazy_format-2.0.3 \
		libc-0.2.153 \
		log-0.4.21 \
		memchr-2.7.2 \
		nu-ansi-term-0.50.1 \
		num-traits-0.2.18 \
		once_cell-1.19.0 \
		os_str_bytes-6.6.1 \
		proc-macro2-1.0.80 \
		quote-1.0.36 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		regex-1.10.5 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.3 \
		ryu-1.0.17 \
		same-file-1.0.6 \
		serde-1.0.197 \
		serde_derive-1.0.197 \
		serde_json-1.0.116 \
		serde_spanned-0.6.5 \
		strsim-0.10.0 \
		syn-2.0.59 \
		termcolor-1.4.1 \
		textwrap-0.16.1 \
		thiserror-1.0.58 \
		thiserror-impl-1.0.58 \
		toml-0.8.12 \
		toml_datetime-0.6.5 \
		toml_edit-0.22.12 \
		unicode-ident-1.0.12 \
		walkdir-2.5.0 \
		wasm-bindgen-0.2.92 \
		wasm-bindgen-backend-0.2.92 \
		wasm-bindgen-macro-0.2.92 \
		wasm-bindgen-macro-support-0.2.92 \
		wasm-bindgen-shared-0.2.92 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-core-0.52.0 \
		windows-sys-0.52.0 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.52.5 \
		winnow-0.6.6

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
