PORTNAME=	cargo-generate
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1
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

USES=		cargo localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ashleygwilliams

CARGO_CRATES=	addr2line-0.17.0 \
		adler-1.0.2 \
		ahash-0.7.6 \
		aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		anyhow-1.0.56 \
		anymap2-0.13.0 \
		assert_cmd-2.0.4 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		backtrace-0.3.64 \
		bitflags-1.3.2 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		bstr-0.2.17 \
		byte-tools-0.3.1 \
		byteorder-1.4.3 \
		cargo-husky-1.5.0 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		console-0.15.0 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		dialoguer-0.10.0 \
		difflib-0.4.0 \
		digest-0.8.1 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		encode_unicode-0.3.6 \
		failure-0.1.8 \
		failure_derive-0.1.8 \
		fake-simd-0.1.2 \
		fastrand-1.7.0 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.1 \
		generic-array-0.12.4 \
		getrandom-0.2.6 \
		gimli-0.26.1 \
		git-config-0.2.1 \
		git-features-0.20.0 \
		git-hash-0.9.3 \
		git2-0.14.2 \
		globset-0.4.8 \
		heck-0.3.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		home-0.5.3 \
		idna-0.2.3 \
		ignore-0.4.18 \
		indicatif-0.16.2 \
		indoc-1.0.4 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-1.0.1 \
		jobserver-0.1.24 \
		kstring-2.0.0 \
		lazy_static-1.4.0 \
		libc-0.2.122 \
		libgit2-sys-0.13.2+1.4.2 \
		libssh2-sys-0.2.23 \
		libz-sys-1.1.5 \
		liquid-0.26.0 \
		liquid-core-0.26.0 \
		liquid-derive-0.26.0 \
		liquid-lib-0.26.0 \
		log-0.4.16 \
		maplit-1.0.2 \
		matches-0.1.9 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.4.4 \
		nom-7.1.1 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		num_threads-0.1.5 \
		number_prefix-0.4.0 \
		object-0.27.1 \
		once_cell-1.10.0 \
		opaque-debug-0.2.3 \
		openssl-0.10.38 \
		openssl-probe-0.1.5 \
		openssl-src-111.18.0+1.1.1n \
		openssl-sys-0.9.72 \
		path-absolutize-3.0.13 \
		path-dedot-3.0.17 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		pkg-config-0.3.25 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.37 \
		proc-quote-0.4.0 \
		proc-quote-impl-0.3.2 \
		pwd-1.3.1 \
		quick-error-2.0.1 \
		quote-1.0.18 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.13 \
		redox_users-0.4.3 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		remove_dir_all-0.7.0 \
		rhai-1.6.1 \
		rhai_codegen-1.4.0 \
		rustc-demangle-0.1.21 \
		same-file-1.0.6 \
		sanitize-filename-0.3.0 \
		scopeguard-1.1.0 \
		semver-1.0.7 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		sha-1-0.8.2 \
		smallvec-1.8.0 \
		smartstring-1.0.1 \
		static_assertions-1.1.0 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		syn-1.0.91 \
		synstructure-0.12.6 \
		tempfile-3.3.0 \
		terminal_size-0.1.17 \
		termtree-0.2.4 \
		textwrap-0.11.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		thread_local-1.1.4 \
		time-0.3.9 \
		time-macros-0.2.4 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		toml-0.5.8 \
		typenum-1.15.0 \
		ucd-trie-0.1.3 \
		unicode-bidi-0.3.7 \
		unicode-bom-1.1.4 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		unindent-0.1.8 \
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
		zeroize-1.5.4

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
