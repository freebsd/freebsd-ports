# $FreeBSD$

PORTNAME=	gitui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal UI for git

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake
LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo pkgconfig localbase:ldflags perl5 python:build xorg
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	extrawurst
GH_TAGNAME=	fbba2d0 # freebsd-fix branch

CARGO_CRATES=	addr2line-0.14.0 \
		adler-0.2.3 \
		ahash-0.6.1 \
		anyhow-1.0.36 \
		arrayvec-0.4.12 \
		autocfg-1.0.1 \
		backtrace-0.3.55 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		bytemuck-1.4.1 \
		bytesize-1.0.1 \
		cassowary-0.3.0 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		const_fn-0.4.3 \
		cpp_demangle-0.3.2 \
		crossbeam-channel-0.5.0 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.1 \
		crossbeam-utils-0.8.1 \
		crossterm-0.18.2 \
		crossterm_winapi-0.6.2 \
		debugid-0.7.2 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.1 \
		either-1.6.1 \
		form_urlencoded-1.0.0 \
		getrandom-0.1.15 \
		getrandom-0.2.0 \
		gimli-0.23.0 \
		git2-0.13.12 \
		glob-0.3.0 \
		hashbrown-0.9.1 \
		hermit-abi-0.1.17 \
		idna-0.2.0 \
		indexmap-1.6.0 \
		inferno-0.10.2 \
		instant-0.1.9 \
		itertools-0.9.0 \
		itoa-0.4.6 \
		jobserver-0.1.21 \
		lazy_static-1.4.0 \
		libc-0.2.81 \
		libgit2-sys-0.12.14+1.1.0 \
		libssh2-sys-0.2.20 \
		libz-sys-1.1.2 \
		lock_api-0.4.2 \
		log-0.4.11 \
		matches-0.1.8 \
		memchr-2.3.4 \
		memmap-0.7.0 \
		memoffset-0.6.1 \
		miniz_oxide-0.4.3 \
		mio-0.7.6 \
		miow-0.3.6 \
		nix-0.17.0 \
		nodrop-0.1.14 \
		ntapi-0.3.6 \
		num-format-0.4.0 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		object-0.22.0 \
		openssl-probe-0.1.2 \
		openssl-src-111.12.0+1.1.1h \
		openssl-sys-0.9.58 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.1 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.19 \
		pprof-0.3.20 \
		ppv-lite86-0.2.10 \
		proc-macro2-1.0.24 \
		quick-xml-0.20.0 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rayon-core-1.9.0 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		remove_dir_all-0.5.3 \
		rgb-0.8.25 \
		ron-0.6.4 \
		rustc-demangle-0.1.18 \
		scopeguard-1.1.0 \
		serde-1.0.118 \
		serde_derive-1.0.118 \
		serial_test-0.5.1 \
		serial_test_derive-0.5.1 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.2 \
		simplelog-0.8.0 \
		smallvec-1.5.1 \
		smawk-0.3.0 \
		socket2-0.3.17 \
		stable_deref_trait-1.2.0 \
		str_stack-0.1.0 \
		symbolic-common-8.0.0 \
		symbolic-demangle-8.0.0 \
		syn-1.0.54 \
		tempfile-3.1.0 \
		textwrap-0.11.0 \
		textwrap-0.13.1 \
		thiserror-1.0.22 \
		thiserror-impl-1.0.22 \
		time-0.1.44 \
		tinyvec-1.1.0 \
		tinyvec_macros-0.1.0 \
		tui-0.13.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.16 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.2.0 \
		uuid-0.8.1 \
		vcpkg-0.2.10 \
		version_check-0.9.2 \
		void-1.0.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		which-4.0.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0
PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD} # xcb requires python3

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
