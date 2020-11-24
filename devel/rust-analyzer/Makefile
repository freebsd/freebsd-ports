# $FreeBSD$

PORTNAME=	rust-analyzer
DISTVERSION=	2020-09-28
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	rust@FreeBSD.org
COMMENT=	Experimental Rust compiler front-end for IDEs

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
CARGO_CRATES=	addr2line-0.13.0 \
		adler-0.2.3 \
		ansi_term-0.12.1 \
		anyhow-1.0.32 \
		anymap-0.12.1 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.50 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		byteorder-1.3.4 \
		cargo_metadata-0.11.3 \
		cc-1.0.60 \
		cfg-if-0.1.10 \
		chalk-derive-0.29.0 \
		chalk-ir-0.29.0 \
		chalk-recursive-0.29.0 \
		chalk-solve-0.29.0 \
		chrono-0.4.18 \
		cloudabi-0.1.0 \
		cmake-0.1.44 \
		crc32fast-1.2.0 \
		crossbeam-channel-0.4.4 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-utils-0.7.2 \
		difference-2.0.0 \
		drop_bomb-0.1.5 \
		either-1.6.1 \
		ena-0.14.0 \
		env_logger-0.7.1 \
		expect-test-1.0.1 \
		filetime-0.2.12 \
		fixedbitset-0.2.0 \
		flate2-1.0.17 \
		fs-err-2.5.0 \
		fsevent-2.0.2 \
		fsevent-sys-3.0.2 \
		fst-0.4.4 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		gimli-0.22.0 \
		goblin-0.2.3 \
		hashbrown-0.9.0 \
		heck-0.3.1 \
		hermit-abi-0.1.16 \
		home-0.5.3 \
		idna-0.2.0 \
		indexmap-1.6.0 \
		inotify-0.8.3 \
		inotify-sys-0.1.3 \
		instant-0.1.7 \
		iovec-0.1.4 \
		itertools-0.9.0 \
		itoa-0.4.6 \
		jod-thread-0.1.2 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.77 \
		libloading-0.6.3 \
		libmimalloc-sys-0.1.17 \
		lock_api-0.4.1 \
		log-0.4.11 \
		lsp-server-0.3.4 \
		lsp-types-0.82.0 \
		matchers-0.0.1 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memmap-0.7.0 \
		memoffset-0.5.6 \
		mimalloc-0.1.21 \
		miniz_oxide-0.4.2 \
		mio-0.6.22 \
		mio-extras-2.0.6 \
		miow-0.2.1 \
		net2-0.2.35 \
		notify-5.0.0-pre.3 \
		num-integer-0.1.43 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		object-0.20.0 \
		once_cell-1.4.1 \
		oorandom-11.1.2 \
		parking_lot-0.11.0 \
		parking_lot_core-0.8.0 \
		percent-encoding-2.1.0 \
		perf-event-0.4.5 \
		perf-event-open-sys-1.0.1 \
		petgraph-0.5.1 \
		pico-args-0.3.4 \
		plain-0.2.3 \
		proc-macro2-1.0.23 \
		pulldown-cmark-0.7.2 \
		pulldown-cmark-to-cmark-5.0.0 \
		quote-1.0.7 \
		rayon-1.4.0 \
		rayon-core-1.8.1 \
		redox_syscall-0.1.57 \
		regex-1.3.9 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.18 \
		rowan-0.10.0 \
		rustc-ap-rustc_lexer-673.0.0 \
		rustc-demangle-0.1.16 \
		rustc-hash-1.1.0 \
		ryu-1.0.5 \
		salsa-0.15.2 \
		salsa-macros-0.15.2 \
		same-file-1.0.6 \
		scoped-tls-1.0.0 \
		scopeguard-1.1.0 \
		scroll-0.10.1 \
		scroll_derive-0.10.2 \
		semver-0.10.0 \
		semver-parser-0.7.0 \
		serde-1.0.116 \
		serde_derive-1.0.116 \
		serde_json-1.0.57 \
		serde_repr-0.1.6 \
		sharded-slab-0.0.9 \
		slab-0.4.2 \
		smallvec-1.4.2 \
		smol_str-0.1.17 \
		syn-1.0.42 \
		synstructure-0.12.4 \
		termcolor-1.1.0 \
		text-size-1.0.0 \
		thin-dst-1.1.0 \
		thread_local-1.0.1 \
		threadpool-1.8.1 \
		time-0.1.44 \
		tinyvec-0.3.4 \
		tracing-0.1.19 \
		tracing-attributes-0.1.11 \
		tracing-core-0.1.16 \
		tracing-log-0.1.1 \
		tracing-serde-0.1.2 \
		tracing-subscriber-0.2.12 \
		tracing-tree-0.1.5 \
		ungrammar-1.1.4 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-segmentation-1.6.0 \
		unicode-xid-0.2.1 \
		url-2.1.1 \
		version_check-0.9.2 \
		walkdir-2.3.1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		write-json-0.1.2 \
		ws2_32-sys-0.2.1

CARGO_INSTALL_PATH=	crates/rust-analyzer

# attempts to install rustup toolchains
NO_TEST=	yes

PLIST_FILES=	bin/rust-analyzer
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rust-analyzer

post-install-DOCS-on:
	@cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
