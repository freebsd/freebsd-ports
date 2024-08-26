PORTNAME=	ox
DISTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	editors
PKGNAMESUFFIX=	-text-editor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Independent Rust text editor that runs in your terminal
WWW=		https://github.com/curlpipe/ox

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	curlpipe

CARGO_CRATES=	aho-corasick-1.1.3 \
		alinio-0.2.1 \
		autocfg-1.3.0 \
		bitflags-2.6.0 \
		bstr-1.10.0 \
		cc-1.1.7 \
		cfg-if-1.0.0 \
		crossterm-0.27.0 \
		crossterm_winapi-0.9.1 \
		dirs-5.0.1 \
		dirs-sys-0.4.1 \
		either-1.13.0 \
		errno-0.3.9 \
		getrandom-0.2.15 \
		home-0.5.9 \
		if_chain-1.0.2 \
		jargon-args-0.2.7 \
		kaolinite-0.8.1 \
		libc-0.2.155 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.14 \
		lock_api-0.4.12 \
		log-0.4.22 \
		lua-src-547.0.0 \
		luajit-src-210.5.9+04dca79 \
		memchr-2.7.4 \
		mio-0.8.11 \
		mlua-0.9.9 \
		mlua-sys-0.6.2 \
		num-traits-0.2.19 \
		once_cell-1.19.0 \
		option-ext-0.2.0 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		pkg-config-0.3.30 \
		proc-macro2-1.0.86 \
		quick-error-2.0.1 \
		quote-1.0.36 \
		redox_syscall-0.5.3 \
		redox_users-0.4.5 \
		regex-1.10.6 \
		regex-automata-0.4.7 \
		regex-syntax-0.8.4 \
		ropey-1.6.1 \
		rustc-hash-2.0.0 \
		rustix-0.38.34 \
		scopeguard-1.2.0 \
		serde-1.0.204 \
		serde_derive-1.0.204 \
		shellexpand-3.1.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.4 \
		signal-hook-registry-1.4.2 \
		smallvec-1.13.2 \
		str_indices-0.4.3 \
		syn-2.0.72 \
		synoptic-2.0.4 \
		thiserror-1.0.63 \
		thiserror-impl-1.0.63 \
		unicode-ident-1.0.12 \
		unicode-width-0.1.13 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		which-6.0.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.6 \
		winsafe-0.0.19

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
