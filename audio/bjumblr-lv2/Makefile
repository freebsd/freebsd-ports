PORTNAME=	bjumblr
DISTVERSION=	1.6.6-8
DISTVERSIONSUFFIX=	-g3e18941
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pattern-controlled audio stream / sample re-sequencer LV2 plugin

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:c++11-lang gmake gnome pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	sjaehn
GH_PROJECT=	BJumblr

MAKEFILE=	makefile

CFLAGS+=	-DWWW_BROWSER_CMD=\\\"${LOCALBASE}/bin/xdg-open\\\"

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/BJumblr.lv2/LICENSE
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/BJumblr.lv2/BJumblr*.so

.include <bsd.port.mk>
