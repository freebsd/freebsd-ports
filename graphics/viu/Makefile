# $FreeBSD$

PORTNAME=	viu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	vulcan@wired.sh
COMMENT=	Simple terminal image viewer written in Rust

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	atanunq

CARGO_CRATES=	adler32-1.2.0 \
		ansi_colours-1.0.1 \
		ansi_term-0.11.0 \
		arc-swap-0.4.7 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bytemuck-1.4.1 \
		byteorder-1.3.4 \
		cc-1.0.60 \
		cfg-if-0.1.10 \
		clap-2.33.3 \
		cloudabi-0.0.3 \
		color_quant-1.0.1 \
		crc32fast-1.2.0 \
		crossbeam-channel-0.4.4 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-utils-0.7.2 \
		crossterm-0.17.7 \
		crossterm_winapi-0.6.1 \
		ctrlc-3.1.6 \
		deflate-0.7.20 \
		deflate-0.8.6 \
		either-1.6.1 \
		gif-0.10.3 \
		hermit-abi-0.1.15 \
		image-0.22.5 \
		image-0.23.9 \
		inflate-0.4.5 \
		jpeg-decoder-0.1.20 \
		lazy_static-1.4.0 \
		libc-0.2.77 \
		lock_api-0.3.4 \
		log-0.4.11 \
		lzw-0.10.0 \
		maybe-uninit-2.0.0 \
		memoffset-0.5.5 \
		miniz_oxide-0.3.7 \
		mio-0.7.0 \
		miow-0.3.5 \
		nix-0.17.0 \
		ntapi-0.3.4 \
		num-derive-0.2.5 \
		num-integer-0.1.43 \
		num-iter-0.1.41 \
		num-rational-0.2.4 \
		num-rational-0.3.0 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		png-0.15.3 \
		png-0.16.7 \
		proc-macro2-0.4.30 \
		quote-0.6.13 \
		rayon-1.4.0 \
		rayon-core-1.8.1 \
		redox_syscall-0.1.57 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.1.0 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.1 \
		smallvec-1.4.2 \
		socket2-0.3.15 \
		strsim-0.8.0 \
		syn-0.15.44 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		tiff-0.3.1 \
		tiff-0.5.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.1.0 \
		vec_map-0.8.2 \
		void-1.0.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
