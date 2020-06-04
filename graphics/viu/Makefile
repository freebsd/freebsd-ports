# $FreeBSD$

PORTNAME=	viu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	vulcan@wired.sh
COMMENT=	Simple terminal image viewer written in Rust

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	atanunq

CARGO_CRATES=	adler32-1.0.4 \
		ansi_colours-1.0.1 \
		ansi_term-0.11.0 \
		arc-swap-0.4.4 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bitflags-1.2.1 \
		bytemuck-1.2.0 \
		byteorder-1.3.4 \
		cc-1.0.50 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		color_quant-1.0.1 \
		crc32fast-1.2.0 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.1 \
		crossbeam-utils-0.7.2 \
		crossterm-0.15.0 \
		crossterm_winapi-0.6.1 \
		ctrlc-3.1.4 \
		deflate-0.7.20 \
		deflate-0.8.3 \
		either-1.5.3 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		gif-0.10.3 \
		hermit-abi-0.1.8 \
		image-0.22.5 \
		image-0.23.1 \
		inflate-0.4.5 \
		iovec-0.1.4 \
		jpeg-decoder-0.1.18 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.67 \
		lock_api-0.3.3 \
		log-0.4.8 \
		lzw-0.10.0 \
		maybe-uninit-2.0.0 \
		memoffset-0.5.3 \
		miniz_oxide-0.3.6 \
		mio-0.6.21 \
		miow-0.2.1 \
		net2-0.2.33 \
		nix-0.17.0 \
		num-derive-0.2.5 \
		num-integer-0.1.42 \
		num-iter-0.1.40 \
		num-rational-0.2.3 \
		num-traits-0.2.11 \
		num_cpus-1.12.0 \
		parking_lot-0.10.0 \
		parking_lot_core-0.7.0 \
		png-0.15.3 \
		png-0.16.1 \
		proc-macro2-0.4.30 \
		quote-0.6.13 \
		rayon-1.3.0 \
		rayon-core-1.7.0 \
		redox_syscall-0.1.56 \
		rustc_version-0.2.3 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		signal-hook-0.1.13 \
		signal-hook-registry-1.2.0 \
		slab-0.4.2 \
		smallvec-1.2.0 \
		strsim-0.8.0 \
		syn-0.15.44 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		tiff-0.3.1 \
		tiff-0.4.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.1.0 \
		vec_map-0.8.1 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.3 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
