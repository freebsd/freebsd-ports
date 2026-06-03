PORTNAME=	bchoppr
DISTVERSION=	1.12.8
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
USE_GNOME=	cairo
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	sjaehn
GH_PROJECT=	BChoppr
GH_TUPLE=	sjaehn:BWidgets:e04aede:BWidgets/src/BWidgets \
		lv2:pugl:9b5a0871c1a8771dbe204e60f437653a67abd42a:pugl/src/BWidgets/pugl

MAKEFILE=	makefile

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/BChoppr.lv2/LICENSE
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/BChoppr.lv2/BChoppr*.so

.include <bsd.port.mk>
