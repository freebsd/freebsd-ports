# $FreeBSD$

PORTNAME=	viu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	graphics

MAINTAINER=	vulcan@wired.sh
COMMENT=	Simple terminal image viewer written in Rust

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	atanunq

CARGO_CRATES=	adler-0.2.3 \
		adler32-1.2.0 \
		ansi_colours-1.0.1 \
		ansi_term-0.11.0 \
		arc-swap-0.4.7 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		bytemuck-1.4.1 \
		byteorder-1.3.4 \
		cc-1.0.61 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		cloudabi-0.1.0 \
		color_quant-1.1.0 \
		console-0.13.0 \
		const_fn-0.4.2 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.0 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.0 \
		crossbeam-utils-0.8.0 \
		crossterm-0.18.1 \
		crossterm_winapi-0.6.2 \
		ctrlc-3.1.7 \
		deflate-0.7.20 \
		deflate-0.8.6 \
		either-1.6.1 \
		encode_unicode-0.3.6 \
		getrandom-0.1.15 \
		gif-0.10.3 \
		gif-0.11.1 \
		hermit-abi-0.1.17 \
		image-0.22.5 \
		image-0.23.11 \
		inflate-0.4.5 \
		instant-0.1.8 \
		jpeg-decoder-0.1.20 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		lock_api-0.4.1 \
		log-0.4.11 \
		lzw-0.10.0 \
		memoffset-0.5.6 \
		miniz_oxide-0.3.7 \
		miniz_oxide-0.4.3 \
		mio-0.7.4 \
		miow-0.3.5 \
		nix-0.18.0 \
		ntapi-0.3.6 \
		num-derive-0.2.5 \
		num-integer-0.1.43 \
		num-iter-0.1.41 \
		num-rational-0.2.4 \
		num-rational-0.3.0 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		parking_lot-0.11.0 \
		parking_lot_core-0.8.0 \
		png-0.15.3 \
		png-0.16.7 \
		ppv-lite86-0.2.9 \
		proc-macro2-0.4.30 \
		quote-0.6.13 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rayon-1.5.0 \
		rayon-core-1.9.0 \
		redox_syscall-0.1.57 \
		regex-1.4.1 \
		regex-syntax-0.6.20 \
		remove_dir_all-0.5.3 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.1.0 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.1 \
		smallvec-1.4.2 \
		socket2-0.3.15 \
		strsim-0.8.0 \
		syn-0.15.44 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		terminal_size-0.1.13 \
		textwrap-0.11.0 \
		tiff-0.3.1 \
		tiff-0.6.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.1.0 \
		vec_map-0.8.2 \
		viuer-0.2.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		weezl-0.1.2 \
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
