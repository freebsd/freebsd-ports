PORTNAME=	sudachi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.11
CATEGORIES=	japanese
MASTER_SITES=	http://sudachi.s3-website-ap-northeast-1.amazonaws.com/sudachidict/:dict
DISTFILES=	sudachi-dictionary-20220519-core.zip:dict # see ${WRKSRC}/fetch_dictionary.sh

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of Sudachi, a Japanese morphological analyzer
WWW=		https://github.com/WorksApplications/sudachi.rs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails, see https://github.com/WorksApplications/sudachi.rs/issues/271
BROKEN_i386=	compilation fails, see https://github.com/WorksApplications/sudachi.rs/issues/271
BROKEN_powerpc=	compilation fails, see https://github.com/WorksApplications/sudachi.rs/issues/271

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	WorksApplications
GH_PROJECT=	sudachi.rs

CARGO_CRATES=	aho-corasick-1.1.4 \
		anes-0.1.6 \
		anstream-0.6.21 \
		anstyle-1.0.13 \
		anstyle-parse-0.2.7 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		anyhow-1.0.102 \
		arbitrary-1.4.2 \
		autocfg-1.0.1 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-2.11.0 \
		bumpalo-3.20.2 \
		cast-0.3.0 \
		cfg-if-1.0.4 \
		ciborium-0.2.2 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		claim-0.5.0 \
		clap-4.5.60 \
		clap_builder-4.5.60 \
		clap_derive-4.5.55 \
		clap_lex-1.0.0 \
		colorchoice-1.0.4 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		crunchy-0.2.4 \
		csv-1.4.0 \
		csv-core-0.1.13 \
		either-1.15.0 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		fancy-regex-0.13.0 \
		fastrand-2.3.0 \
		foldhash-0.1.5 \
		getrandom-0.4.2 \
		half-2.7.1 \
		hashbrown-0.15.5 \
		hashbrown-0.16.1 \
		heck-0.5.0 \
		hermit-abi-0.5.2 \
		honggfuzz-0.5.58 \
		id-arena-2.3.0 \
		indexmap-2.13.0 \
		indoc-2.0.7 \
		is-terminal-0.4.17 \
		is_terminal_polyfill-1.70.2 \
		itertools-0.10.5 \
		itertools-0.13.0 \
		itoa-1.0.17 \
		js-sys-0.3.91 \
		lazy_static-1.5.0 \
		leb128fmt-0.1.0 \
		libc-0.2.182 \
		libloading-0.8.9 \
		linux-raw-sys-0.12.1 \
		log-0.4.29 \
		memchr-2.8.0 \
		memmap2-0.9.10 \
		memoffset-0.9.1 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-traits-0.2.19 \
		once_cell-1.21.3 \
		once_cell_polyfill-1.70.2 \
		oorandom-11.1.5 \
		plotters-0.3.7 \
		plotters-backend-0.3.7 \
		plotters-svg-0.3.7 \
		portable-atomic-1.13.1 \
		prettyplease-0.2.37 \
		proc-macro2-1.0.106 \
		pyo3-0.27.2 \
		pyo3-build-config-0.27.2 \
		pyo3-ffi-0.27.2 \
		pyo3-macros-0.27.2 \
		pyo3-macros-backend-0.27.2 \
		quote-1.0.45 \
		r-efi-6.0.0 \
		rayon-1.11.0 \
		rayon-core-1.13.0 \
		regex-1.12.3 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.10 \
		rustc_version-0.4.1 \
		rustix-1.1.4 \
		rustversion-1.0.22 \
		ryu-1.0.23 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		semver-1.0.27 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		strsim-0.11.1 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		tempfile-3.26.0 \
		thiserror-1.0.69 \
		thiserror-impl-1.0.69 \
		thread_local-1.1.9 \
		tinytemplate-1.2.1 \
		tinyvec-1.10.0 \
		tinyvec_macros-0.1.1 \
		unicode-ident-1.0.24 \
		unicode-normalization-0.1.25 \
		unicode-xid-0.2.6 \
		unindent-0.2.4 \
		utf8parse-0.2.2 \
		walkdir-2.5.0 \
		wasip2-1.0.2+wasi-0.2.9 \
		wasip3-0.4.0+wasi-0.3.0-rc-2026-01-06 \
		wasm-bindgen-0.2.114 \
		wasm-bindgen-macro-0.2.114 \
		wasm-bindgen-macro-support-0.2.114 \
		wasm-bindgen-shared-0.2.114 \
		wasm-encoder-0.244.0 \
		wasm-metadata-0.244.0 \
		wasmparser-0.244.0 \
		web-sys-0.3.91 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		wit-bindgen-0.51.0 \
		wit-bindgen-core-0.51.0 \
		wit-bindgen-rust-0.51.0 \
		wit-bindgen-rust-macro-0.51.0 \
		wit-component-0.244.0 \
		wit-parser-0.244.0 \
		yada-0.5.1 \
		zerocopy-0.8.40 \
		zerocopy-derive-0.8.40 \
		zmij-1.0.21

post-patch:
	@${REINPLACE_CMD} \
		-e 's|const DEFAULT_RESOURCE_DIR: &str = "resources";|const DEFAULT_RESOURCE_DIR: \&str = "${DATADIR}/resources";|' \
		${WRKSRC}/sudachi/src/config.rs

do-install:
	# install binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	# install the resources directory
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} resources ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} \
		${WRKDIR}/sudachi-dictionary-20220519/system_core.dic \
		${STAGEDIR}${DATADIR}/resources/system.dic
	@${RM} ${STAGEDIR}${DATADIR}/resources/.gitkeep

.include <bsd.port.mk>
