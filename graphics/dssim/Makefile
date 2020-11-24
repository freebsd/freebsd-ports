# $FreeBSD$

PORTNAME=	dssim
DISTVERSION=	2.11.4
PORTREVISION=	2
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
		autocfg-1.0.1 \
		bytemuck-1.4.1 \
		cc-1.0.61 \
		cfg-if-0.1.10 \
		crc32fast-1.2.0 \
		crossbeam-channel-0.4.4 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-utils-0.7.2 \
		dssim-core-2.11.4 \
		dunce-1.0.1 \
		either-1.6.1 \
		flate2-1.0.18 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.1 \
		foreign-types-shared-0.3.0 \
		getopts-0.2.21 \
		hermit-abi-0.1.17 \
		imgref-1.7.0 \
		itertools-0.9.0 \
		jobserver-0.1.21 \
		lazy_static-1.4.0 \
		lcms2-5.4.0 \
		lcms2-sys-3.1.5 \
		libc-0.2.79 \
		load_image-2.12.1 \
		lodepng-3.2.2 \
		maybe-uninit-2.0.0 \
		memoffset-0.5.6 \
		miniz_oxide-0.4.3 \
		mozjpeg-0.8.20 \
		mozjpeg-sys-0.10.11 \
		nasm-rs-0.2.0 \
		num-0.2.1 \
		num-bigint-0.2.6 \
		num-complex-0.2.4 \
		num-integer-0.1.43 \
		num-iter-0.1.41 \
		num-rational-0.2.4 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		pkg-config-0.3.18 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		rayon-1.4.1 \
		rayon-core-1.8.1 \
		rexif-0.5.0 \
		rgb-0.8.25 \
		scopeguard-1.1.0 \
		syn-1.0.44 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1

.include <bsd.port.mk>
