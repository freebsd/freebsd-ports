PORTNAME=	grex
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Command-line tool for generating regular expressions from test cases

LICENSE=	APACHE20

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	pemistahl

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		assert_cmd-2.0.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bit-set-0.5.2 \
		bit-vec-0.6.3 \
		bitflags-1.2.1 \
		bstr-0.2.15 \
		byteorder-1.3.4 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		fixedbitset-0.4.0 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		getrandom-0.2.2 \
		hashbrown-0.11.2 \
		heck-0.3.2 \
		hermit-abi-0.1.17 \
		indexmap-1.7.0 \
		indoc-1.0.3 \
		itertools-0.10.1 \
		lazy_static-1.4.0 \
		libc-0.2.81 \
		matches-0.1.8 \
		matrixmultiply-0.3.0 \
		memchr-2.4.0 \
		ndarray-0.15.3 \
		normalize-line-endings-0.3.0 \
		num-complex-0.4.0 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		petgraph-0.6.0 \
		ppv-lite86-0.2.10 \
		predicates-2.0.2 \
		predicates-core-1.0.1 \
		predicates-tree-1.0.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.27 \
		proptest-1.0.0 \
		quick-error-1.2.3 \
		quick-error-2.0.0 \
		quote-1.0.9 \
		rand-0.8.3 \
		rand_chacha-0.3.0 \
		rand_core-0.6.2 \
		rand_hc-0.3.0 \
		rand_xorshift-0.3.0 \
		rawpointer-0.2.1 \
		redox_syscall-0.2.5 \
		regex-1.5.4 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rstest-0.11.0 \
		rustc_version-0.4.0 \
		rusty-fork-0.3.0 \
		semver-1.0.4 \
		strsim-0.8.0 \
		structopt-0.3.23 \
		structopt-derive-0.4.16 \
		syn-1.0.73 \
		tempfile-3.2.0 \
		textwrap-0.11.0 \
		treeline-0.1.0 \
		unic-char-property-0.9.0 \
		unic-char-range-0.9.0 \
		unic-common-0.9.0 \
		unic-ucd-category-0.9.0 \
		unic-ucd-version-0.9.0 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		unindent-0.1.7 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		wait-timeout-0.2.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/grex

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README.md RELEASE_NOTES.md

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/grex
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
