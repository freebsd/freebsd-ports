# $FreeBSD$

PORTNAME=	eq10q
DISTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parametric equalizer LV2 audio plugin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lang dos2unix gnome localbase:ldflags \
		pkgconfig
USE_GNOME=	glib20 gtk20 gtkmm24 gdkpixbuf2 atkmm cairo cairomm pangomm
DOS2UNIX_FILES=	dsp/vu.h

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	SSE

SSE_CMAKE_ON=	-DPORT_SIMD_FLAGS:STRING="-msse -mfpmath=sse"

post-patch:
	@${REINPLACE_CMD} -e 's/pow10(/pow(10,/g' \
		${WRKSRC}/gui/widgets/*.cpp
	# fix for audio/lv2 1.18.0 based on: https://sourceforge.net/p/eq10q/bugs/23/
.for f in gui/eq10q_ui.cpp gui/dyn_ui.cpp gui/bassup_ui.cpp gui/midside_ui.cpp
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's/const _LV2UI_Descriptor/const LV2UI_Descriptor/' ${f}
.endfor

.include <bsd.port.mk>
