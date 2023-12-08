PORTNAME=	resvg-c-api
DISTVERSIONPREFIX=	v
DISTVERSION=	0.36.0
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SVG rendering library (C++/Qt API)
WWW=		https://github.com/RazrFalcon/resvg

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/../../LICENSE.txt

USES=		cargo
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	RazrFalcon
GH_PROJECT=	resvg

WRKSRC_SUBDIR=	crates/c-api

CARGO_CRATES=	adler-1.0.2 \
		arrayref-0.3.7 \
		arrayvec-0.7.4 \
		base64-0.21.4 \
		bitflags-1.3.2 \
		bytemuck-1.14.0 \
		cfg-if-1.0.0 \
		color_quant-1.1.0 \
		crc32fast-1.3.2 \
		data-url-0.3.0 \
		fdeflate-0.3.0 \
		flate2-1.0.27 \
		float-cmp-0.9.0 \
		fontconfig-parser-0.5.3 \
		fontdb-0.15.0 \
		gif-0.12.0 \
		imagesize-0.12.0 \
		jpeg-decoder-0.3.0 \
		kurbo-0.9.5 \
		libc-0.2.148 \
		log-0.4.20 \
		memmap2-0.8.0 \
		miniz_oxide-0.7.1 \
		once_cell-1.18.0 \
		pico-args-0.5.0 \
		png-0.17.10 \
		rctree-0.5.0 \
		rgb-0.8.36 \
		roxmltree-0.18.1 \
		rustybuzz-0.10.0 \
		simd-adler32-0.3.7 \
		simplecss-0.2.1 \
		siphasher-0.3.11 \
		slotmap-1.0.6 \
		smallvec-1.11.1 \
		strict-num-0.1.1 \
		svgtypes-0.12.0 \
		tiny-skia-0.11.2 \
		tiny-skia-path-0.11.2 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		ttf-parser-0.19.2 \
		unicode-bidi-0.3.13 \
		unicode-bidi-mirroring-0.1.0 \
		unicode-ccc-0.1.2 \
		unicode-properties-0.1.0 \
		unicode-script-0.5.5 \
		unicode-vo-0.1.0 \
		version_check-0.9.4 \
		weezl-0.1.7 \
		xmlparser-0.13.6 \
		xmlwriter-0.1.0

PLIST_FILES=	include/ResvgQt.h \
		include/resvg.h \
		lib/libresvg.a \
		lib/libresvg.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/resvg.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/ResvgQt.h ${STAGEDIR}${PREFIX}/include
	cd ${WRKDIR}/target && \
		${INSTALL_LIB} */release/libresvg.so ${STAGEDIR}${PREFIX}/lib && \
		${INSTALL_DATA} */release/libresvg.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
