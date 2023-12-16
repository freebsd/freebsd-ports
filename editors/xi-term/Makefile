PORTNAME=	xi-term
DISTVERSION=	g20190913
PORTREVISION=	29
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Terminal frontend for xi-editor
WWW=		https://github.com/xi-frontend/xi-term

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Run segfaults. See also: https://github.com/xi-frontend/xi-term/issues/116
DEPRECATED=	Frontend depends on deprecated editors/xi-core. No upstream activity.
EXPIRATION_DATE=	2023-12-31

RUN_DEPENDS=	xi-core:editors/xi-core

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	xi-frontend
GH_TAGNAME=	d264767

CARGO_CRATES=	adler32-1.0.3 \
		ansi_term-0.11.0 \
		antidote-1.0.0 \
		arc-swap-0.3.11 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.4 \
		backtrace-0.3.30 \
		backtrace-sys-0.1.28 \
		base64-0.10.1 \
		bitflags-1.1.0 \
		build_const-0.2.1 \
		byteorder-1.3.2 \
		bytes-0.4.12 \
		cc-1.0.37 \
		cfg-if-0.1.9 \
		chrono-0.4.6 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		crc-1.8.1 \
		crc32fast-1.2.0 \
		crossbeam-deque-0.7.1 \
		crossbeam-epoch-0.7.1 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.5 \
		dtoa-0.4.4 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		flate2-1.0.7 \
		fnv-1.0.6 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.27 \
		humantime-1.2.0 \
		indexmap-1.0.2 \
		iovec-0.1.2 \
		itoa-0.4.4 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		lazycell-1.2.1 \
		libc-0.2.58 \
		line-wrap-0.1.1 \
		linked-hash-map-0.5.2 \
		lock_api-0.1.5 \
		log-0.4.6 \
		log-mdc-0.1.0 \
		log4rs-0.8.3 \
		memoffset-0.2.1 \
		miniz-sys-0.1.12 \
		miniz_oxide-0.2.1 \
		miniz_oxide_c_api-0.2.1 \
		mio-0.6.19 \
		mio-named-pipes-0.1.6 \
		mio-uds-0.6.7 \
		miow-0.2.1 \
		miow-0.3.3 \
		net2-0.2.33 \
		nodrop-0.1.13 \
		num-integer-0.1.41 \
		num-traits-0.2.8 \
		num_cpus-1.10.1 \
		numtoa-0.1.0 \
		ordered-float-1.0.2 \
		owning_ref-0.4.0 \
		parking_lot-0.7.1 \
		parking_lot_core-0.4.0 \
		plist-0.4.2 \
		proc-macro2-0.4.30 \
		quick-error-1.2.2 \
		quote-0.6.12 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		rustc-demangle-0.1.15 \
		rustc_version-0.2.3 \
		ryu-0.2.8 \
		safemem-0.3.0 \
		same-file-1.0.4 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.92 \
		serde-value-0.5.3 \
		serde_derive-1.0.92 \
		serde_json-1.0.39 \
		serde_yaml-0.8.9 \
		signal-hook-0.1.9 \
		signal-hook-registry-1.0.1 \
		slab-0.4.2 \
		smallvec-0.6.10 \
		socket2-0.3.9 \
		stable_deref_trait-1.1.1 \
		strsim-0.8.0 \
		syn-0.15.36 \
		synstructure-0.10.2 \
		syntect-3.2.0 \
		termion-1.5.3 \
		textwrap-0.11.0 \
		thread-id-3.3.0 \
		time-0.1.42 \
		tokio-0.1.21 \
		tokio-codec-0.1.1 \
		tokio-current-thread-0.1.6 \
		tokio-executor-0.1.7 \
		tokio-fs-0.1.6 \
		tokio-io-0.1.12 \
		tokio-process-0.2.3 \
		tokio-reactor-0.1.9 \
		tokio-signal-0.2.7 \
		tokio-sync-0.1.6 \
		tokio-tcp-0.1.3 \
		tokio-threadpool-0.1.14 \
		tokio-timer-0.2.11 \
		tokio-trace-core-0.2.0 \
		tokio-udp-0.1.3 \
		tokio-uds-0.2.5 \
		traitobject-0.1.0 \
		typemap-0.3.3 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unsafe-any-0.4.2 \
		vec_map-0.8.1 \
		walkdir-2.2.8 \
		winapi-0.2.8 \
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1 \
		xdg-2.2.0 \
		xml-rs-0.8.0 \
		xrl-0.0.8 \
		yaml-rust-0.4.3

PLIST_FILES=	bin/xi-term
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xi-term

.include <bsd.port.mk>
