PORTNAME=	rust-analyzer
DISTVERSION=	2023-06-12
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	rust@FreeBSD.org
COMMENT=	Experimental Rust compiler front-end for IDEs
WWW=		https://rust-analyzer.github.io/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo dos2unix
DOS2UNIX_FILES=	${WRKSRC_crate_notify}/src/kqueue.rs
USE_GITHUB=	yes

CARGO_CRATES=	addr2line-0.19.0 \
		adler-1.0.2 \
		always-assert-0.1.3 \
		anyhow-1.0.70 \
		anymap-1.0.0-beta.2 \
		arbitrary-1.3.0 \
		arrayvec-0.7.2 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		backtrace-0.3.67 \
		bitflags-1.3.2 \
		bitflags-2.1.0 \
		byteorder-1.4.3 \
		camino-1.1.4 \
		cargo-platform-0.1.2 \
		cargo_metadata-0.15.4 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		chalk-derive-0.89.0 \
		chalk-ir-0.89.0 \
		chalk-recursive-0.89.0 \
		chalk-solve-0.89.0 \
		command-group-2.1.0 \
		countme-3.0.1 \
		cov-mark-2.0.0-pre.1 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.8 \
		crossbeam-deque-0.8.3 \
		crossbeam-epoch-0.9.14 \
		crossbeam-utils-0.8.15 \
		dashmap-5.4.0 \
		derive_arbitrary-1.3.0 \
		dissimilar-1.0.6 \
		dot-0.1.4 \
		drop_bomb-0.1.5 \
		either-1.8.1 \
		ena-0.14.2 \
		expect-test-1.4.1 \
		filetime-0.2.19 \
		fixedbitset-0.2.0 \
		flate2-1.0.25 \
		form_urlencoded-1.1.0 \
		fsevent-sys-4.1.0 \
		fst-0.4.7 \
		gimli-0.27.2 \
		hashbrown-0.12.3 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		hermit-abi-0.2.6 \
		hkalbasi-rustc-ap-rustc_abi-0.0.20221221 \
		hkalbasi-rustc-ap-rustc_index-0.0.20221221 \
		home-0.5.4 \
		idna-0.3.0 \
		indexmap-1.9.3 \
		inotify-0.9.6 \
		inotify-sys-0.1.5 \
		instant-0.1.12 \
		itertools-0.10.5 \
		itoa-1.0.6 \
		jod-thread-0.1.2 \
		kqueue-1.0.7 \
		kqueue-sys-1.0.3 \
		lazy_static-1.4.0 \
		libc-0.2.141 \
		libloading-0.7.4 \
		libmimalloc-sys-0.1.32 \
		lock_api-0.4.9 \
		log-0.4.17 \
		lsp-types-0.94.0 \
		matchers-0.1.0 \
		memchr-2.5.0 \
		memmap2-0.5.10 \
		memoffset-0.8.0 \
		mimalloc-0.1.36 \
		miniz_oxide-0.6.2 \
		mio-0.8.5 \
		miow-0.5.0 \
		nix-0.26.2 \
		nohash-hasher-0.2.0 \
		notify-5.1.0 \
		nu-ansi-term-0.46.0 \
		num_cpus-1.15.0 \
		object-0.30.3 \
		once_cell-1.17.1 \
		oorandom-11.1.3 \
		overload-0.1.1 \
		parking_lot-0.11.2 \
		parking_lot-0.12.1 \
		parking_lot_core-0.8.6 \
		parking_lot_core-0.9.6 \
		paste-1.0.12 \
		percent-encoding-2.2.0 \
		perf-event-0.4.7 \
		perf-event-open-sys-1.0.1 \
		petgraph-0.5.1 \
		pin-project-lite-0.2.9 \
		proc-macro2-1.0.56 \
		protobuf-3.1.0 \
		protobuf-support-3.1.0 \
		pulldown-cmark-0.9.2 \
		pulldown-cmark-to-cmark-10.0.4 \
		quote-1.0.26 \
		ra-ap-rustc_lexer-0.1.0 \
		rayon-1.7.0 \
		rayon-core-1.11.0 \
		redox_syscall-0.2.16 \
		regex-1.7.3 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.29 \
		rowan-0.15.11 \
		rustc-demangle-0.1.22 \
		rustc-hash-1.1.0 \
		ryu-1.0.13 \
		salsa-0.17.0-pre.2 \
		salsa-macros-0.17.0-pre.2 \
		same-file-1.0.6 \
		scip-0.1.1 \
		scoped-tls-1.0.1 \
		scopeguard-1.1.0 \
		semver-1.0.17 \
		serde-1.0.156 \
		serde_derive-1.0.156 \
		serde_json-1.0.96 \
		serde_repr-0.1.11 \
		sharded-slab-0.1.4 \
		smallvec-1.10.0 \
		smol_str-0.2.0 \
		snap-1.1.0 \
		static_assertions-1.1.0 \
		syn-1.0.109 \
		synstructure-0.12.6 \
		text-size-1.1.0 \
		thiserror-1.0.39 \
		thiserror-impl-1.0.39 \
		thread_local-1.1.7 \
		tikv-jemalloc-ctl-0.5.0 \
		tikv-jemalloc-sys-0.5.3+5.3.0-patched \
		tikv-jemallocator-0.5.0 \
		time-0.3.20 \
		time-core-0.1.0 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		tracing-0.1.37 \
		tracing-attributes-0.1.23 \
		tracing-core-0.1.30 \
		tracing-log-0.1.3 \
		tracing-subscriber-0.3.16 \
		tracing-tree-0.2.2 \
		triomphe-0.1.8 \
		typed-arena-2.0.2 \
		ungrammar-1.16.1 \
		unic-char-property-0.9.0 \
		unic-char-range-0.9.0 \
		unic-common-0.9.0 \
		unic-emoji-char-0.9.0 \
		unic-ucd-version-0.9.0 \
		unicase-2.6.0 \
		unicode-bidi-0.3.13 \
		unicode-ident-1.0.8 \
		unicode-normalization-0.1.22 \
		unicode-segmentation-1.10.1 \
		unicode-xid-0.2.4 \
		url-2.3.1 \
		valuable-0.1.0 \
		version_check-0.9.4 \
		walkdir-2.3.3 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_msvc-0.42.2 \
		windows_i686_gnu-0.42.2 \
		windows_i686_msvc-0.42.2 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_msvc-0.42.2 \
		write-json-0.1.2 \
		xflags-0.3.1 \
		xflags-macros-0.3.1 \
		xshell-0.2.3 \
		xshell-macros-0.2.3 \
		zip-0.6.4

CARGO_INSTALL_PATH=	crates/rust-analyzer

LTO_UNSAFE=	yes

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
