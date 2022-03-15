PORTNAME=	gifski
DISTVERSION=	1.6.4
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Highest-quality GIF encoder based on pngquant

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	ImageOptim

CARGO_CRATES=	adler-1.0.2 \
		ahash-0.7.6 \
		ansi_term-0.12.1 \
		arrayvec-0.7.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bindgen-0.54.0 \
		bitflags-1.3.2 \
		bytemuck-1.7.3 \
		cc-1.0.72 \
		cexpr-0.4.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clang-sys-0.29.3 \
		clap-2.34.0 \
		color_quant-1.1.0 \
		crc32fast-1.3.0 \
		crossbeam-channel-0.5.2 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.6 \
		crossbeam-utils-0.8.6 \
		dunce-1.0.2 \
		either-1.6.1 \
		fallible_collections-0.4.4 \
		ffmpeg-next-4.4.0 \
		ffmpeg-sys-next-4.4.0 \
		flate2-1.0.22 \
		getrandom-0.2.4 \
		gif-0.11.3 \
		gif-dispose-3.1.1 \
		gifsicle-1.92.5 \
		glob-0.3.0 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		imagequant-4.0.0-beta.7 \
		imgref-1.9.1 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.112 \
		libloading-0.5.2 \
		lodepng-3.5.0 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		miniz_oxide-0.4.4 \
		natord-1.0.9 \
		noisy_float-0.2.0 \
		nom-5.1.2 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		once_cell-1.9.0 \
		pbr-1.0.4 \
		peeking_take_while-0.1.2 \
		pkg-config-0.3.24 \
		proc-macro2-1.0.36 \
		quick-error-2.0.1 \
		quote-1.0.14 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		resize-0.7.2 \
		rgb-0.8.31 \
		rustc-hash-1.1.0 \
		scopeguard-1.1.0 \
		shlex-0.1.1 \
		strsim-0.8.0 \
		textwrap-0.11.0 \
		thread_local-1.1.3 \
		time-0.1.43 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		vcpkg-0.2.15 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		wasi-0.10.3+wasi-snapshot-preview1 \
		weezl-0.1.5 \
		wild-2.0.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
