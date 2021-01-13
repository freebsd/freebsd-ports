# $FreeBSD$

PORTNAME=	gifski
DISTVERSION=	1.2.6
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Highest-quality GIF encoder based on pngquant

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	ImageOptim
GH_TUPLE=	kornelski:rust-ffmpeg:4da6d270cdaa868e5488144ed73bfaabe329cfcb:ffmpeg \
		meh:rust-ffmpeg-sys:acc80af7fb470e7a0b8a6856abee0d2e40799cf2:ffmpegsys

CARGO_CRATES=	adler-0.2.3 \
		aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bindgen-0.56.0 \
		bitflags-0.9.1 \
		bitflags-1.2.1 \
		bytemuck-1.4.1 \
		cc-1.0.66 \
		cexpr-0.4.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clang-sys-1.0.3 \
		clap-2.33.3 \
		color_quant-1.1.0 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.0 \
		crossbeam-utils-0.8.1 \
		dunce-1.0.1 \
		env_logger-0.8.2 \
		flate2-1.0.19 \
		gif-0.11.1 \
		gif-dispose-3.1.0 \
		gifsicle-1.92.4 \
		glob-0.3.0 \
		hermit-abi-0.1.17 \
		humantime-2.0.1 \
		imagequant-2.13.0 \
		imagequant-sys-2.13.1 \
		imgref-1.7.1 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.82 \
		libloading-0.6.6 \
		lodepng-3.2.2 \
		log-0.4.11 \
		memchr-2.3.4 \
		miniz_oxide-0.4.3 \
		natord-1.0.9 \
		nom-5.1.2 \
		num_cpus-1.13.0 \
		openmp-sys-1.0.0 \
		pbr-1.0.4 \
		peeking_take_while-0.1.2 \
		pkg-config-0.3.19 \
		proc-macro2-1.0.24 \
		quick-error-2.0.0 \
		quote-1.0.8 \
		regex-1.4.3 \
		regex-syntax-0.6.22 \
		resize-0.5.5 \
		rgb-0.8.25 \
		rustc-hash-1.1.0 \
		shlex-0.1.1 \
		strsim-0.8.0 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		thread_local-1.1.0 \
		time-0.1.44 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vcpkg-0.2.11 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		weezl-0.1.3 \
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
