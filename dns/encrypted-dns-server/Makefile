PORTNAME=	encrypted-dns-server
DISTVERSION=	0.9.6
PORTREVISION=	28
CATEGORIES=	dns

MAINTAINER=	felix@userspace.com.au
COMMENT=	High-performance, zero maintenance encrypted DNS proxy
WWW=		https://github.com/jedisct1/encrypted-dns-server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1
USE_RC_SUBR=	encrypted_dns

CARGO_CRATES=	adler-1.0.2 \
		adler32-1.2.0 \
		anyhow-1.0.58 \
		autocfg-1.1.0 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		bumpalo-3.10.0 \
		byteorder-1.4.3 \
		bytes-1.1.0 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		chunked_transfer-1.4.0 \
		clap-3.2.8 \
		clap_lex-0.2.4 \
		clockpro-cache-0.1.10 \
		coarsetime-0.1.22 \
		crc32fast-1.3.2 \
		crossbeam-utils-0.8.10 \
		ct-codecs-1.1.1 \
		daemonize-simple-0.1.5 \
		derivative-2.2.0 \
		dnsstamps-0.1.9 \
		env_logger-0.9.0 \
		filetime-0.2.17 \
		flate2-1.0.24 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		futures-0.3.21 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-macro-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		getrandom-0.2.7 \
		hashbrown-0.12.2 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		http-0.2.8 \
		http-body-0.4.5 \
		httparse-1.7.1 \
		httpdate-1.0.2 \
		humantime-2.1.0 \
		hyper-0.14.20 \
		idna-0.2.3 \
		indexmap-1.9.1 \
		ipext-0.1.0 \
		itoa-1.0.2 \
		js-sys-0.3.58 \
		lazy_static-1.4.0 \
		libc-0.2.126 \
		libflate-1.2.0 \
		libflate_lz77-1.1.0 \
		libmimalloc-sys-0.1.25 \
		libsodium-sys-stable-1.19.22 \
		lock_api-0.4.7 \
		log-0.4.17 \
		matches-0.1.9 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		mimalloc-0.1.29 \
		minisign-verify-0.2.1 \
		miniz_oxide-0.5.3 \
		mio-0.8.4 \
		nix-0.24.1 \
		num_cpus-1.13.1 \
		once_cell-1.13.0 \
		os_str_bytes-6.1.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.3 \
		percent-encoding-2.1.0 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		pkg-config-0.3.25 \
		ppv-lite86-0.2.16 \
		privdrop-0.5.2 \
		proc-macro2-1.0.40 \
		procfs-0.12.0 \
		prometheus-32bitfix-0.13.1 \
		quote-1.0.20 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		redox_syscall-0.2.13 \
		ring-0.16.20 \
		rle-decode-fast-1.0.3 \
		rlimit-0.8.3 \
		rustc-hash-1.1.0 \
		rustls-0.20.6 \
		scopeguard-1.1.0 \
		sct-0.7.0 \
		serde-1.0.138 \
		serde-big-array-0.4.1 \
		serde_derive-1.0.138 \
		siphasher-0.3.10 \
		slab-0.4.6 \
		slabigator-0.1.4 \
		smallvec-1.9.0 \
		socket2-0.4.4 \
		spin-0.5.2 \
		syn-1.0.98 \
		tar-0.4.38 \
		terminal_size-0.1.17 \
		textwrap-0.15.0 \
		thiserror-1.0.31 \
		thiserror-impl-1.0.31 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		tokio-1.19.2 \
		toml-0.5.9 \
		tower-service-0.3.2 \
		tracing-0.1.35 \
		tracing-core-0.1.28 \
		try-lock-0.2.3 \
		unicode-bidi-0.3.8 \
		unicode-ident-1.0.1 \
		unicode-normalization-0.1.21 \
		unsafe_unwrap-0.1.0 \
		untrusted-0.7.1 \
		ureq-2.5.0 \
		url-2.2.2 \
		vcpkg-0.2.15 \
		want-0.3.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.81 \
		wasm-bindgen-backend-0.2.81 \
		wasm-bindgen-macro-0.2.81 \
		wasm-bindgen-macro-support-0.2.81 \
		wasm-bindgen-shared-0.2.81 \
		web-sys-0.3.58 \
		webpki-0.22.0 \
		webpki-roots-0.22.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.36.1 \
		xattr-0.2.3 \
		zip-0.6.2

CARGO_FEATURES=	--no-default-features

USERS=		_encrypted-dns
GROUPS=		_encrypted-dns

PLIST_FILES=	"@dir(${USERS},${GROUPS},0755) ${ETCDIR}" \
		"@sample ${ETCDIR}/encrypted-dns.toml.sample" \
		"@sample ${ETCDIR}/undelegated.txt.sample" \
		bin/encrypted-dns
PLIST_SUB=	GROUPS=${GROUPS} \
		USERS=${USERS}

OPTIONS_DEFINE=		METRICS
OPTIONS_DEFAULT=	METRICS

METRICS_DESC=	Enable Prometheus metrics
METRICS_VARS=	CARGO_FEATURES+=metrics

post-extract:
	${MV} ${WRKSRC}/undelegated.txt \
		${WRKSRC}/undelegated.txt.sample

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/encrypted-dns.toml.sample \
		${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/undelegated.txt.sample \
		${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
