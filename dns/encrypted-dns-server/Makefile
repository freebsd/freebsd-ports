PORTNAME=	encrypted-dns-server
DISTVERSION=	0.3.23
PORTREVISION=	1
CATEGORIES=	dns

MAINTAINER=	felix@userspace.com.au
COMMENT=	High-performance, zero maintenance encrypted DNS proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1
USE_RC_SUBR=	encrypted_dns

CARGO_CRATES=	adler-1.0.2 \
		adler32-1.2.0 \
		aho-corasick-0.7.15 \
		anyhow-1.0.40 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bumpalo-3.6.1 \
		byteorder-1.4.3 \
		bytes-1.0.1 \
		cc-1.0.67 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		clockpro-cache-0.1.10 \
		coarsetime-0.1.18 \
		crc32fast-1.2.1 \
		ct-codecs-1.1.1 \
		daemonize-simple-0.1.4 \
		derivative-2.2.0 \
		dnsstamps-0.1.6 \
		env_logger-0.8.3 \
		filetime-0.2.14 \
		flate2-1.0.20 \
		fnv-1.0.7 \
		fs_extra-1.2.0 \
		futures-0.3.14 \
		futures-channel-0.3.14 \
		futures-core-0.3.14 \
		futures-executor-0.3.14 \
		futures-io-0.3.14 \
		futures-macro-0.3.14 \
		futures-sink-0.3.14 \
		futures-task-0.3.14 \
		futures-util-0.3.14 \
		getrandom-0.2.2 \
		hermit-abi-0.1.18 \
		hex-0.4.3 \
		http-0.2.4 \
		http-body-0.4.1 \
		httparse-1.3.6 \
		httpdate-0.3.2 \
		humantime-2.1.0 \
		hyper-0.14.5 \
		instant-0.1.9 \
		ipext-0.1.0 \
		itoa-0.4.7 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		lazy_static-1.4.0 \
		libc-0.2.93 \
		libflate-1.0.4 \
		libflate_lz77-1.0.0 \
		libsodium-sys-stable-1.19.15 \
		lock_api-0.4.3 \
		log-0.4.14 \
		memchr-2.3.4 \
		minisign-verify-0.1.8 \
		miniz_oxide-0.4.4 \
		mio-0.7.11 \
		miow-0.3.7 \
		nix-0.19.1 \
		ntapi-0.3.6 \
		num_cpus-1.13.0 \
		once_cell-1.7.2 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		pin-project-1.0.6 \
		pin-project-internal-1.0.6 \
		pin-project-lite-0.2.6 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.10 \
		privdrop-0.5.0 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.7 \
		proc-macro2-1.0.26 \
		procfs-0.9.1 \
		prometheus-0.11.0 \
		quote-1.0.9 \
		rand-0.8.3 \
		rand_chacha-0.3.0 \
		rand_core-0.6.2 \
		rand_hc-0.3.0 \
		redox_syscall-0.2.6 \
		regex-1.4.5 \
		regex-syntax-0.6.23 \
		rle-decode-fast-1.0.1 \
		rustc-hash-1.1.0 \
		scopeguard-1.1.0 \
		serde-1.0.125 \
		serde-big-array-0.3.2 \
		serde_derive-1.0.125 \
		siphasher-0.3.5 \
		slab-0.4.2 \
		smallvec-1.6.1 \
		socket2-0.3.19 \
		syn-1.0.69 \
		tar-0.4.33 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thiserror-1.0.24 \
		thiserror-impl-1.0.24 \
		tokio-1.5.0 \
		toml-0.5.8 \
		tower-service-0.3.1 \
		tracing-0.1.25 \
		tracing-core-0.1.17 \
		try-lock-0.2.3 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		unsafe_unwrap-0.1.0 \
		vcpkg-0.2.11 \
		want-0.3.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.73 \
		wasm-bindgen-backend-0.2.73 \
		wasm-bindgen-macro-0.2.73 \
		wasm-bindgen-macro-support-0.2.73 \
		wasm-bindgen-shared-0.2.73 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xattr-0.2.2
CARGO_FEATURES=	--no-default-features

USERS=		_encrypted-dns
GROUPS=		_encrypted-dns

PLIST_SUB=	USERS=${USERS} \
		GROUPS=${GROUPS}
PLIST_FILES=	bin/encrypted-dns \
		"@sample ${ETCDIR}/encrypted-dns.toml.sample" \
		"@dir(${USERS},${GROUPS},0755) ${ETCDIR}"

OPTIONS_DEFINE=	METRICS
OPTIONS_DEFAULT=METRICS

METRICS_DESC=	Enable Prometheus metrics
METRICS_VARS=	CARGO_FEATURES+=metrics

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/encrypted-dns.toml.sample \
		${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
