PORTNAME=	bchoppr
DISTVERSION=	1.12.6-11
DISTVERSIONSUFFIX=	-g9a463da
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio stream chopping LV2 plugin
WWW=		https://github.com/sjaehn/BChoppr

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
GH_TUPLE=	sjaehn:BWidgets:89d0765:BWidgets/src/BWidgets

MAKEFILE=	makefile

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/BChoppr.lv2/LICENSE
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/BChoppr.lv2/BChoppr*.so

.include <bsd.port.mk>
