PORTNAME=	gifski
DISTVERSION=	1.7.0
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
		arrayvec-0.7.2 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bindgen-0.59.2 \
		bitflags-1.3.2 \
		bytemuck-1.9.1 \
		cc-1.0.73 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		clang-sys-1.3.3 \
		clap-3.1.18 \
		clap_lex-0.2.0 \
		color_quant-1.1.0 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		dunce-1.0.2 \
		either-1.6.1 \
		fallible_collections-0.4.4 \
		ffmpeg-next-4.4.0 \
		flate2-1.0.24 \
		getrandom-0.2.6 \
		gif-0.11.3 \
		gif-dispose-3.1.1 \
		gifsicle-1.92.5 \
		glob-0.3.0 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		imagequant-4.0.0 \
		imgref-1.9.1 \
		indexmap-1.8.2 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.126 \
		libloading-0.7.3 \
		lodepng-3.6.2 \
		loop9-0.1.3 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.5.3 \
		natord-1.0.9 \
		noisy_float-0.2.0 \
		nom-7.1.1 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		once_cell-1.12.0 \
		os_str_bytes-6.1.0 \
		pbr-1.0.4 \
		peeking_take_while-0.1.2 \
		pkg-config-0.3.25 \
		proc-macro2-1.0.39 \
		quick-error-2.0.1 \
		quote-1.0.18 \
		rayon-1.5.3 \
		rayon-core-1.9.3 \
		regex-1.5.6 \
		regex-syntax-0.6.26 \
		resize-0.7.3 \
		rgb-0.8.32 \
		rustc-hash-1.1.0 \
		scopeguard-1.1.0 \
		shlex-1.1.0 \
		strsim-0.10.0 \
		termcolor-1.1.3 \
		textwrap-0.15.0 \
		thread_local-1.1.4 \
		time-0.1.43 \
		unicode-ident-1.0.0 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		weezl-0.1.6 \
		wild-2.0.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ffmpeg-sys-next@git+https://github.com/kornelski/rust-ffmpeg-sys-1?rev=78458039d5fac99354f9cb078869f3be3f3af5fb\#78458039d5fac99354f9cb078869f3be3f3af5fb

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
