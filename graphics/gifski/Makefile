PORTNAME=	gifski
DISTVERSION=	1.4.3
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

CARGO_CRATES=	adler-1.0.2 \
		ahash-0.4.7 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bindgen-0.54.0 \
		bitflags-1.2.1 \
		bytemuck-1.5.1 \
		cc-1.0.67 \
		cexpr-0.4.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clang-sys-0.29.3 \
		clap-2.33.3 \
		color_quant-1.1.0 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.0 \
		crossbeam-utils-0.8.3 \
		dunce-1.0.1 \
		fallible_collections-0.4.0 \
		ffmpeg-next-4.3.8 \
		ffmpeg-sys-next-4.3.5 \
		flate2-1.0.20 \
		gif-0.11.1 \
		gif-dispose-3.1.1 \
		gifsicle-1.92.4 \
		glob-0.3.0 \
		hashbrown-0.9.1 \
		hermit-abi-0.1.18 \
		imagequant-3.0.4-alpha.2 \
		imagequant-sys-3.0.4-alpha.2 \
		imgref-1.8.0 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.90 \
		libloading-0.5.2 \
		lodepng-3.4.5 \
		memchr-2.3.4 \
		miniz_oxide-0.4.4 \
		natord-1.0.9 \
		nom-5.1.2 \
		num_cpus-1.13.0 \
		openmp-sys-1.2.0-alpha.1 \
		pbr-1.0.4 \
		peeking_take_while-0.1.2 \
		pkg-config-0.3.19 \
		proc-macro2-1.0.24 \
		quick-error-2.0.0 \
		quote-1.0.9 \
		regex-1.4.5 \
		regex-syntax-0.6.23 \
		resize-0.7.2 \
		rgb-0.8.25 \
		rustc-hash-1.1.0 \
		shlex-0.1.1 \
		strsim-0.8.0 \
		textwrap-0.11.0 \
		time-0.1.44 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vcpkg-0.2.11 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		weezl-0.1.4 \
		wild-2.0.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_USE_GITHUB=	yes

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
