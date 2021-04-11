PORTNAME=	littlefly
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Overdrive/distortion pedal simulation LV2 plugin

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		compiler:c11 gmake gnome localbase pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11
USE_BINUTILS=	yes # linking needs some GNU features, fails on 12 without this, see https://github.com/brummer10/GxPlugins.lv2/issues/9

USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	LittleFly.lv2
GH_TUPLE=	brummer10:libxputty:70c910d:libxputty/libxputty

PLIST_FILES=	lib/lv2/LittleFly.lv2/LittleFly.so \
		lib/lv2/LittleFly.lv2/LittleFly.ttl \
		lib/lv2/LittleFly.lv2/LittleFly_ui.so \
		lib/lv2/LittleFly.lv2/manifest.ttl

.include <bsd.port.mk>
