PORTNAME=	dssim
DISTVERSION=	3.1.0
PORTREVISION=	5
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
		ahash-0.4.7 \
		aom-decode-0.2.0 \
		arrayvec-0.5.2 \
		arrayvec-0.7.0 \
		autocfg-1.0.1 \
		avif-parse-0.13.1 \
		bitreader-0.3.4 \
		bytemuck-1.5.1 \
		byteorder-1.4.3 \
		cc-1.0.68 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		cmake-0.1.45 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.5 \
		crossbeam-utils-0.8.5 \
		dssim-core-3.1.0 \
		dunce-1.0.1 \
		either-1.6.1 \
		fallible_collections-0.4.2 \
		flate2-1.0.20 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.1 \
		foreign-types-shared-0.3.0 \
		getopts-0.2.21 \
		hashbrown-0.9.1 \
		hermit-abi-0.1.18 \
		imgref-1.9.0 \
		itertools-0.10.0 \
		jobserver-0.1.22 \
		lazy_static-1.4.0 \
		lcms2-5.4.1 \
		lcms2-sys-3.1.8 \
		libaom-sys-0.9.1 \
		libc-0.2.95 \
		libwebp-0.1.2 \
		libwebp-sys2-0.1.2 \
		load_image-2.15.1 \
		lodepng-3.4.6 \
		log-0.4.14 \
		memoffset-0.6.4 \
		miniz_oxide-0.4.4 \
		mozjpeg-0.9.0 \
		mozjpeg-sys-0.12.4 \
		nasm-rs-0.2.0 \
		num-0.4.0 \
		num-bigint-0.4.0 \
		num-complex-0.4.0 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.4.0 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		pkg-config-0.3.19 \
		proc-macro2-1.0.27 \
		quick-error-2.0.1 \
		quote-1.0.9 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		rexif-0.7.3 \
		rgb-0.8.27 \
		scopeguard-1.1.0 \
		static_assertions-1.1.0 \
		syn-1.0.72 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vcpkg-0.2.13 \
		yuv-0.1.4

.include <bsd.port.mk>
