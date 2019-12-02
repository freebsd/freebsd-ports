# $FreeBSD$

PORTNAME=	spotify-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	audio

MAINTAINER=	vulcan@wired.sh
COMMENT=	Spotify for the terminal written in Rust

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo localbase:ldflags python:3.6+,build ssl:build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Rigellute
USE_XORG=	xcb

CARGO_CRATES=	adler32-1.0.4 \
		aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		arrayref-0.3.5 \
		arrayvec-0.5.1 \
		atty-0.2.13 \
		autocfg-0.1.7 \
		backtrace-0.3.40 \
		backtrace-sys-0.1.32 \
		base64-0.10.1 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.9 \
		block-0.1.6 \
		byteorder-1.3.2 \
		bytes-0.4.12 \
		c2-chacha-0.2.3 \
		cassowary-0.3.0 \
		cc-1.0.47 \
		cfg-if-0.1.10 \
		chrono-0.4.9 \
		clap-2.33.0 \
		clipboard-0.5.0 \
		clipboard-win-2.2.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.4 \
		cookie-0.12.0 \
		cookie_store-0.7.0 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.6.2 \
		crc32fast-1.2.0 \
		crossbeam-deque-0.7.2 \
		crossbeam-epoch-0.8.0 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.6 \
		crossbeam-utils-0.7.0 \
		darling-0.9.0 \
		darling_core-0.9.0 \
		darling_macro-0.9.0 \
		derive_builder-0.7.2 \
		derive_builder_core-0.5.0 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		dotenv-0.13.0 \
		dtoa-0.4.4 \
		either-1.5.3 \
		encoding_rs-0.8.20 \
		env_logger-0.6.2 \
		error-chain-0.12.1 \
		failure-0.1.6 \
		failure_derive-0.1.6 \
		flate2-1.0.13 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.29 \
		futures-cpupool-0.1.8 \
		getrandom-0.1.13 \
		h2-0.1.26 \
		hermit-abi-0.1.3 \
		http-0.1.19 \
		http-body-0.1.0 \
		httparse-1.3.4 \
		humantime-1.3.0 \
		hyper-0.12.35 \
		hyper-tls-0.3.2 \
		ident_case-1.0.1 \
		idna-0.1.5 \
		idna-0.2.0 \
		indexmap-1.3.0 \
		iovec-0.1.4 \
		itertools-0.8.1 \
		itoa-0.4.4 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.65 \
		linked-hash-map-0.5.2 \
		lock_api-0.3.1 \
		log-0.4.8 \
		malloc_buf-0.0.6 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.2.1 \
		memoffset-0.5.3 \
		mime-0.3.14 \
		mime_guess-2.0.1 \
		miniz_oxide-0.3.5 \
		mio-0.6.19 \
		miow-0.2.1 \
		native-tls-0.2.3 \
		net2-0.2.33 \
		num-integer-0.1.41 \
		num-traits-0.2.9 \
		num_cpus-1.11.1 \
		numtoa-0.1.0 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		openssl-0.10.25 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.52 \
		parking_lot-0.9.0 \
		parking_lot_core-0.6.2 \
		percent-encoding-1.0.1 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.17 \
		ppv-lite86-0.2.6 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.6 \
		publicsuffix-1.5.4 \
		quick-error-1.2.2 \
		quote-0.6.13 \
		quote-1.0.2 \
		rand-0.6.5 \
		rand-0.7.2 \
		rand_chacha-0.1.1 \
		rand_chacha-0.2.1 \
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
		random-0.12.2 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		redox_users-0.3.1 \
		regex-1.3.1 \
		regex-syntax-0.6.12 \
		remove_dir_all-0.5.2 \
		reqwest-0.9.17 \
		rspotify-0.7.0 \
		rust-argon2-0.5.1 \
		rustc-demangle-0.1.16 \
		rustc-serialize-0.3.24 \
		rustc_version-0.2.3 \
		ryu-1.0.2 \
		schannel-0.1.16 \
		scopeguard-1.0.0 \
		security-framework-0.3.4 \
		security-framework-sys-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.103 \
		serde_derive-1.0.103 \
		serde_json-1.0.41 \
		serde_urlencoded-0.5.5 \
		serde_yaml-0.8.11 \
		slab-0.4.2 \
		smallvec-0.6.13 \
		smallvec-1.0.0 \
		string-0.2.1 \
		strsim-0.7.0 \
		strsim-0.8.0 \
		syn-0.15.44 \
		syn-1.0.8 \
		synstructure-0.12.3 \
		tempfile-3.1.0 \
		termcolor-1.0.5 \
		termion-1.5.3 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		time-0.1.42 \
		tokio-0.1.22 \
		tokio-buf-0.1.1 \
		tokio-current-thread-0.1.6 \
		tokio-executor-0.1.8 \
		tokio-io-0.1.12 \
		tokio-reactor-0.1.10 \
		tokio-sync-0.1.7 \
		tokio-tcp-0.1.3 \
		tokio-threadpool-0.1.16 \
		tokio-timer-0.2.11 \
		try-lock-0.2.2 \
		try_from-0.3.2 \
		tui-0.6.2 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.10 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.6 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		url-1.7.2 \
		url-2.1.0 \
		uuid-0.7.4 \
		vcpkg-0.2.7 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		version_check-0.9.1 \
		want-0.2.0 \
		wasi-0.7.0 \
		webbrowser-0.5.2 \
		widestring-0.4.0 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.2 \
		ws2_32-sys-0.2.1 \
		x11-clipboard-0.3.3 \
		xcb-0.8.2 \
		yaml-rust-0.4.3

BINARY_ALIAS=	python3=${PYTHON_CMD}

SUB_FILES=	pkg-message

PORTDOCS=	CHANGELOG.md README.md
PLIST_FILES=	bin/spt

OPTIONS_DEFINE=	DOCS SPOTIFYD
SPOTIFYD_DESC=	Lightweight Spotify client daemon

SPOTIFYD_RUN_DEPENDS=	spotifyd:audio/spotifyd

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
