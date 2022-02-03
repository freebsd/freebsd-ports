PORTNAME=	encrypted-dns-server
DISTVERSION=	0.9.1
PORTREVISION=	4
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
		anyhow-1.0.44 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		bumpalo-3.7.1 \
		byteorder-1.4.3 \
		bytes-1.1.0 \
		cc-1.0.71 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		clockpro-cache-0.1.10 \
		coarsetime-0.1.19 \
		crc32fast-1.2.1 \
		ct-codecs-1.1.1 \
		daemonize-simple-0.1.5 \
		derivative-2.2.0 \
		dnsstamps-0.1.9 \
		env_logger-0.8.4 \
		filetime-0.2.15 \
		flate2-1.0.22 \
		fnv-1.0.7 \
		fs_extra-1.2.0 \
		futures-0.3.17 \
		futures-channel-0.3.17 \
		futures-core-0.3.17 \
		futures-executor-0.3.17 \
		futures-io-0.3.17 \
		futures-macro-0.3.17 \
		futures-sink-0.3.17 \
		futures-task-0.3.17 \
		futures-util-0.3.17 \
		getrandom-0.2.3 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		http-0.2.5 \
		http-body-0.4.3 \
		httparse-1.5.1 \
		httpdate-1.0.1 \
		humantime-2.1.0 \
		hyper-0.14.13 \
		instant-0.1.11 \
		ipext-0.1.0 \
		itoa-0.4.8 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		lazy_static-1.4.0 \
		libc-0.2.103 \
		libflate-1.1.1 \
		libflate_lz77-1.1.0 \
		libsodium-sys-stable-1.19.19 \
		lock_api-0.4.5 \
		log-0.4.14 \
		memchr-2.4.1 \
		minisign-verify-0.2.0 \
		miniz_oxide-0.4.4 \
		mio-0.7.13 \
		miow-0.3.7 \
		nix-0.19.1 \
		ntapi-0.3.6 \
		num_cpus-1.13.0 \
		once_cell-1.8.0 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		pin-project-lite-0.2.7 \
		pin-utils-0.1.0 \
		pkg-config-0.3.20 \
		ppv-lite86-0.2.10 \
		privdrop-0.5.0 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.7 \
		proc-macro2-1.0.29 \
		procfs-0.9.1 \
		prometheus-0.12.0 \
		quote-1.0.10 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		redox_syscall-0.2.10 \
		rle-decode-fast-1.0.1 \
		rustc-hash-1.1.0 \
		scopeguard-1.1.0 \
		serde-1.0.130 \
		serde-big-array-0.3.2 \
		serde_derive-1.0.130 \
		siphasher-0.3.7 \
		slab-0.4.4 \
		smallvec-1.7.0 \
		socket2-0.4.2 \
		syn-1.0.80 \
		tar-0.4.37 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		tokio-1.12.0 \
		toml-0.5.8 \
		tower-service-0.3.1 \
		tracing-0.1.29 \
		tracing-core-0.1.21 \
		try-lock-0.2.3 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		unsafe_unwrap-0.1.0 \
		vcpkg-0.2.15 \
		want-0.3.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.78 \
		wasm-bindgen-backend-0.2.78 \
		wasm-bindgen-macro-0.2.78 \
		wasm-bindgen-macro-support-0.2.78 \
		wasm-bindgen-shared-0.2.78 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xattr-0.2.2

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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/encrypted-dns.toml.sample \
		${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/undelegated.txt.sample \
		${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
