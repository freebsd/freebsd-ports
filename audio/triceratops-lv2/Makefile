PORTNAME=	triceratops
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0_Oct_2022
CATEGORIES=	audio
MASTER_SITES=	SF/triceratops
PKGNAMESUFFIX=	-lv2
DISTNAME=	${PORTNAME}_${DISTVERSIONFULL}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Polyphonic synthesizer LV2 plugin
WWW=		https://sourceforge.net/projects/triceratops

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang gnome pkgconfig python:build waf
USE_GNOME=	cairo cairomm gdkpixbuf2 gtk20 gtkmm24

WRKSRC=		${WRKDIR}/${PORTNAME}#-lv2-0.5.0.o.2022

post-patch:
	${REINPLACE_CMD} -e 's|"/usr/lib/lv2"|"${PREFIX}/lib/lv2"|' ${WRKSRC}/wscript

post-install:
		@${STRIP_CMD} \
			${STAGEDIR}${PREFIX}/lib/lv2/triceratops.lv2/triceratops.so \
			${STAGEDIR}${PREFIX}/lib/lv2/triceratops.lv2/triceratops_gui.so

.include <bsd.port.mk>
