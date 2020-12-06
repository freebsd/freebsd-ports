# $FreeBSD$

PORTNAME=	grex
DISTVERSIONPREFIX=v
DISTVERSION=	1.1.0
CATEGORIES=	devel

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Command-line tool for generating regular expressions from test cases

LICENSE=	APACHE20

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	pemistahl

CARGO_CRATES=	aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		assert_cmd-1.0.1 \
		atty-0.2.14 \
		autocfg-0.1.7 \
		autocfg-1.0.0 \
		bit-set-0.5.1 \
		bit-vec-0.5.1 \
		bitflags-1.2.1 \
		byteorder-1.3.4 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		colored-1.9.3 \
		difference-2.0.0 \
		doc-comment-0.3.3 \
		either-1.5.3 \
		fixedbitset-0.2.0 \
		float-cmp-0.6.0 \
		fnv-1.0.6 \
		fuchsia-cprng-0.1.1 \
		getrandom-0.1.14 \
		heck-0.3.1 \
		hermit-abi-0.1.11 \
		indexmap-1.3.2 \
		itertools-0.8.2 \
		itertools-0.9.0 \
		lazy_static-1.4.0 \
		libc-0.2.69 \
		matches-0.1.8 \
		matrixmultiply-0.2.3 \
		memchr-2.3.3 \
		ndarray-0.13.0 \
		normalize-line-endings-0.3.0 \
		num-complex-0.2.4 \
		num-integer-0.1.42 \
		num-traits-0.2.11 \
		petgraph-0.5.0 \
		ppv-lite86-0.2.6 \
		predicates-1.0.4 \
		predicates-core-1.0.0 \
		predicates-tree-1.0.0 \
		proc-macro-error-1.0.2 \
		proc-macro-error-attr-1.0.2 \
		proc-macro2-1.0.10 \
		proptest-0.9.6 \
		quick-error-1.2.3 \
		quote-1.0.3 \
		rand-0.6.5 \
		rand-0.7.3 \
		rand_chacha-0.1.1 \
		rand_chacha-0.2.2 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.5.1 \
		rand_hc-0.1.0 \
		rand_hc-0.2.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rawpointer-0.2.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		regex-1.3.6 \
		regex-syntax-0.6.17 \
		remove_dir_all-0.5.2 \
		rstest-0.6.2 \
		rustc_version-0.2.3 \
		rusty-fork-0.2.2 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		strsim-0.8.0 \
		structopt-0.3.13 \
		structopt-derive-0.4.6 \
		syn-1.0.17 \
		syn-mid-0.5.0 \
		tempfile-3.1.0 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		treeline-0.1.0 \
		unic-char-property-0.9.0 \
		unic-char-range-0.9.0 \
		unic-common-0.9.0 \
		unic-ucd-category-0.9.0 \
		unic-ucd-version-0.9.0 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		version_check-0.9.1 \
		wait-timeout-0.2.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

OPTIONS_DEFINE=	DOCS
PORTDOCS=	RELEASE_NOTES.md README.md

PLIST_FILES=	bin/grex

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/grex
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
