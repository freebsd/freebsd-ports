PORTNAME=	bchoppr
DISTVERSION=	1.10.8
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio stream chopping LV2 plugin

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gmake gnome pkgconfig xorg
USE_GITHUB=	yes
USE_GNOME=	cairo
USE_XORG=	x11

GH_ACCOUNT=	sjaehn
GH_PROJECT=	BChoppr

MAKEFILE=	makefile

PLIST_FILES=	lib/lv2/BChoppr.lv2/BChoppr.so \
		lib/lv2/BChoppr.lv2/BChoppr.ttl \
		lib/lv2/BChoppr.lv2/BChoppr_GUI.so \
		lib/lv2/BChoppr.lv2/manifest.ttl \
		lib/lv2/BChoppr.lv2/surface.png

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/BChoppr.lv2/LICENSE
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/BChoppr.lv2/BChoppr*.so

.include <bsd.port.mk>
