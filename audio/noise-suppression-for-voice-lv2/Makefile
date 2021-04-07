PORTNAME=	noise-suppression-for-voice
DISTVERSIONPREFIX=	v
DISTVERSION=	0.91-2
DISTVERSIONSUFFIX=	-g6466b34
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Real-time noise suppression plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	werman

CMAKE_OFF=	BUILD_VST_PLUGIN BUILD_LADSPA_PLUGIN # https://github.com/werman/noise-suppression-for-voice/issues/65

PLIST_FILES=	lib/lv2/rnnoise.lv2/manifest.ttl \
		lib/lv2/rnnoise.lv2/rnnoise.ttl \
		lib/lv2/rnnoise.lv2/rnnoise_lv2.so

.include <bsd.port.mk>
