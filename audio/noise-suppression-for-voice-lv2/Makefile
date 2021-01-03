# $FreeBSD$

PORTNAME=	noise-suppression-for-voice
DISTVERSIONPREFIX=	v
DISTVERSION=	0.91-1
DISTVERSIONSUFFIX=	-ge391a9b
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Real-time noise suppression plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	werman

CMAKE_OFF=	BUILD_VST_PLUGIN BUILD_LADSPA_PLUGIN # https://github.com/werman/noise-suppression-for-voice/issues/65

PLIST_FILES=	lib/lv2/rnnoise.lv2/librnnoise_lv2.so \
		lib/lv2/rnnoise.lv2/manifest.ttl \
		lib/lv2/rnnoise.lv2/rnnoise.ttl

.include <bsd.port.mk>
