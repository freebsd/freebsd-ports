# $FreeBSD$

PORTNAME=	cargo-generate
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	vulcan@wired.sh
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

CARGO_CRATES=	adler-0.2.3 \
		aho-corasick-0.7.13 \
		ansi_term-0.11.0 \
		anyhow-1.0.32 \
		anymap-0.12.1 \
		assert_cmd-1.0.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bitmaps-2.1.0 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		bstr-0.2.13 \
		byte-tools-0.3.1 \
		byteorder-1.3.4 \
		bytesize-1.0.1 \
		cargo-0.46.1 \
		cargo-platform-0.1.1 \
		cc-1.0.59 \
		cfg-if-0.1.10 \
		chrono-0.4.15 \
		clap-2.33.3 \
		commoncrypto-0.2.0 \
		commoncrypto-sys-0.2.0 \
		console-0.11.3 \
		console-0.12.0 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.7.0 \
		crates-io-0.31.1 \
		crc32fast-1.2.0 \
		crossbeam-utils-0.7.2 \
		crypto-hash-0.3.4 \
		curl-0.4.33 \
		curl-sys-0.4.36+curl-7.71.1 \
		dialoguer-0.6.2 \
		difference-2.0.0 \
		digest-0.8.1 \
		doc-comment-0.3.3 \
		either-1.6.0 \
		encode_unicode-0.3.6 \
		env_logger-0.7.1 \
		fake-simd-0.1.2 \
		filetime-0.2.12 \
		flate2-1.0.17 \
		float-cmp-0.8.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fwdansi-1.1.0 \
		generic-array-0.12.3 \
		getrandom-0.1.15 \
		git2-0.13.11 \
		git2-curl-0.14.1 \
		glob-0.3.0 \
		globset-0.4.5 \
		heck-0.3.1 \
		hermit-abi-0.1.15 \
		hex-0.3.2 \
		hex-0.4.2 \
		home-0.5.3 \
		humantime-1.3.0 \
		humantime-2.0.1 \
		idna-0.2.0 \
		ignore-0.4.16 \
		im-rc-15.0.0 \
		indicatif-0.15.0 \
		itertools-0.9.0 \
		itoa-0.4.6 \
		jobserver-0.1.21 \
		kstring-1.0.0 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.77 \
		libgit2-sys-0.12.13+1.0.1 \
		libnghttp2-sys-0.1.4+1.41.0 \
		libssh2-sys-0.2.19 \
		libz-sys-1.1.2 \
		liquid-0.21.4 \
		liquid-core-0.21.2 \
		liquid-derive-0.21.0 \
		liquid-lib-0.21.1 \
		log-0.4.11 \
		maplit-1.0.2 \
		matches-0.1.8 \
		memchr-2.3.3 \
		miniz_oxide-0.4.2 \
		miow-0.3.5 \
		normalize-line-endings-0.3.0 \
		num-integer-0.1.43 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		number_prefix-0.3.0 \
		once_cell-1.4.1 \
		opaque-debug-0.2.3 \
		opener-0.4.1 \
		openssl-0.10.30 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.58 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		pkg-config-0.3.18 \
		ppv-lite86-0.2.9 \
		predicates-1.0.5 \
		predicates-core-1.0.0 \
		predicates-tree-1.0.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.18 \
		proc-macro2-1.0.21 \
		proc-quote-0.3.2 \
		proc-quote-impl-0.3.2 \
		quick-error-1.2.3 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_xoshiro-0.4.0 \
		redox_syscall-0.1.57 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		remove_dir_all-0.5.3 \
		rustc-workspace-hack-1.0.0 \
		rustfix-0.5.1 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		schannel-0.1.19 \
		semver-0.10.0 \
		semver-parser-0.7.0 \
		serde-1.0.116 \
		serde_derive-1.0.116 \
		serde_ignored-0.1.2 \
		serde_json-1.0.57 \
		sha-1-0.8.2 \
		shell-escape-0.1.5 \
		sized-chunks-0.6.2 \
		socket2-0.3.15 \
		strip-ansi-escapes-0.1.0 \
		strsim-0.8.0 \
		structopt-0.3.17 \
		structopt-derive-0.4.10 \
		syn-1.0.41 \
		tar-0.4.30 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		terminal_size-0.1.13 \
		termios-0.3.2 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.44 \
		tinyvec-0.3.4 \
		toml-0.5.6 \
		treeline-0.1.0 \
		typenum-1.12.0 \
		ucd-trie-0.1.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.1.1 \
		utf8parse-0.1.1 \
		vcpkg-0.2.10 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		vte-0.3.3 \
		wait-timeout-0.2.0 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

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
