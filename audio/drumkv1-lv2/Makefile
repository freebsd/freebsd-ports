PORTNAME=	drumkv1
DISTVERSION=	1.1.0
CATEGORIES=	audio
MASTER_SITES=	SF
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Old-school drum-kit sampler: LV2 plugin and Jack app
WWW=		https://drumkv1.sourceforge.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile \
		liblo.so:audio/liblo

USES=		cmake compiler:c++17-lang desktop-file-utils gl localbase:ldflags pkgconfig qt:6 shared-mime-info
USE_QT=		base svg tools:build
USE_GL=		gl

CMAKE_OFF=	CONFIG_ALSA_MIDI

.include <bsd.port.mk>
