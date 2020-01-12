# $FreeBSD$

PORTNAME=	so-synth
DISTVERSIONPREFIX=	upstream/
DISTVERSION=	1.5
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unofficial LV2 ports of 50m30n3's synthesizers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	jeremysalwen
GH_PROJECT=	So-synth-LV2

ALL_TARGET=	libsosynth.so

MAKE_ARGS=	INSTALLDIR=${STAGEDIR}${PREFIX}/lib/lv2/
BINARY_ALIAS=	gcc=${CC}

PLIST_FILES=	lib/lv2/so-synth.lv2/libsosynth.so \
		lib/lv2/so-synth.lv2/manifest.ttl \
		lib/lv2/so-synth.lv2/so-404.ttl \
		lib/lv2/so-synth.lv2/so-666.ttl \
		lib/lv2/so-synth.lv2/so-kl5.ttl

.include <bsd.port.mk>
