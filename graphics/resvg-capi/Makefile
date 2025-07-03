PORTNAME=	resvg-c-api
DISTVERSION=	0.45.0
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SVG rendering library (C++/Qt API)
WWW=		https://github.com/linebender/resvg

LICENSE=		MIT APACHE20
LICENSE_COMB=		dual
LICENSE_FILE_APACHE20=	${WRKSRC}/../../LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/../../LICENSE-MIT

USES=		cargo
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	linebender
GH_PROJECT=	resvg

WRKSRC_SUBDIR=	crates/c-api

CARGO_CRATES=	adler2-2.0.0 \
		arrayref-0.3.9 \
		arrayvec-0.7.6 \
		autocfg-0.1.8 \
		autocfg-1.4.0 \
		base64-0.22.1 \
		bitflags-1.3.2 \
		bitflags-2.8.0 \
		bytemuck-1.21.0 \
		byteorder-lite-0.1.0 \
		cfg-if-1.0.0 \
		cloudabi-0.0.3 \
		color_quant-1.1.0 \
		core_maths-0.1.1 \
		crc32fast-1.4.2 \
		data-url-0.3.1 \
		either-1.14.0 \
		fdeflate-0.3.7 \
		flate2-1.1.0 \
		float-cmp-0.9.0 \
		fontconfig-parser-0.5.7 \
		fontdb-0.23.0 \
		fuchsia-cprng-0.1.1 \
		gif-0.13.1 \
		image-webp-0.2.0 \
		imagesize-0.13.0 \
		itertools-0.14.0 \
		kurbo-0.11.1 \
		libc-0.2.170 \
		libm-0.2.11 \
		log-0.4.26 \
		memmap2-0.9.5 \
		miniz_oxide-0.8.5 \
		once_cell-1.20.3 \
		phf-0.7.24 \
		phf_codegen-0.7.24 \
		phf_generator-0.7.24 \
		phf_shared-0.7.24 \
		pico-args-0.5.0 \
		png-0.17.16 \
		quick-error-2.0.1 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		rgb-0.8.50 \
		roxmltree-0.20.0 \
		rustybuzz-0.20.1 \
		simd-adler32-0.3.7 \
		simplecss-0.2.2 \
		siphasher-0.2.3 \
		siphasher-1.0.1 \
		slotmap-1.0.7 \
		smallvec-1.14.0 \
		strict-num-0.1.1 \
		svgtypes-0.15.3 \
		tiny-skia-0.11.4 \
		tiny-skia-path-0.11.4 \
		tinyvec-1.8.1 \
		tinyvec_macros-0.1.1 \
		ttf-parser-0.25.1 \
		unicode-bidi-0.3.18 \
		unicode-bidi-mirroring-0.4.0 \
		unicode-ccc-0.4.0 \
		unicode-properties-0.1.3 \
		unicode-script-0.5.7 \
		unicode-vo-0.1.0 \
		version_check-0.9.5 \
		weezl-0.1.8 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xmlwriter-0.1.0 \
		zune-core-0.4.12 \
		zune-jpeg-0.4.14

PLIST_FILES=	include/ResvgQt.h \
		include/resvg.h \
		lib/libresvg.a \
		lib/libresvg.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/resvg.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/ResvgQt.h ${STAGEDIR}${PREFIX}/include
	cd ${WRKDIR}/target && \
		${INSTALL_LIB} release/libresvg.so ${STAGEDIR}${PREFIX}/lib && \
		${INSTALL_DATA} release/libresvg.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
