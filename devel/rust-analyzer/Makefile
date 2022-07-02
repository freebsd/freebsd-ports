PORTNAME=	rust-analyzer
DISTVERSION=	2022-06-20
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	rust@FreeBSD.org
COMMENT=	Experimental Rust compiler front-end for IDEs

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo dos2unix
DOS2UNIX_FILES=	${WRKSRC_crate_notify}/src/kqueue.rs
USE_GITHUB=	yes

CARGO_CRATES=	addr2line-0.17.0 \
		adler-1.0.2 \
		always-assert-0.1.2 \
		ansi_term-0.12.1 \
		anyhow-1.0.57 \
		anymap-1.0.0-beta.2 \
		arbitrary-1.1.0 \
		arrayvec-0.7.2 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		backtrace-0.3.65 \
		bitflags-1.3.2 \
		camino-1.0.9 \
		cargo-platform-0.1.2 \
		cargo_metadata-0.14.2 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		chalk-derive-0.82.0 \
		chalk-ir-0.82.0 \
		chalk-recursive-0.82.0 \
		chalk-solve-0.82.0 \
		countme-3.0.1 \
		cov-mark-2.0.0-pre.1 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		dashmap-5.3.4 \
		derive_arbitrary-1.1.0 \
		dissimilar-1.0.4 \
		dot-0.1.4 \
		drop_bomb-0.1.5 \
		either-1.6.1 \
		ena-0.14.0 \
		expect-test-1.3.0 \
		filetime-0.2.16 \
		fixedbitset-0.2.0 \
		flate2-1.0.24 \
		form_urlencoded-1.0.1 \
		fs_extra-1.2.0 \
		fsevent-sys-4.1.0 \
		fst-0.4.7 \
		gimli-0.26.1 \
		hashbrown-0.11.2 \
		hashbrown-0.12.1 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		home-0.5.3 \
		idna-0.2.3 \
		indexmap-1.8.2 \
		inotify-0.9.6 \
		inotify-sys-0.1.5 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-1.0.2 \
		jod-thread-0.1.2 \
		kqueue-1.0.6 \
		kqueue-sys-1.0.3 \
		lazy_static-1.4.0 \
		libc-0.2.126 \
		libloading-0.7.3 \
		libmimalloc-sys-0.1.25 \
		lock_api-0.4.7 \
		log-0.4.17 \
		lsp-types-0.93.0 \
		matchers-0.1.0 \
		matches-0.1.9 \
		memchr-2.5.0 \
		memmap2-0.5.4 \
		memoffset-0.6.5 \
		mimalloc-0.1.29 \
		miniz_oxide-0.5.3 \
		mio-0.8.3 \
		miow-0.4.0 \
		notify-5.0.0-pre.15 \
		num_cpus-1.13.1 \
		object-0.28.4 \
		once_cell-1.12.0 \
		oorandom-11.1.3 \
		parking_lot-0.11.2 \
		parking_lot-0.12.1 \
		parking_lot_core-0.8.5 \
		parking_lot_core-0.9.3 \
		paste-1.0.7 \
		percent-encoding-2.1.0 \
		perf-event-0.4.7 \
		perf-event-open-sys-1.0.1 \
		petgraph-0.5.1 \
		pin-project-lite-0.2.9 \
		proc-macro2-1.0.39 \
		pulldown-cmark-0.9.1 \
		pulldown-cmark-to-cmark-10.0.1 \
		quote-1.0.18 \
		rayon-1.5.3 \
		rayon-core-1.9.3 \
		redox_syscall-0.2.13 \
		regex-1.5.6 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.26 \
		rowan-0.15.5 \
		rustc-ap-rustc_lexer-725.0.0 \
		rustc-demangle-0.1.21 \
		rustc-hash-1.1.0 \
		ryu-1.0.10 \
		salsa-0.17.0-pre.2 \
		salsa-macros-0.17.0-pre.2 \
		same-file-1.0.6 \
		scoped-tls-1.0.0 \
		scopeguard-1.1.0 \
		semver-1.0.10 \
		serde-1.0.137 \
		serde_derive-1.0.137 \
		serde_json-1.0.81 \
		serde_repr-0.1.8 \
		sharded-slab-0.1.4 \
		smallvec-1.8.0 \
		smol_str-0.1.23 \
		snap-1.0.5 \
		syn-1.0.96 \
		synstructure-0.12.6 \
		text-size-1.1.0 \
		thread_local-1.1.4 \
		threadpool-1.8.1 \
		tikv-jemalloc-ctl-0.5.0 \
		tikv-jemalloc-sys-0.5.0+5.3.0 \
		tikv-jemallocator-0.5.0 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		tracing-0.1.35 \
		tracing-attributes-0.1.21 \
		tracing-core-0.1.27 \
		tracing-log-0.1.3 \
		tracing-subscriber-0.3.11 \
		tracing-tree-0.2.1 \
		typed-arena-2.0.1 \
		ungrammar-1.16.1 \
		unicase-2.6.0 \
		unicode-bidi-0.3.8 \
		unicode-ident-1.0.0 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.9.0 \
		unicode-xid-0.2.3 \
		url-2.2.2 \
		valuable-0.1.0 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.28.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.28.0 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.28.0 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.28.0 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.28.0 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.28.0 \
		windows_x86_64_msvc-0.36.1 \
		write-json-0.1.2 \
		xflags-0.2.4 \
		xflags-macros-0.2.4 \
		xshell-0.2.2 \
		xshell-macros-0.2.2

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
