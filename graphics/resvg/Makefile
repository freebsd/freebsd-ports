PORTNAME=	resvg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.41.0
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
		base64-0.22.0 \
		bitflags-1.3.2 \
		bitflags-2.5.0 \
		bytemuck-1.15.0 \
		cfg-if-1.0.0 \
		color_quant-1.1.0 \
		crc32fast-1.4.0 \
		data-url-0.3.1 \
		fdeflate-0.3.4 \
		flate2-1.0.28 \
		float-cmp-0.9.0 \
		fontconfig-parser-0.5.6 \
		fontdb-0.16.2 \
		gif-0.13.1 \
		imagesize-0.12.0 \
		jpeg-decoder-0.3.1 \
		kurbo-0.11.0 \
		libc-0.2.153 \
		log-0.4.21 \
		memmap2-0.9.4 \
		miniz_oxide-0.7.2 \
		once_cell-1.19.0 \
		pico-args-0.5.0 \
		png-0.17.13 \
		rgb-0.8.37 \
		roxmltree-0.19.0 \
		rustybuzz-0.13.0 \
		simd-adler32-0.3.7 \
		simplecss-0.2.1 \
		siphasher-1.0.1 \
		slotmap-1.0.7 \
		smallvec-1.13.2 \
		strict-num-0.1.1 \
		svgtypes-0.15.0 \
		tiny-skia-0.11.4 \
		tiny-skia-path-0.11.4 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		ttf-parser-0.20.0 \
		unicode-bidi-0.3.15 \
		unicode-bidi-mirroring-0.2.0 \
		unicode-ccc-0.2.0 \
		unicode-properties-0.1.1 \
		unicode-script-0.5.6 \
		unicode-vo-0.1.0 \
		version_check-0.9.4 \
		weezl-0.1.8 \
		xmlwriter-0.1.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
