PORTNAME=	bschaffl
DISTVERSION=	1.4.10
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Groove quantizer LV2 MIDI plugin
WWW=		https://github.com/sjaehn/BSchaffl

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile

USES=		compiler:c++11-lang gmake gnome pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	sjaehn
GH_PROJECT=	BSchaffl

MAKEFILE=	makefile

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/BSchaffl.lv2/LICENSE
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/BSchaffl.lv2/BSchaffl*.so

.include <bsd.port.mk>
