PORTNAME=	resvg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.43.0
PORTREVISION=	1
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
		arrayref-0.3.8 \
		arrayvec-0.7.6 \
		base64-0.22.1 \
		bitflags-1.3.2 \
		bitflags-2.6.0 \
		bytemuck-1.17.0 \
		byteorder-lite-0.1.0 \
		cfg-if-1.0.0 \
		color_quant-1.1.0 \
		core_maths-0.1.0 \
		crc32fast-1.4.2 \
		data-url-0.3.1 \
		fdeflate-0.3.4 \
		flate2-1.0.31 \
		float-cmp-0.9.0 \
		fontconfig-parser-0.5.7 \
		fontdb-0.21.0 \
		gif-0.13.1 \
		image-webp-0.1.3 \
		imagesize-0.13.0 \
		kurbo-0.11.0 \
		libc-0.2.157 \
		libm-0.2.8 \
		log-0.4.22 \
		memmap2-0.9.4 \
		miniz_oxide-0.7.4 \
		once_cell-1.19.0 \
		pico-args-0.5.0 \
		png-0.17.13 \
		quick-error-2.0.1 \
		rgb-0.8.48 \
		roxmltree-0.20.0 \
		rustybuzz-0.18.0 \
		simd-adler32-0.3.7 \
		simplecss-0.2.1 \
		siphasher-1.0.1 \
		slotmap-1.0.7 \
		smallvec-1.13.2 \
		strict-num-0.1.1 \
		svgtypes-0.15.1 \
		tiny-skia-0.11.4 \
		tiny-skia-path-0.11.4 \
		tinyvec-1.8.0 \
		tinyvec_macros-0.1.1 \
		ttf-parser-0.24.1 \
		unicode-bidi-0.3.15 \
		unicode-bidi-mirroring-0.3.0 \
		unicode-ccc-0.3.0 \
		unicode-properties-0.1.1 \
		unicode-script-0.5.6 \
		unicode-vo-0.1.0 \
		version_check-0.9.5 \
		weezl-0.1.8 \
		xmlwriter-0.1.0 \
		zune-core-0.4.12 \
		zune-jpeg-0.4.13

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
