# $FreeBSD$

PORTNAME=	gifski
DISTVERSION=	1.2.2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Highest-quality GIF encoder based on pngquant

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	ImageOptim
GH_TUPLE=	kornelski:rust-ffmpeg:4da6d270cdaa868e5488144ed73bfaabe329cfcb:ffmpeg \
		meh:rust-ffmpeg-sys:70f711a43eb7ff7447fcffa98bb9f533acc08a1e:ffmpegsys

CARGO_CRATES=	adler-0.2.3 \
		aho-corasick-0.7.13 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bindgen-0.55.1 \
		bitflags-0.9.1 \
		bitflags-1.2.1 \
		bytemuck-1.4.1 \
		cc-1.0.61 \
		cexpr-0.4.0 \
		cfg-if-0.1.10 \
		clang-sys-1.0.1 \
		clap-2.33.3 \
		color_quant-1.1.0 \
		crc32fast-1.2.0 \
		crossbeam-channel-0.4.4 \
		crossbeam-utils-0.7.2 \
		dunce-1.0.1 \
		env_logger-0.7.1 \
		flate2-1.0.18 \
		gif-0.11.1 \
		gif-dispose-3.0.0 \
		gifsicle-1.92.1 \
		glob-0.3.0 \
		hermit-abi-0.1.17 \
		humantime-1.3.0 \
		imagequant-2.12.5 \
		imagequant-sys-2.12.7 \
		imgref-1.7.0 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.79 \
		libloading-0.6.4 \
		lodepng-3.2.2 \
		log-0.4.11 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		miniz_oxide-0.4.3 \
		natord-1.0.9 \
		nom-5.1.2 \
		num_cpus-1.13.0 \
		openmp-sys-0.1.7 \
		pbr-1.0.3 \
		peeking_take_while-0.1.2 \
		pkg-config-0.3.18 \
		proc-macro2-1.0.24 \
		quick-error-1.2.3 \
		quick-error-2.0.0 \
		quote-1.0.7 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		resize-0.5.5 \
		rgb-0.8.25 \
		rustc-hash-1.1.0 \
		shlex-0.1.1 \
		strsim-0.8.0 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.44 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vcpkg-0.2.10 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		weezl-0.1.1 \
		which-3.1.1 \
		wild-2.0.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_USE_GITHUB=	yes

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
