# $FreeBSD$

PORTNAME=	encrypted-dns-server
DISTVERSION=	0.3.21
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

CARGO_CRATES=	adler32-1.2.0 \
		aho-corasick-0.7.14 \
		anyhow-1.0.33 \
		autocfg-1.0.1 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		byteorder-1.3.4 \
		bytes-0.5.6 \
		cc-1.0.61 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		clockpro-cache-0.1.8 \
		cloudabi-0.0.3 \
		cloudabi-0.1.0 \
		coarsetime-0.1.16 \
		crc32fast-1.2.1 \
		daemonize-simple-0.1.4 \
		derivative-2.1.1 \
		dnsstamps-0.1.4 \
		env_logger-0.8.1 \
		filetime-0.2.12 \
		fnv-1.0.7 \
		fs_extra-1.2.0 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.3.7 \
		futures-channel-0.3.7 \
		futures-core-0.3.7 \
		futures-executor-0.3.7 \
		futures-io-0.3.7 \
		futures-macro-0.3.7 \
		futures-sink-0.3.7 \
		futures-task-0.3.7 \
		futures-util-0.3.7 \
		getrandom-0.1.15 \
		h2-0.2.7 \
		hashbrown-0.9.1 \
		hermit-abi-0.1.17 \
		hex-0.4.2 \
		http-0.2.1 \
		http-body-0.3.1 \
		httparse-1.3.4 \
		httpdate-0.3.2 \
		humantime-2.0.1 \
		hyper-0.13.8 \
		indexmap-1.6.0 \
		instant-0.1.8 \
		iovec-0.1.4 \
		ipext-0.1.0 \
		itoa-0.4.6 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		libflate-1.0.3 \
		libflate_lz77-1.0.0 \
		libsodium-sys-stable-1.19.11 \
		lock_api-0.3.4 \
		lock_api-0.4.1 \
		log-0.4.11 \
		memchr-2.3.4 \
		minisign-verify-0.1.8 \
		mio-0.6.22 \
		miow-0.2.1 \
		net2-0.2.35 \
		nix-0.19.0 \
		num_cpus-1.13.0 \
		once_cell-1.4.1 \
		parking_lot-0.10.2 \
		parking_lot-0.11.0 \
		parking_lot_core-0.7.2 \
		parking_lot_core-0.8.0 \
		pin-project-0.4.27 \
		pin-project-1.0.1 \
		pin-project-internal-0.4.27 \
		pin-project-internal-1.0.1 \
		pin-project-lite-0.1.11 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.9 \
		privdrop-0.5.0 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.6 \
		proc-macro2-1.0.24 \
		procfs-0.8.1 \
		prometheus-0.10.0 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		regex-1.4.2 \
		regex-syntax-0.6.21 \
		rle-decode-fast-1.0.1 \
		rustc-hash-1.1.0 \
		scopeguard-1.1.0 \
		serde-1.0.117 \
		serde-big-array-0.3.0 \
		serde_derive-1.0.117 \
		siphasher-0.3.3 \
		slab-0.4.2 \
		smallvec-1.4.2 \
		socket2-0.3.15 \
		syn-1.0.48 \
		tar-0.4.30 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thiserror-1.0.21 \
		thiserror-impl-1.0.21 \
		thread_local-1.0.1 \
		tokio-0.2.22 \
		tokio-util-0.3.1 \
		toml-0.5.7 \
		tower-service-0.3.0 \
		tracing-0.1.21 \
		tracing-core-0.1.17 \
		tracing-futures-0.2.4 \
		try-lock-0.2.3 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		unsafe_unwrap-0.1.0 \
		vcpkg-0.2.10 \
		want-0.3.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1 \
		xattr-0.2.2
CARGO_FEATURES=	--no-default-features

USERS=		_encrypted-dns
GROUPS=		_encrypted-dns

PLIST_FILES=	bin/encrypted-dns \
		"@sample ${PREFIX}/etc/encrypted-dns/encrypted-dns.toml.sample"

OPTIONS_DEFINE=	METRICS
OPTIONS_DEFAULT=METRICS

METRICS_DESC=	Enable Prometheus metrics
METRICS_VARS=	CARGO_FEATURES+=metrics

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/encrypted-dns
	${INSTALL_DATA} ${FILESDIR}/encrypted-dns.toml.sample \
		${STAGEDIR}${PREFIX}/etc/encrypted-dns

.include <bsd.port.mk>
