PORTNAME=	timely
DISTVERSION=	g20190412
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utility header for time-based LV2 plugins

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint:audio/lv2lint \
		sord_validate:devel/sord

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMusicKontrollers
GH_PROJECT=	timely.lv2
GH_TAGNAME=	3846b5a

PLIST_FILES=	lib/lv2/timely.lv2/manifest.ttl \
		lib/lv2/timely.lv2/timely.so \
		lib/lv2/timely.lv2/timely.ttl

.include <bsd.port.mk>
