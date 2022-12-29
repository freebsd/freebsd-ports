PORTNAME=	gitui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal UI for git
WWW=		https://github.com/extrawurst/gitui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_armv7=	error: conflicting types for 'get_proc_total', see https://github.com/FillZpp/sys-info-rs/issues/80
BROKEN_i386=	error: conflicting types for 'get_proc_total', see https://github.com/FillZpp/sys-info-rs/issues/80
BROKEN_powerpc=	error: conflicting types for 'get_proc_total', see https://github.com/FillZpp/sys-info-rs/issues/80

BUILD_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake
LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo pkgconfig localbase:ldflags perl5 python:build xorg
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	extrawurst

CARGO_CRATES=	addr2line-0.17.0 \
		adler-1.0.2 \
		ahash-0.7.6 \
		aho-corasick-0.7.18 \
		android_system_properties-0.1.4 \
		ansi_term-0.12.1 \
		anyhow-1.0.62 \
		arrayvec-0.4.12 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		backtrace-0.3.66 \
		base64-0.13.0 \
		bincode-1.3.3 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		bugreport-0.5.0 \
		bumpalo-3.11.0 \
		bytemuck-1.12.1 \
		bytesize-1.1.0 \
		cassowary-0.3.0 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		chrono-0.4.22 \
		clap-3.2.17 \
		clap_lex-0.2.4 \
		core-foundation-sys-0.8.3 \
		cpp_demangle-0.3.5 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.6 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.10 \
		crossbeam-utils-0.8.11 \
		crossterm-0.23.2 \
		crossterm_winapi-0.9.0 \
		ctor-0.1.23 \
		dashmap-5.3.4 \
		debugid-0.8.0 \
		diff-0.1.13 \
		dirs-4.0.0 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.7 \
		dirs-sys-next-0.1.2 \
		easy-cast-0.4.4 \
		either-1.7.0 \
		fancy-regex-0.7.1 \
		fastrand-1.8.0 \
		findshlibs-0.10.2 \
		flate2-1.0.24 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		futures-0.3.23 \
		futures-channel-0.3.23 \
		futures-core-0.3.23 \
		futures-executor-0.3.23 \
		futures-io-0.3.23 \
		futures-sink-0.3.23 \
		futures-task-0.3.23 \
		futures-util-0.3.23 \
		fuzzy-matcher-0.3.7 \
		getrandom-0.2.7 \
		gh-emoji-1.0.7 \
		gimli-0.26.2 \
		git-version-0.3.5 \
		git-version-macro-0.3.5 \
		git2-0.15.0 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		iana-time-zone-0.1.45 \
		idna-0.2.3 \
		indexmap-1.9.1 \
		inferno-0.11.7 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-0.4.8 \
		itoa-1.0.3 \
		jobserver-0.1.24 \
		js-sys-0.3.59 \
		lazy_static-1.4.0 \
		libc-0.2.132 \
		libgit2-sys-0.14.0+1.5.0 \
		libssh2-sys-0.2.23 \
		libz-sys-1.1.8 \
		lock_api-0.4.7 \
		log-0.4.17 \
		matches-0.1.9 \
		memchr-2.5.0 \
		memmap2-0.5.7 \
		memoffset-0.6.5 \
		miniz_oxide-0.5.3 \
		mio-0.8.4 \
		nix-0.24.2 \
		nodrop-0.1.14 \
		num-format-0.4.0 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		num_threads-0.1.6 \
		object-0.29.0 \
		once_cell-1.13.1 \
		openssl-probe-0.1.5 \
		openssl-src-111.22.0+1.1.1q \
		openssl-sys-0.9.75 \
		os_str_bytes-6.3.0 \
		output_vt100-0.1.3 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.3 \
		percent-encoding-2.1.0 \
		phf-0.11.1 \
		phf_shared-0.11.1 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		pkg-config-0.3.25 \
		pprof-0.10.0 \
		pretty_assertions-1.2.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.43 \
		quick-xml-0.23.0 \
		quote-1.0.21 \
		rayon-core-1.9.3 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		remove_dir_all-0.5.3 \
		rgb-0.8.33 \
		ron-0.8.0 \
		rustc-demangle-0.1.21 \
		ryu-1.0.11 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.143 \
		serde_derive-1.0.143 \
		serde_json-1.0.83 \
		serial_test-0.9.0 \
		serial_test_derive-0.9.0 \
		shell-escape-0.1.5 \
		shellexpand-2.1.2 \
		signal-hook-0.3.14 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.0 \
		simplelog-0.12.0 \
		siphasher-0.3.10 \
		slab-0.4.7 \
		smallvec-1.9.0 \
		smawk-0.3.1 \
		stable_deref_trait-1.2.0 \
		str_stack-0.1.0 \
		strsim-0.10.0 \
		symbolic-common-9.1.1 \
		symbolic-demangle-9.1.1 \
		syn-1.0.99 \
		syntect-5.0.0 \
		sys-info-0.9.1 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		textwrap-0.15.0 \
		thiserror-1.0.32 \
		thiserror-impl-1.0.32 \
		thread_local-1.1.4 \
		time-0.3.13 \
		time-macros-0.2.4 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		tui-0.18.0 \
		unicode-bidi-0.3.8 \
		unicode-ident-1.0.3 \
		unicode-linebreak-0.1.2 \
		unicode-normalization-0.1.21 \
		unicode-segmentation-1.9.0 \
		unicode-truncate-0.2.0 \
		unicode-width-0.1.9 \
		url-2.2.2 \
		uuid-1.1.2 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.82 \
		wasm-bindgen-backend-0.2.82 \
		wasm-bindgen-macro-0.2.82 \
		wasm-bindgen-macro-support-0.2.82 \
		wasm-bindgen-shared-0.2.82 \
		which-4.2.5 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.36.1
RUSTFLAGS+=	--cap-lints=warn
PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD} # xcb requires python3

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
