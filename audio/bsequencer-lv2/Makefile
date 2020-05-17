# $FreeBSD$

PORTNAME=	bsequencer
DISTVERSION=	1.4.2
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi channel MIDI step sequencer LV2 plugin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gmake gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	sjaehn
GH_PROJECT=	BSEQuencer
USE_GNOME=	cairo
USE_XORG=	x11

MAKEFILE=	makefile

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/lv2/BSEQuencer.lv2/BSEQuencer.so \
		${STAGEDIR}${PREFIX}/lib/lv2/BSEQuencer.lv2/BSEQuencer_GUI.so

.include <bsd.port.mk>
