PORTNAME=	omnilinter
PORTVERSION=	0.7.0
PORTREVISION=	12
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	General purpose bulk linter
WWW=		https://github.com/AMDmi3/omnilinter

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3

CARGO_CRATES=	aho-corasick-1.1.3 \
		anes-0.1.6 \
		anstream-0.6.13 \
		anstyle-1.0.6 \
		anstyle-parse-0.2.3 \
		anstyle-query-1.0.2 \
		anstyle-wincon-3.0.2 \
		anyhow-1.0.81 \
		assert_cmd-2.0.14 \
		autocfg-1.2.0 \
		bitflags-1.3.2 \
		bitflags-2.5.0 \
		block-buffer-0.10.4 \
		bstr-1.9.1 \
		byteorder-1.5.0 \
		cast-0.3.0 \
		cfg-if-1.0.0 \
		ciborium-0.2.2 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		clap-4.5.4 \
		clap_builder-4.5.2 \
		clap_derive-4.5.4 \
		clap_lex-0.7.0 \
		colorchoice-1.0.0 \
		colored-2.1.0 \
		cpufeatures-0.2.12 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.19 \
		crunchy-0.2.2 \
		crypto-common-0.1.6 \
		diff-0.1.13 \
		difflib-0.4.0 \
		digest-0.10.7 \
		directories-5.0.1 \
		dirs-sys-0.4.1 \
		doc-comment-0.3.3 \
		either-1.10.0 \
		errno-0.3.8 \
		fastrand-2.0.2 \
		fxhash-0.2.1 \
		generic-array-0.14.7 \
		getrandom-0.2.12 \
		glob-0.3.1 \
		half-2.4.0 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		is-terminal-0.4.12 \
		itertools-0.10.5 \
		itoa-1.0.11 \
		lazy_static-1.4.0 \
		libc-0.2.153 \
		libredox-0.0.1 \
		linux-raw-sys-0.4.13 \
		memchr-2.7.2 \
		num-traits-0.2.18 \
		once_cell-1.19.0 \
		oorandom-11.1.3 \
		option-ext-0.2.0 \
		pest-2.7.8 \
		pest_derive-2.7.8 \
		pest_generator-2.7.8 \
		pest_meta-2.7.8 \
		predicates-3.1.0 \
		predicates-core-1.0.6 \
		predicates-tree-1.0.9 \
		pretty_assertions-1.4.0 \
		proc-macro2-1.0.79 \
		quote-1.0.35 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		redox_syscall-0.4.1 \
		redox_users-0.4.4 \
		regex-1.10.4 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.3 \
		relative-path-1.9.2 \
		rstest-0.18.2 \
		rstest_macros-0.18.2 \
		rustc_version-0.4.0 \
		rustix-0.38.32 \
		ryu-1.0.17 \
		same-file-1.0.6 \
		semver-1.0.22 \
		serde-1.0.197 \
		serde_derive-1.0.197 \
		serde_json-1.0.115 \
		sha2-0.10.8 \
		strsim-0.11.0 \
		syn-2.0.55 \
		tempfile-3.10.1 \
		termtree-0.4.1 \
		thiserror-1.0.58 \
		thiserror-impl-1.0.58 \
		tinytemplate-1.2.1 \
		typenum-1.17.0 \
		ucd-trie-0.1.6 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.4 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.4 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.4 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.4 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.4 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.4 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.4 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.4 \
		yansi-0.5.1

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@cd ${WRKSRC}/share && ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${MAKE_CMD} install

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
