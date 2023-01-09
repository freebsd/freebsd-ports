PORTNAME=	resvg-c-api
DISTVERSIONPREFIX=	v
DISTVERSION=	0.28.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SVG rendering library (C++/Qt API)
WWW=		https://github.com/RazrFalcon/resvg

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

USES=		cargo
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	RazrFalcon
GH_PROJECT=	resvg

WRKSRC_SUBDIR=	c-api

CARGO_CRATES=	adler-1.0.2 \
		arrayref-0.3.6 \
		arrayvec-0.7.2 \
		base64-0.13.1 \
		bitflags-1.3.2 \
		bytemuck-1.12.1 \
		cfg-if-1.0.0 \
		color_quant-1.1.0 \
		crc32fast-1.3.2 \
		data-url-0.2.0 \
		flate2-1.0.24 \
		float-cmp-0.9.0 \
		fontconfig-parser-0.5.1 \
		fontdb-0.10.0 \
		gif-0.11.4 \
		imagesize-0.10.1 \
		jpeg-decoder-0.3.0 \
		kurbo-0.8.3 \
		libc-0.2.137 \
		log-0.4.17 \
		memmap2-0.5.8 \
		miniz_oxide-0.5.4 \
		once_cell-1.16.0 \
		pico-args-0.5.0 \
		png-0.17.6 \
		rctree-0.5.0 \
		rgb-0.8.34 \
		roxmltree-0.15.1 \
		rustybuzz-0.6.0 \
		simplecss-0.2.1 \
		siphasher-0.3.10 \
		smallvec-1.10.0 \
		strict-num-0.1.0 \
		svgtypes-0.8.2 \
		tiny-skia-0.8.2 \
		tiny-skia-path-0.8.2 \
		ttf-parser-0.17.1 \
		unicode-bidi-0.3.8 \
		unicode-bidi-mirroring-0.1.0 \
		unicode-ccc-0.1.2 \
		unicode-general-category-0.6.0 \
		unicode-script-0.5.5 \
		unicode-vo-0.1.0 \
		weezl-0.1.7 \
		xmlparser-0.13.5

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
