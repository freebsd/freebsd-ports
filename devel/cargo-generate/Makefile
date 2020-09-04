# $FreeBSD$

PORTNAME=	cargo-generate
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
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

CARGO_CRATES=	adler32-1.0.4 \
		aho-corasick-0.6.10 \
		aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		anymap-0.12.1 \
		arrayvec-0.4.12 \
		assert_cmd-0.4.0 \
		atty-0.2.13 \
		autocfg-0.1.7 \
		backtrace-0.3.40 \
		backtrace-sys-0.1.32 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-padding-0.1.4 \
		bstr-0.2.8 \
		byte-tools-0.3.1 \
		byteorder-1.3.2 \
		c2-chacha-0.2.3 \
		cargo-0.30.0 \
		cc-1.0.46 \
		cfg-if-0.1.10 \
		chrono-0.4.9 \
		clap-2.33.0 \
		clap-verbosity-flag-0.2.0 \
		clicolors-control-0.2.0 \
		clicolors-control-1.0.1 \
		cloudabi-0.0.3 \
		commoncrypto-0.2.0 \
		commoncrypto-sys-0.2.0 \
		console-0.6.2 \
		console-0.9.0 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.6.2 \
		crates-io-0.18.0 \
		crc32fast-1.2.0 \
		crossbeam-channel-0.3.9 \
		crossbeam-deque-0.7.1 \
		crossbeam-epoch-0.7.2 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.5.0 \
		crossbeam-utils-0.6.6 \
		crypto-hash-0.3.4 \
		curl-0.4.25 \
		curl-sys-0.4.23 \
		deunicode-1.0.0 \
		dialoguer-0.1.0 \
		difference-2.0.0 \
		digest-0.8.1 \
		doc-comment-0.3.1 \
		either-1.5.3 \
		encode_unicode-0.3.6 \
		env_logger-0.5.13 \
		escargot-0.2.0 \
		exitfailure-0.5.1 \
		failure-0.1.6 \
		failure_derive-0.1.6 \
		fake-simd-0.1.2 \
		filetime-0.2.7 \
		flate2-1.0.12 \
		float-cmp-0.4.0 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fs2-0.4.3 \
		fuchsia-cprng-0.1.1 \
		generic-array-0.12.3 \
		getrandom-0.1.12 \
		git2-0.7.5 \
		git2-curl-0.8.2 \
		glob-0.2.11 \
		globset-0.4.4 \
		globwalk-0.3.1 \
		heck-0.3.1 \
		hex-0.3.2 \
		home-0.3.4 \
		humantime-1.3.0 \
		idna-0.1.5 \
		ignore-0.4.10 \
		indicatif-0.9.0 \
		itertools-0.8.0 \
		itoa-0.4.4 \
		jobserver-0.1.17 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.4.0 \
		lazycell-1.2.1 \
		libc-0.2.65 \
		libgit2-sys-0.7.11 \
		libssh2-sys-0.2.13 \
		libz-sys-1.0.25 \
		liquid-0.19.0 \
		liquid-compiler-0.19.0 \
		liquid-derive-0.19.0 \
		liquid-error-0.19.0 \
		liquid-interpreter-0.19.0 \
		liquid-value-0.19.0 \
		lock_api-0.3.1 \
		log-0.4.8 \
		maplit-1.0.2 \
		matches-0.1.8 \
		memchr-2.2.1 \
		memoffset-0.5.1 \
		miniz_oxide-0.3.3 \
		miow-0.3.3 \
		nodrop-0.1.14 \
		num-integer-0.1.41 \
		num-traits-0.2.8 \
		num_cpus-1.10.1 \
		opaque-debug-0.2.3 \
		openssl-0.10.25 \
		openssl-probe-0.1.2 \
		openssl-src-111.6.0+1.1.1d \
		openssl-sys-0.9.52 \
		parking_lot-0.9.0 \
		parking_lot_core-0.6.2 \
		percent-encoding-1.0.1 \
		pest-2.1.2 \
		pest_derive-2.1.0 \
		pest_generator-2.1.1 \
		pest_meta-2.1.2 \
		pkg-config-0.3.16 \
		ppv-lite86-0.2.6 \
		predicates-0.5.2 \
		proc-macro-hack-0.5.11 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.6 \
		proc-quote-0.2.2 \
		proc-quote-impl-0.2.2 \
		quick-error-1.2.2 \
		quicli-0.4.0 \
		quote-0.6.13 \
		quote-1.0.2 \
		rand-0.3.23 \
		rand-0.4.6 \
		rand-0.7.2 \
		rand_chacha-0.2.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rayon-1.2.0 \
		rayon-core-1.6.0 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		regex-0.2.11 \
		regex-1.3.1 \
		regex-syntax-0.5.6 \
		regex-syntax-0.6.12 \
		remove_dir_all-0.5.2 \
		rustc-demangle-0.1.16 \
		rustc-workspace-hack-1.0.0 \
		rustc_version-0.2.3 \
		rustfix-0.4.6 \
		ryu-1.0.2 \
		same-file-1.0.5 \
		schannel-0.1.16 \
		scopeguard-0.3.3 \
		scopeguard-1.0.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.101 \
		serde_derive-1.0.101 \
		serde_ignored-0.0.4 \
		serde_json-1.0.41 \
		sha-1-0.8.1 \
		shell-escape-0.1.4 \
		smallvec-0.6.10 \
		socket2-0.3.11 \
		strsim-0.8.0 \
		structopt-0.2.18 \
		structopt-derive-0.2.18 \
		syn-0.15.44 \
		syn-1.0.5 \
		synstructure-0.12.1 \
		tar-0.4.26 \
		tempfile-2.2.0 \
		tempfile-3.1.0 \
		termcolor-1.0.5 \
		termios-0.3.1 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		time-0.1.42 \
		toml-0.4.10 \
		toml-0.5.3 \
		typenum-1.11.2 \
		ucd-trie-0.1.2 \
		ucd-util-0.1.5 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-segmentation-1.3.0 \
		unicode-width-0.1.6 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		url-1.7.2 \
		utf8-ranges-1.0.4 \
		vcpkg-0.2.7 \
		vec_map-0.8.1 \
		walkdir-2.2.9 \
		wasi-0.7.0 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.2

PORTDOCS=	CHANGELOG.md CODE_OF_CONDUCT.md CONTRIBUTING.md README.md \
		TEMPLATES.md
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
