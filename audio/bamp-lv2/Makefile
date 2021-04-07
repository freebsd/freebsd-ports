PORTNAME=	bamp
DISTVERSION=	g20210212
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Basic testing plugin for using BWidgets for LV2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		compiler:c++11-lang gmake gnome pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	sjaehn
GH_PROJECT=	BAmp
GH_TAGNAME=	fe91b838f2ec801df55b12ffbdf6c6a4ab4ef093

MAKEFILE=	makefile

PLIST_FILES=	lib/lv2/BAmp.lv2/BAmp.so \
		lib/lv2/BAmp.lv2/BAmp.ttl \
		lib/lv2/BAmp.lv2/BAmp_GUI.so \
		lib/lv2/BAmp.lv2/manifest.ttl

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/BAmp.lv2/LICENSE
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/BAmp.lv2//BAmp*.so

.include <bsd.port.mk>
