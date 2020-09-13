# $FreeBSD$

PORTNAME=	dssim
DISTVERSION=	2.11.3
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
		arrayvec-0.5.1 \
		autocfg-1.0.0 \
		bytemuck-1.2.0 \
		cc-1.0.58 \
		cfg-if-0.1.10 \
		crc32fast-1.2.0 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.3 \
		crossbeam-utils-0.7.2 \
		dssim-core-2.11.3 \
		dunce-1.0.1 \
		either-1.5.3 \
		flate2-1.0.17 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.1 \
		foreign-types-shared-0.3.0 \
		getopts-0.2.21 \
		hermit-abi-0.1.15 \
		imgref-1.7.0 \
		itertools-0.9.0 \
		jobserver-0.1.21 \
		lazy_static-1.4.0 \
		lcms2-5.3.1 \
		lcms2-sys-3.1.4 \
		libc-0.2.72 \
		load_image-2.12.1 \
		lodepng-3.2.1 \
		maybe-uninit-2.0.0 \
		memoffset-0.5.5 \
		miniz_oxide-0.4.1 \
		mozjpeg-0.8.19 \
		mozjpeg-sys-0.10.8 \
		nasm-rs-0.1.7 \
		num-0.2.1 \
		num-bigint-0.2.6 \
		num-complex-0.2.4 \
		num-integer-0.1.43 \
		num-iter-0.1.41 \
		num-rational-0.2.4 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		pkg-config-0.3.18 \
		proc-macro2-1.0.18 \
		quote-1.0.7 \
		rayon-1.3.1 \
		rayon-core-1.7.1 \
		rexif-0.5.0 \
		rgb-0.8.20 \
		scopeguard-1.1.0 \
		syn-1.0.34 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1

.include <bsd.port.mk>
