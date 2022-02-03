PORTNAME=	cargo-generate
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Quickly generate Rust project templates from existing git repositories

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ashleygwilliams

CARGO_CRATES=	ahash-0.7.6 \
		aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		anyhow-1.0.52 \
		anymap2-0.13.0 \
		assert_cmd-2.0.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		bstr-0.2.17 \
		byte-tools-0.3.1 \
		byteorder-1.4.3 \
		cargo-husky-1.5.0 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.34.0 \
		console-0.15.0 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.5 \
		crossbeam-utils-0.8.5 \
		dialoguer-0.9.0 \
		difflib-0.4.0 \
		digest-0.8.1 \
		dirs-4.0.0 \
		dirs-sys-0.3.6 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		encode_unicode-0.3.6 \
		fake-simd-0.1.2 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.1 \
		generic-array-0.12.4 \
		getrandom-0.2.3 \
		git2-0.13.25 \
		globset-0.4.8 \
		heck-0.3.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		home-0.5.3 \
		idna-0.2.3 \
		ignore-0.4.18 \
		indicatif-0.16.2 \
		indoc-1.0.3 \
		instant-0.1.12 \
		itertools-0.10.3 \
		jobserver-0.1.24 \
		kstring-1.0.6 \
		lazy_static-1.4.0 \
		libc-0.2.112 \
		libgit2-sys-0.12.26+1.3.0 \
		libssh2-sys-0.2.23 \
		libz-sys-1.1.3 \
		liquid-0.23.1 \
		liquid-core-0.23.2 \
		liquid-derive-0.23.1 \
		liquid-lib-0.23.1 \
		log-0.4.14 \
		maplit-1.0.2 \
		matches-0.1.9 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		normalize-line-endings-0.3.0 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		number_prefix-0.4.0 \
		once_cell-1.9.0 \
		opaque-debug-0.2.3 \
		openssl-0.10.38 \
		openssl-probe-0.1.4 \
		openssl-sys-0.9.72 \
		path-absolutize-3.0.11 \
		path-dedot-3.0.14 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		pkg-config-0.3.24 \
		ppv-lite86-0.2.16 \
		predicates-2.1.0 \
		predicates-core-1.0.2 \
		predicates-tree-1.0.4 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.36 \
		proc-quote-0.4.0 \
		proc-quote-impl-0.3.2 \
		quote-1.0.14 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		remove_dir_all-0.7.0 \
		rhai-1.3.0 \
		rhai_codegen-1.2.0 \
		same-file-1.0.6 \
		sanitize-filename-0.3.0 \
		scopeguard-1.1.0 \
		semver-1.0.4 \
		serde-1.0.133 \
		serde_derive-1.0.133 \
		sha-1-0.8.2 \
		smallvec-1.7.0 \
		smartstring-0.2.9 \
		static_assertions-1.1.0 \
		strsim-0.8.0 \
		structopt-0.3.25 \
		structopt-derive-0.4.18 \
		syn-1.0.84 \
		tempfile-3.2.0 \
		terminal_size-0.1.17 \
		termtree-0.2.3 \
		textwrap-0.11.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		thread_local-1.1.3 \
		time-0.1.43 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		toml-0.5.8 \
		typenum-1.15.0 \
		ucd-trie-0.1.3 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		unindent-0.1.7 \
		url-2.2.2 \
		vcpkg-0.2.15 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		zeroize-1.4.3

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md CODE_OF_CONDUCT.md CONTRIBUTING.md README.md \
		TEMPLATES.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
