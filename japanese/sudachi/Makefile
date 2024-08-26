PORTNAME=	sudachi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.8
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://sudachi.s3-website-ap-northeast-1.amazonaws.com/sudachidict/:dict
DISTFILES=	sudachi-dictionary-20220519-core.zip:dict # see ${WRKSRC}/fetch_dictionary.sh

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of Sudachi, a Japanese morphological analyzer
WWW=		https://github.com/WorksApplications/sudachi.rs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails, see https://github.com/WorksApplications/sudachi.rs/issues/271

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	WorksApplications
GH_PROJECT=	sudachi.rs

CARGO_CRATES=	aho-corasick-1.1.2 \
		anes-0.1.6 \
		ansi_term-0.12.1 \
		anstyle-1.0.4 \
		arbitrary-1.3.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		bumpalo-3.14.0 \
		cast-0.3.0 \
		cfg-if-1.0.0 \
		ciborium-0.2.1 \
		ciborium-io-0.2.1 \
		ciborium-ll-0.2.1 \
		claim-0.5.0 \
		clap-2.34.0 \
		clap-4.4.11 \
		clap_builder-4.4.11 \
		clap_lex-0.6.0 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-deque-0.8.3 \
		crossbeam-epoch-0.9.15 \
		crossbeam-utils-0.8.16 \
		csv-1.3.0 \
		csv-core-0.1.11 \
		either-1.9.0 \
		equivalent-1.0.1 \
		errno-0.3.8 \
		fancy-regex-0.12.0 \
		fastrand-2.0.1 \
		half-1.8.2 \
		hashbrown-0.14.3 \
		heck-0.3.3 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		hermit-abi-0.3.3 \
		honggfuzz-0.5.55 \
		indexmap-2.1.0 \
		indoc-2.0.4 \
		is-terminal-0.4.9 \
		itertools-0.10.5 \
		itertools-0.12.0 \
		itoa-1.0.10 \
		js-sys-0.3.66 \
		lazy_static-1.4.0 \
		libc-0.2.151 \
		libloading-0.8.1 \
		linux-raw-sys-0.4.12 \
		lock_api-0.4.6 \
		log-0.4.20 \
		memchr-2.6.4 \
		memmap2-0.5.10 \
		memmap2-0.7.1 \
		memmap2-0.9.0 \
		memoffset-0.9.0 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-traits-0.2.17 \
		once_cell-1.19.0 \
		oorandom-11.1.3 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		plotters-0.3.5 \
		plotters-backend-0.3.5 \
		plotters-svg-0.3.5 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.70 \
		pyo3-0.20.0 \
		pyo3-build-config-0.20.0 \
		pyo3-ffi-0.20.0 \
		pyo3-macros-0.20.0 \
		pyo3-macros-backend-0.20.0 \
		quote-1.0.33 \
		rayon-1.8.0 \
		rayon-core-1.12.0 \
		redox_syscall-0.4.1 \
		regex-1.10.2 \
		regex-automata-0.4.3 \
		regex-syntax-0.8.2 \
		rustc_version-0.4.0 \
		rustix-0.38.28 \
		ryu-1.0.16 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		semver-1.0.20 \
		serde-1.0.193 \
		serde_derive-1.0.193 \
		serde_json-1.0.108 \
		smallvec-1.11.2 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		syn-1.0.109 \
		syn-2.0.41 \
		target-lexicon-0.12.12 \
		tempfile-3.8.1 \
		textwrap-0.11.0 \
		thiserror-1.0.50 \
		thiserror-impl-1.0.50 \
		thread_local-1.1.7 \
		tinytemplate-1.2.1 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.22 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.11 \
		unindent-0.2.3 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		walkdir-2.4.0 \
		wasm-bindgen-0.2.89 \
		wasm-bindgen-backend-0.2.89 \
		wasm-bindgen-macro-0.2.89 \
		wasm-bindgen-macro-support-0.2.89 \
		wasm-bindgen-shared-0.2.89 \
		web-sys-0.3.66 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.0 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.0 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.0 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.0 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.0 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.0 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.0 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.0 \
		yada-0.5.0

post-patch:
	@${REINPLACE_CMD} \
		-e 's|const DEFAULT_RESOURCE_DIR: &str = "resources";|const DEFAULT_RESOURCE_DIR: \&str = "${DATADIR}/resources";|' \
		${WRKSRC}/sudachi/src/config.rs

do-install:
	# install binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/*/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	# install the resources directory
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} resources ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} \
		${WRKDIR}/sudachi-dictionary-20220519/system_core.dic \
		${STAGEDIR}${DATADIR}/resources/system.dic
	@${RM} ${STAGEDIR}${DATADIR}/resources/.gitkeep

.include <bsd.port.mk>
