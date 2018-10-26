# $FreeBSD$

PORTNAME=	speech-denoiser
DISTVERSION=	g20181007
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Speech denoise LV2 plugin based on RNNoise library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	librnnoise-nu.so:audio/rnnoise-nu

USES=		localbase:ldflags meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	lucianodato
GH_TAGNAME=	04cfba9

PLIST_FILES=	lib/lv2/sdenoise.lv2/manifest.ttl \
		lib/lv2/sdenoise.lv2/sdenoise.so \
		lib/lv2/sdenoise.lv2/sdenoise.ttl

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

SIMD_MESON_ON=		-Duse_sse=true

pre-configure:
	@cd ${WRKSRC} && ${LN} -s _build build

.include <bsd.port.mk>
