PORTNAME=	bslizr
DISTVERSION=	1.2.16
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sequenced audio slicing effect LV2 plugin ("step sequencer effect")

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gmake gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	sjaehn
GH_PROJECT=	BSlizr
USE_GNOME=	cairo
USE_XORG=	x11

MAKEFILE=	makefile

PLIST_FILES=	lib/lv2/BSlizr.lv2/BSlizr.so \
		lib/lv2/BSlizr.lv2/BSlizr.ttl \
		lib/lv2/BSlizr.lv2/BSlizr_GUI.so \
		lib/lv2/BSlizr.lv2/manifest.ttl \
		lib/lv2/BSlizr.lv2/surface.png

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/BSlizr.lv2/LICENSE
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/BSlizr.lv2/BSlizr*.so

.include <bsd.port.mk>
