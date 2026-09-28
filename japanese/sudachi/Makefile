PORTNAME=	sudachi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
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

CARGO_CRATES=	aho-corasick-1.1.5 \
		anes-0.1.6 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		arbitrary-1.4.2 \
		autocfg-1.0.1 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-2.13.2 \
		bumpalo-3.20.3 \
		cast-0.3.0 \
		cfg-if-1.0.5 \
		ciborium-0.2.2 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		claim-0.5.0 \
		clap-4.6.7 \
		clap_builder-4.6.7 \
		clap_derive-4.6.7 \
		clap_lex-1.1.1 \
		colorchoice-1.0.5 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-deque-0.8.8 \
		crossbeam-epoch-0.9.21 \
		crossbeam-utils-0.8.23 \
		crunchy-0.2.4 \
		csv-1.4.0 \
		csv-core-0.1.13 \
		deranged-0.5.8 \
		either-1.18.0 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		fancy-regex-0.13.0 \
		fastrand-2.5.0 \
		futures-core-0.3.34 \
		futures-task-0.3.34 \
		futures-util-0.3.34 \
		getrandom-0.4.3 \
		half-2.7.1 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		hermit-abi-0.5.3 \
		honggfuzz-0.5.62 \
		indexmap-2.14.2 \
		is-terminal-0.4.17 \
		is_terminal_polyfill-1.70.2 \
		itertools-0.10.5 \
		itertools-0.13.0 \
		itoa-1.0.18 \
		js-sys-0.3.105 \
		lazy_static-1.5.0 \
		libc-0.2.189 \
		libloading-0.8.9 \
		linux-raw-sys-0.12.1 \
		memchr-2.8.3 \
		memmap2-0.9.11 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-conv-0.2.2 \
		num-traits-0.2.19 \
		once_cell-1.21.4 \
		once_cell_polyfill-1.70.2 \
		oorandom-11.1.5 \
		pin-project-lite-0.2.17 \
		plotters-0.3.7 \
		plotters-backend-0.3.7 \
		plotters-svg-0.3.7 \
		portable-atomic-1.15.0 \
		powerfmt-0.2.0 \
		proc-macro2-1.0.107 \
		pyo3-0.29.2 \
		pyo3-build-config-0.29.2 \
		pyo3-ffi-0.29.2 \
		pyo3-macros-0.29.2 \
		pyo3-macros-backend-0.29.2 \
		quote-1.0.47 \
		r-efi-6.0.0 \
		rayon-1.12.0 \
		rayon-core-1.13.0 \
		regex-1.13.1 \
		regex-automata-0.4.18 \
		regex-syntax-0.8.11 \
		rustc_version-0.4.1 \
		rustix-1.1.5 \
		rustversion-1.0.23 \
		ryu-1.0.23 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		semver-1.0.28 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		serde_json-1.0.151 \
		slab-0.4.12 \
		strsim-0.11.1 \
		syn-2.0.119 \
		syn-3.0.6 \
		target-lexicon-0.13.5 \
		tempfile-3.27.0 \
		thiserror-1.0.69 \
		thiserror-impl-1.0.69 \
		thread_local-1.1.10 \
		time-0.3.55 \
		time-core-0.1.9 \
		time-macros-0.2.32 \
		tinytemplate-1.2.1 \
		tinyvec-1.13.3 \
		unicode-ident-1.0.26 \
		unicode-normalization-0.1.25 \
		utf8parse-0.2.2 \
		walkdir-2.5.0 \
		wasm-bindgen-0.2.128 \
		wasm-bindgen-macro-0.2.128 \
		wasm-bindgen-macro-support-0.2.128 \
		wasm-bindgen-shared-0.2.128 \
		web-sys-0.3.105 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		yada-0.5.1 \
		zerocopy-0.8.57 \
		zerocopy-derive-0.8.57 \
		zmij-1.0.23

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
