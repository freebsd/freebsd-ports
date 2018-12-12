# $FreeBSD$

PORTNAME=	triceratops
DISTVERSIONPREFIX=	lv2-v
DISTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/triceratops
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Polyphonic synthesizer LV2 plugin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang pkgconfig waf
USE_GNOME=	cairo cairomm gdkpixbuf2 gtk20 gtkmm24
NO_WRKSUBDIR=	yes
LDFLAGS_i386=	-Wl,-znotext

post-install:
		@${STRIP_CMD} \
			${STAGEDIR}${PREFIX}/lib/lv2/triceratops.lv2/triceratops.so \
			${STAGEDIR}${PREFIX}/lib/lv2/triceratops.lv2/triceratops_gui.so

.include <bsd.port.mk>
