PORTNAME=	sudachi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.10
PORTREVISION=	6
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

CARGO_CRATES=	aho-corasick-1.1.3 \
		anes-0.1.6 \
		anstream-0.6.14 \
		anstyle-1.0.7 \
		anstyle-parse-0.2.4 \
		anstyle-query-1.1.0 \
		anstyle-wincon-3.0.3 \
		arbitrary-1.3.2 \
		autocfg-1.0.1 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-2.5.0 \
		bumpalo-3.16.0 \
		cast-0.3.0 \
		cfg-if-1.0.0 \
		ciborium-0.2.2 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		claim-0.5.0 \
		clap-4.5.4 \
		clap_builder-4.5.2 \
		clap_derive-4.5.4 \
		clap_lex-0.7.0 \
		colorchoice-1.0.1 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.20 \
		crunchy-0.2.2 \
		csv-1.3.0 \
		csv-core-0.1.11 \
		either-1.12.0 \
		equivalent-1.0.1 \
		errno-0.3.9 \
		fancy-regex-0.13.0 \
		fastrand-2.1.0 \
		half-2.4.1 \
		hashbrown-0.14.5 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		honggfuzz-0.5.56 \
		indexmap-2.2.6 \
		indoc-2.0.5 \
		is-terminal-0.4.12 \
		is_terminal_polyfill-1.70.0 \
		itertools-0.10.5 \
		itertools-0.13.0 \
		itoa-1.0.11 \
		js-sys-0.3.69 \
		lazy_static-1.4.0 \
		libc-0.2.155 \
		libloading-0.8.3 \
		linux-raw-sys-0.4.14 \
		log-0.4.21 \
		memchr-2.7.2 \
		memmap2-0.9.4 \
		memoffset-0.9.1 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-traits-0.2.19 \
		once_cell-1.19.0 \
		oorandom-11.1.3 \
		plotters-0.3.6 \
		plotters-backend-0.3.6 \
		plotters-svg-0.3.6 \
		portable-atomic-1.6.0 \
		proc-macro2-1.0.85 \
		pyo3-0.23.0 \
		pyo3-build-config-0.23.0 \
		pyo3-ffi-0.23.0 \
		pyo3-macros-0.23.0 \
		pyo3-macros-backend-0.23.0 \
		quote-1.0.36 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		regex-1.10.4 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.3 \
		rustc_version-0.4.0 \
		rustix-0.38.34 \
		ryu-1.0.18 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		semver-1.0.23 \
		serde-1.0.203 \
		serde_derive-1.0.203 \
		serde_json-1.0.117 \
		strsim-0.11.1 \
		syn-2.0.66 \
		target-lexicon-0.12.14 \
		tempfile-3.10.1 \
		thiserror-1.0.61 \
		thiserror-impl-1.0.61 \
		thread_local-1.1.8 \
		tinytemplate-1.2.1 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.23 \
		unindent-0.2.3 \
		utf8parse-0.2.1 \
		walkdir-2.5.0 \
		wasm-bindgen-0.2.92 \
		wasm-bindgen-backend-0.2.92 \
		wasm-bindgen-macro-0.2.92 \
		wasm-bindgen-macro-support-0.2.92 \
		wasm-bindgen-shared-0.2.92 \
		web-sys-0.3.69 \
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
		windows_x86_64_msvc-0.52.5 \
		yada-0.5.1

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
