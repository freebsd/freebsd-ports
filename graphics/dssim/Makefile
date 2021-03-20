# $FreeBSD$

PORTNAME=	dssim
DISTVERSION=	3.0.1
CATEGORIES=	graphics
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Image similarity comparison simulating human perception

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	adler-0.2.3 \
		ahash-0.4.7 \
		arrayvec-0.5.2 \
		autocfg-1.0.1 \
		bytemuck-1.4.1 \
		cc-1.0.66 \
		cfg-if-1.0.0 \
		const_fn-0.4.5 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.0 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.1 \
		crossbeam-utils-0.8.1 \
		dssim-core-3.0.0 \
		dunce-1.0.1 \
		either-1.6.1 \
		fallible_collections-0.4.0 \
		flate2-1.0.19 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.1 \
		foreign-types-shared-0.3.0 \
		getopts-0.2.21 \
		hashbrown-0.9.1 \
		hermit-abi-0.1.17 \
		imgref-1.7.1 \
		itertools-0.10.0 \
		jobserver-0.1.21 \
		lazy_static-1.4.0 \
		lcms2-5.4.0 \
		lcms2-sys-3.1.5 \
		libc-0.2.84 \
		load_image-2.12.1 \
		lodepng-3.4.3 \
		memoffset-0.6.1 \
		miniz_oxide-0.4.3 \
		mozjpeg-0.8.21 \
		mozjpeg-sys-0.10.11 \
		nasm-rs-0.2.0 \
		num-0.3.1 \
		num-bigint-0.3.1 \
		num-complex-0.3.1 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.3.2 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		pkg-config-0.3.19 \
		proc-macro2-1.0.24 \
		quote-1.0.8 \
		rayon-1.5.0 \
		rayon-core-1.9.0 \
		rexif-0.5.1 \
		rgb-0.8.25 \
		scopeguard-1.1.0 \
		syn-1.0.58 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1

.include <bsd.port.mk>
