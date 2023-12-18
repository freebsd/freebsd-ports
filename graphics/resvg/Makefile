PORTNAME=	resvg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.37.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SVG rendering library
WWW=		https://github.com/RazrFalcon/resvg

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	RazrFalcon

WRKSRC_SUBDIR=	crates/resvg

CARGO_CRATES=	adler-1.0.2 \
		arrayref-0.3.7 \
		arrayvec-0.7.4 \
		base64-0.21.5 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		bytemuck-1.14.0 \
		cfg-if-1.0.0 \
		color_quant-1.1.0 \
		crc32fast-1.3.2 \
		data-url-0.3.1 \
		fdeflate-0.3.1 \
		flate2-1.0.28 \
		float-cmp-0.9.0 \
		fontconfig-parser-0.5.3 \
		fontdb-0.16.0 \
		gif-0.12.0 \
		imagesize-0.12.0 \
		jpeg-decoder-0.3.0 \
		kurbo-0.9.5 \
		libc-0.2.151 \
		log-0.4.20 \
		memmap2-0.9.2 \
		miniz_oxide-0.7.1 \
		once_cell-1.19.0 \
		pico-args-0.5.0 \
		png-0.17.10 \
		rctree-0.5.0 \
		rgb-0.8.37 \
		roxmltree-0.18.1 \
		roxmltree-0.19.0 \
		rustybuzz-0.12.1 \
		simd-adler32-0.3.7 \
		simplecss-0.2.1 \
		siphasher-0.3.11 \
		slotmap-1.0.7 \
		smallvec-1.11.2 \
		strict-num-0.1.1 \
		svgtypes-0.13.0 \
		tiny-skia-0.11.3 \
		tiny-skia-path-0.11.3 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		ttf-parser-0.20.0 \
		unicode-bidi-0.3.14 \
		unicode-bidi-mirroring-0.1.0 \
		unicode-ccc-0.1.2 \
		unicode-properties-0.1.0 \
		unicode-script-0.5.5 \
		unicode-vo-0.1.0 \
		version_check-0.9.4 \
		weezl-0.1.7 \
		xmlparser-0.13.6 \
		xmlwriter-0.1.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
