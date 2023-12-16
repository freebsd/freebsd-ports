PORTNAME=	ox
DISTVERSION=	0.2.7
PORTREVISION=	9
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

CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.11 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		cloudabi-0.1.0 \
		constant_time_eq-0.1.5 \
		crossbeam-utils-0.7.2 \
		crossterm-0.18.2 \
		crossterm_winapi-0.6.2 \
		directories-3.0.1 \
		dirs-2.0.2 \
		dirs-sys-0.3.5 \
		getrandom-0.1.15 \
		hermit-abi-0.1.17 \
		instant-0.1.8 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		lock_api-0.4.1 \
		log-0.4.11 \
		memchr-2.3.4 \
		mio-0.7.6 \
		miow-0.3.6 \
		ntapi-0.3.6 \
		parking_lot-0.11.0 \
		parking_lot_core-0.8.0 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		regex-1.4.2 \
		regex-syntax-0.6.21 \
		ron-0.6.2 \
		rust-argon2-0.8.2 \
		scopeguard-1.1.0 \
		serde-1.0.117 \
		serde_derive-1.0.117 \
		shellexpand-2.0.0 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.2 \
		smallvec-1.4.2 \
		socket2-0.3.16 \
		strsim-0.8.0 \
		syn-1.0.48 \
		term-0.6.1 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		unicode-segmentation-1.7.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
