PORTNAME=	eteroj
DISTVERSION=	0.10.0
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OSC injection/ejection from/to UDP/TCP/Serial for LV2

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint:audio/lv2lint
LIB_DEPENDS=	libsratom-0.so:audio/sratom \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libuv.so:devel/libuv

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMusicKontrollers
GH_PROJECT=	eteroj.lv2

PLIST_FILES=	lib/lv2/eteroj.lv2/eteroj.so \
		lib/lv2/eteroj.lv2/eteroj.ttl \
		lib/lv2/eteroj.lv2/manifest.ttl

.include <bsd.port.mk>
