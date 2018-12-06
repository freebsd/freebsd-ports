# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	doh-proxy
DISTVERSION=	0.1.10
PORTREVISION=	4
CATEGORIES=	dns

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DNS-over-HTTP server proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1
GH_PROJECT=	rust-doh

PLIST_FILES=	bin/doh-proxy

CARGO_CRATES=	ansi_term-0.11.0 \
		arrayvec-0.4.7 \
		atty-0.2.11 \
		base64-0.9.2 \
		bitflags-1.0.4 \
		byteorder-1.2.6 \
		bytes-0.4.9 \
		cfg-if-0.1.5 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		crossbeam-deque-0.6.1 \
		crossbeam-epoch-0.5.2 \
		crossbeam-utils-0.5.0 \
		fnv-1.0.6 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.23 \
		futures-cpupool-0.1.8 \
		h2-0.1.12 \
		http-0.1.10 \
		httparse-1.3.2 \
		hyper-0.12.9 \
		indexmap-1.0.1 \
		iovec-0.1.2 \
		itoa-0.4.2 \
		kernel32-sys-0.2.2 \
		lazy_static-1.1.0 \
		lazycell-0.6.0 \
		libc-0.2.43 \
		lock_api-0.1.3 \
		log-0.4.4 \
		memoffset-0.2.1 \
		mio-0.6.15 \
		mio-uds-0.6.6 \
		miow-0.2.1 \
		net2-0.2.33 \
		nodrop-0.1.12 \
		num_cpus-1.8.0 \
		owning_ref-0.3.3 \
		parking_lot-0.6.4 \
		parking_lot_core-0.3.0 \
		rand-0.5.5 \
		rand_core-0.2.1 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		rustc_version-0.2.3 \
		safemem-0.2.0 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		slab-0.3.0 \
		slab-0.4.1 \
		smallvec-0.6.5 \
		stable_deref_trait-1.1.1 \
		string-0.1.1 \
		strsim-0.7.0 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		time-0.1.40 \
		tokio-0.1.8 \
		tokio-codec-0.1.0 \
		tokio-current-thread-0.1.1 \
		tokio-executor-0.1.4 \
		tokio-fs-0.1.3 \
		tokio-io-0.1.8 \
		tokio-reactor-0.1.5 \
		tokio-tcp-0.1.1 \
		tokio-threadpool-0.1.6 \
		tokio-timer-0.1.2 \
		tokio-timer-0.2.6 \
		tokio-udp-0.1.2 \
		tokio-uds-0.2.1 \
		try-lock-0.2.2 \
		unicode-width-0.1.5 \
		unreachable-1.0.0 \
		vec_map-0.8.1 \
		version_check-0.1.4 \
		void-1.0.2 \
		want-0.0.6 \
		winapi-0.2.8 \
		winapi-0.3.5 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/doh-proxy

.include <bsd.port.mk>
