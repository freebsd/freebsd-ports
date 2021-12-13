PORTNAME=	fatfrog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High gain amplifier LV2 audio plugin

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gmake gnome localbase pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11
USE_BINUTILS=	yes # linking needs some GNU features, fails on 12 without this, see https://github.com/brummer10/GxPlugins.lv2/issues/9

USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	FatFrog.lv2
GH_TUPLE=	brummer10:libxputty:70c910d:libxputty/libxputty

MAKE_ARGS=	INSTALL_DIR=${PREFIX}/lib/lv2

PLIST_FILES=	lib/lv2/FatFrog.lv2/FatFrog.so \
		lib/lv2/FatFrog.lv2/FatFrog.ttl \
		lib/lv2/FatFrog.lv2/FatFrog_ui.so \
		lib/lv2/FatFrog.lv2/manifest.ttl

.include <bsd.port.mk>
