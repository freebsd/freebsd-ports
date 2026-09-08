PORTNAME=	resvg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.48.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SVG rendering library
WWW=		https://github.com/RazrFalcon/resvg

LICENSE=		MIT APACHE20
LICENSE_COMB=		dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	RazrFalcon

WRKSRC_SUBDIR=	crates/resvg

CARGO_CRATES=	adler2-2.0.1 \
		arrayref-0.3.9 \
		arrayvec-0.7.8 \
		autocfg-0.1.8 \
		autocfg-1.5.1 \
		base64-0.23.0 \
		bitflags-1.3.2 \
		bitflags-2.13.1 \
		bytemuck-1.25.2 \
		bytemuck_derive-1.11.0 \
		byteorder-lite-0.1.0 \
		cfg-if-1.0.4 \
		cloudabi-0.0.3 \
		color_quant-1.1.0 \
		crc32fast-1.5.0 \
		data-url-0.3.2 \
		either-1.17.0 \
		euclid-0.22.14 \
		fdeflate-0.3.7 \
		flate2-1.1.9 \
		float-cmp-0.9.0 \
		font-types-0.12.1 \
		fontconfig-parser-0.5.8 \
		fontdb-0.24.0 \
		fuchsia-cprng-0.1.1 \
		gif-0.14.2 \
		harfrust-0.12.0 \
		image-webp-0.2.4 \
		imagesize-0.15.0 \
		itertools-0.14.0 \
		kurbo-0.13.1 \
		libc-0.2.189 \
		log-0.4.33 \
		memchr-2.8.3 \
		memmap2-0.9.11 \
		miniz_oxide-0.8.9 \
		num-traits-0.2.19 \
		once_cell-1.21.4 \
		phf_codegen-0.7.24 \
		phf_generator-0.7.24 \
		phf_shared-0.7.24 \
		pico-args-0.5.0 \
		png-0.18.1 \
		polycool-0.4.0 \
		proc-macro2-1.0.107 \
		quick-error-2.0.1 \
		quote-1.0.47 \
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
		read-fonts-0.41.0 \
		rgb-0.8.53 \
		roxmltree-0.20.0 \
		roxmltree-0.21.1 \
		simd-adler32-0.3.10 \
		simplecss-0.2.2 \
		siphasher-0.2.3 \
		siphasher-1.0.3 \
		skrifa-0.44.0 \
		slotmap-1.1.1 \
		smallvec-1.15.2 \
		strict-num-0.1.1 \
		svgtypes-0.16.1 \
		syn-2.0.119 \
		tiny-skia-0.12.0 \
		tiny-skia-path-0.12.0 \
		tinyvec-1.12.0 \
		tinyvec_macros-0.1.1 \
		unicode-bidi-0.3.18 \
		unicode-ident-1.0.24 \
		unicode-script-0.5.8 \
		unicode-vo-0.1.0 \
		version_check-0.9.5 \
		weezl-0.1.12 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xmlwriter-0.1.0 \
		zune-core-0.5.1 \
		zune-jpeg-0.5.15

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
