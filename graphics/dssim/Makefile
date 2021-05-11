PORTNAME=	dssim
DISTVERSION=	3.0.2
PORTREVISION=	1
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
		arrayvec-0.5.2 \
		arrayvec-0.7.0 \
		autocfg-1.0.1 \
		bytemuck-1.5.1 \
		cc-1.0.67 \
		cfg-if-1.0.0 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.4 \
		crossbeam-utils-0.8.4 \
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
		libc-0.2.94 \
		load_image-2.12.2 \
		lodepng-3.4.5 \
		memoffset-0.6.3 \
		miniz_oxide-0.4.4 \
		mozjpeg-0.9.0 \
		mozjpeg-sys-0.12.3 \
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
		proc-macro2-1.0.26 \
		quote-1.0.9 \
		rayon-1.5.0 \
		rayon-core-1.9.0 \
		rexif-0.7.0 \
		rgb-0.8.27 \
		scopeguard-1.1.0 \
		syn-1.0.72 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2

.include <bsd.port.mk>
