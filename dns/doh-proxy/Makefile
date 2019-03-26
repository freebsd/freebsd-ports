# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	doh-proxy
DISTVERSION=	0.1.12
CATEGORIES=	dns

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DNS-over-HTTP server proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# jemalloc-sys-0.1.8 needs gmake
BUILD_DEPENDS=	gmake:devel/gmake

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1
GH_PROJECT=	rust-doh

PLIST_FILES=	bin/doh-proxy

CARGO_CRATES=	ansi_term-0.11.0 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		base64-0.10.1 \
		bitflags-1.0.4 \
		byteorder-1.3.1 \
		bytes-0.4.12 \
		cc-1.0.31 \
		cfg-if-0.1.7 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		crossbeam-deque-0.7.1 \
		crossbeam-epoch-0.7.1 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.5 \
		fnv-1.0.6 \
		fs_extra-1.1.0 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.25 \
		futures-cpupool-0.1.8 \
		h2-0.1.17 \
		http-0.1.16 \
		httparse-1.3.3 \
		hyper-0.12.25 \
		indexmap-1.0.2 \
		iovec-0.1.2 \
		itoa-0.4.3 \
		jemalloc-sys-0.1.8 \
		jemallocator-0.1.9 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		lazycell-1.2.1 \
		libc-0.2.50 \
		lock_api-0.1.5 \
		log-0.4.6 \
		memoffset-0.2.1 \
		mio-0.6.16 \
		mio-uds-0.6.7 \
		miow-0.2.1 \
		net2-0.2.33 \
		nodrop-0.1.13 \
		num_cpus-1.10.0 \
		owning_ref-0.4.0 \
		parking_lot-0.7.1 \
		parking_lot_core-0.4.0 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.3 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		rustc_version-0.2.3 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		slab-0.4.2 \
		smallvec-0.6.9 \
		stable_deref_trait-1.1.1 \
		string-0.1.3 \
		strsim-0.7.0 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		time-0.1.42 \
		tokio-0.1.18 \
		tokio-codec-0.1.1 \
		tokio-current-thread-0.1.6 \
		tokio-executor-0.1.7 \
		tokio-fs-0.1.6 \
		tokio-io-0.1.12 \
		tokio-reactor-0.1.9 \
		tokio-sync-0.1.4 \
		tokio-tcp-0.1.3 \
		tokio-threadpool-0.1.13 \
		tokio-timer-0.2.10 \
		tokio-trace-core-0.1.0 \
		tokio-udp-0.1.3 \
		tokio-uds-0.2.5 \
		try-lock-0.2.2 \
		unicode-width-0.1.5 \
		vec_map-0.8.1 \
		want-0.0.6 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/doh-proxy

.include <bsd.port.mk>
