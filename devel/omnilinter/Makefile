PORTNAME=	omnilinter
PORTVERSION=	0.7.1
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	General purpose bulk linter
WWW=		https://github.com/AMDmi3/omnilinter

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3

CARGO_CRATES=	aho-corasick-1.1.4 \
		alloca-0.4.0 \
		anes-0.1.6 \
		anstream-0.6.21 \
		anstyle-1.0.13 \
		anstyle-parse-0.2.7 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		anyhow-1.0.102 \
		assert_cmd-2.1.2 \
		autocfg-1.5.0 \
		bitflags-2.10.0 \
		block-buffer-0.10.4 \
		bstr-1.12.1 \
		byteorder-1.5.0 \
		cast-0.3.0 \
		cc-1.2.52 \
		cfg-if-1.0.4 \
		ciborium-0.2.2 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		clap-4.5.60 \
		clap_builder-4.5.60 \
		clap_derive-4.5.55 \
		clap_lex-1.0.0 \
		colorchoice-1.0.4 \
		colored-3.1.1 \
		cpufeatures-0.2.17 \
		criterion-0.8.2 \
		criterion-plot-0.8.2 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		crunchy-0.2.4 \
		crypto-common-0.1.7 \
		diff-0.1.13 \
		difflib-0.4.0 \
		digest-0.10.7 \
		directories-6.0.0 \
		dirs-sys-0.5.0 \
		either-1.15.0 \
		errno-0.3.14 \
		fastrand-2.3.0 \
		find-msvc-tools-0.1.7 \
		fxhash-0.2.1 \
		generic-array-0.14.7 \
		getrandom-0.2.17 \
		getrandom-0.3.4 \
		glob-0.3.3 \
		half-2.7.1 \
		heck-0.5.0 \
		is_terminal_polyfill-1.70.2 \
		itertools-0.13.0 \
		itoa-1.0.17 \
		libc-0.2.180 \
		libredox-0.1.12 \
		linux-raw-sys-0.11.0 \
		memchr-2.7.6 \
		num-traits-0.2.19 \
		once_cell-1.21.3 \
		once_cell_polyfill-1.70.2 \
		oorandom-11.1.5 \
		option-ext-0.2.0 \
		page_size-0.6.0 \
		pest-2.8.5 \
		pest_derive-2.8.5 \
		pest_generator-2.8.5 \
		pest_meta-2.8.5 \
		predicates-3.1.3 \
		predicates-core-1.0.9 \
		predicates-tree-1.0.12 \
		pretty_assertions-1.4.1 \
		proc-macro2-1.0.105 \
		quote-1.0.43 \
		r-efi-5.3.0 \
		rayon-1.11.0 \
		rayon-core-1.13.0 \
		redox_users-0.5.2 \
		regex-1.12.2 \
		regex-automata-0.4.13 \
		regex-syntax-0.8.8 \
		relative-path-1.9.3 \
		rstest-0.26.1 \
		rstest_macros-0.26.1 \
		rustc_version-0.4.1 \
		rustix-1.1.3 \
		same-file-1.0.6 \
		semver-1.0.27 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		sha2-0.10.9 \
		shlex-1.3.0 \
		strsim-0.11.1 \
		syn-2.0.114 \
		tempfile-3.25.0 \
		termtree-0.5.1 \
		thiserror-2.0.17 \
		thiserror-impl-2.0.17 \
		tinytemplate-1.2.1 \
		typenum-1.19.0 \
		ucd-trie-0.1.7 \
		unicode-ident-1.0.22 \
		utf8parse-0.2.2 \
		version_check-0.9.5 \
		wait-timeout-0.2.1 \
		walkdir-2.5.0 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasip2-1.0.1+wasi-0.2.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.11 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		wit-bindgen-0.46.0 \
		yansi-1.0.1 \
		zerocopy-0.8.33 \
		zerocopy-derive-0.8.33 \
		zmij-1.0.13

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@cd ${WRKSRC}/share && ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${MAKE_CMD} install

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
