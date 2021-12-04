PORTNAME=	gitui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.2
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal UI for git

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

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

CARGO_CRATES=	addr2line-0.15.2 \
		adler-1.0.2 \
		ahash-0.6.3 \
		aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		anyhow-1.0.42 \
		arrayvec-0.4.12 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.60 \
		base64-0.13.0 \
		bincode-1.3.3 \
		bit-set-0.5.2 \
		bit-vec-0.6.3 \
		bitflags-1.2.1 \
		bugreport-0.4.0 \
		bytemuck-1.7.0 \
		bytesize-1.0.1 \
		cassowary-0.3.0 \
		cc-1.0.68 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		cpp_demangle-0.3.3 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.5 \
		crossbeam-utils-0.8.5 \
		crossterm-0.19.0 \
		crossterm_winapi-0.7.0 \
		ctor-0.1.20 \
		debugid-0.7.2 \
		diff-0.1.12 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		easy-cast-0.4.4 \
		either-1.6.1 \
		fancy-regex-0.3.5 \
		flate2-1.0.20 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		getrandom-0.2.3 \
		gimli-0.24.0 \
		git-version-0.3.4 \
		git-version-macro-0.3.4 \
		git2-0.13.20 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		idna-0.2.3 \
		indexmap-1.7.0 \
		inferno-0.10.6 \
		instant-0.1.9 \
		itertools-0.10.1 \
		itoa-0.4.7 \
		jobserver-0.1.22 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.98 \
		libgit2-sys-0.12.21+1.1.0 \
		libssh2-sys-0.2.21 \
		libz-sys-1.1.3 \
		line-wrap-0.1.1 \
		linked-hash-map-0.5.4 \
		lock_api-0.4.4 \
		log-0.4.14 \
		matches-0.1.8 \
		memchr-2.4.0 \
		memmap-0.7.0 \
		memoffset-0.6.4 \
		miniz_oxide-0.4.4 \
		mio-0.7.13 \
		miow-0.3.7 \
		nix-0.20.0 \
		nodrop-0.1.14 \
		ntapi-0.3.6 \
		num-format-0.4.0 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		object-0.25.3 \
		once_cell-1.8.0 \
		openssl-probe-0.1.4 \
		openssl-src-111.15.0+1.1.1k \
		openssl-sys-0.9.65 \
		output_vt100-0.1.2 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.19 \
		plist-1.1.0 \
		pprof-0.4.3 \
		ppv-lite86-0.2.10 \
		pretty_assertions-0.7.2 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.27 \
		quick-xml-0.20.0 \
		quote-1.0.9 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.9 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rgb-0.8.27 \
		ron-0.6.4 \
		rustc-demangle-0.1.20 \
		ryu-1.0.5 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.126 \
		serde_derive-1.0.126 \
		serde_json-1.0.64 \
		serial_test-0.5.1 \
		serial_test_derive-0.5.1 \
		shell-escape-0.1.5 \
		signal-hook-0.1.17 \
		signal-hook-registry-1.4.0 \
		simplelog-0.10.0 \
		smallvec-1.6.1 \
		smawk-0.3.1 \
		stable_deref_trait-1.2.0 \
		str_stack-0.1.0 \
		symbolic-common-8.3.0 \
		symbolic-demangle-8.3.0 \
		syn-1.0.73 \
		syntect-4.5.0 \
		sys-info-0.9.0 \
		tempfile-3.2.0 \
		textwrap-0.11.0 \
		textwrap-0.14.2 \
		thiserror-1.0.26 \
		thiserror-impl-1.0.26 \
		time-0.1.43 \
		tinyvec-1.2.0 \
		tinyvec_macros-0.1.0 \
		tui-0.15.0 \
		unicode-bidi-0.3.5 \
		unicode-linebreak-0.1.1 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.8.0 \
		unicode-truncate-0.2.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		uuid-0.8.2 \
		vcpkg-0.2.15 \
		version_check-0.9.3 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		which-4.1.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xml-rs-0.8.3 \
		yaml-rust-0.4.5
RUSTFLAGS+=	--cap-lints=warn
PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD} # xcb requires python3

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
