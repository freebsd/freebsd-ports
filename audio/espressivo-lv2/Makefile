PORTNAME=	espressivo
DISTVERSION=	g20190421
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugin bundle to handle expressive events

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint:audio/lv2lint \
		sord_validate:devel/sord

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMusicKontrollers
GH_PROJECT=	${PORTNAME}.lv2
GH_TAGNAME=	de1d07c

PLIST_FILES=	lib/lv2/espressivo.lv2/espressivo.so \
		lib/lv2/espressivo.lv2/espressivo.ttl \
		lib/lv2/espressivo.lv2/manifest.ttl

.include <bsd.port.mk>
