PORTNAME=	dssim
DISTVERSION=	3.2.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Image similarity comparison simulating human perception

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	adler-1.0.2 \
		ahash-0.7.6 \
		aom-decode-0.2.1 \
		arrayvec-0.7.2 \
		autocfg-1.1.0 \
		avif-parse-0.13.2 \
		bitreader-0.3.5 \
		bytemuck-1.7.3 \
		byteorder-1.4.3 \
		cc-1.0.72 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		cmake-0.1.48 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.2 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.7 \
		crossbeam-utils-0.8.7 \
		dssim-core-3.2.0 \
		dunce-1.0.2 \
		either-1.6.1 \
		fallible_collections-0.4.4 \
		flate2-1.0.22 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.1 \
		foreign-types-shared-0.3.0 \
		getopts-0.2.21 \
		getrandom-0.2.4 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		imgref-1.9.1 \
		itertools-0.10.3 \
		jobserver-0.1.24 \
		lazy_static-1.4.0 \
		lcms2-5.4.1 \
		lcms2-sys-3.1.9 \
		libaom-sys-0.11.0 \
		libc-0.2.117 \
		libwebp-0.1.2 \
		libwebp-sys2-0.1.2 \
		load_image-2.16.2 \
		lodepng-3.6.0 \
		log-0.4.14 \
		memoffset-0.6.5 \
		miniz_oxide-0.4.4 \
		mozjpeg-0.9.1 \
		mozjpeg-sys-1.0.1 \
		nasm-rs-0.2.4 \
		num-0.4.0 \
		num-bigint-0.4.3 \
		num-complex-0.4.0 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.4.0 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		once_cell-1.9.0 \
		pkg-config-0.3.24 \
		proc-macro2-1.0.36 \
		quick-error-2.0.1 \
		quote-1.0.15 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		rexif-0.7.3 \
		rgb-0.8.31 \
		scopeguard-1.1.0 \
		static_assertions-1.1.0 \
		syn-1.0.86 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		yuv-0.1.4

.include <bsd.port.mk>
