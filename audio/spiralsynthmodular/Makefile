# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	spiralsynthmodular
PORTVERSION=	0.2.2a
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	SF/spiralmodular/spiralmodular/${PORTVERSION}%20%28Latest%20Version%29
DISTNAME=	spiralmodular-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented modular softsynth/sequencer/sampler

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa \
		jackd:audio/jack
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libsndfile.so:audio/libsndfile

USES=		xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${FLTK_CONFIG}"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/spiralmodular-0.2.2

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=-O3 -ffast-math

post-patch:
	@${REINPLACE_CMD} -E -e 's@(-O3|-ffast-math)@@g; \
		s|-Wall||; \
		s|CFLAGS="-pipe|CFLAGS="\$$\{CFLAGS\}|; \
		s|CXXFLAGS="-pipe|CXXFLAGS="\$$\{CXXFLAGS\}|; \
		s|^SpiralSound/Plugins/MidiPlugin/Makefile||; \
		s|MidiPlugin||' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-I/usr/X11R6/include|-I${LOCALBASE}/include|' \
		${WRKSRC}/SpiralSound/Plugins/LADSPAPlugin/Makefile.in
	@${REINPLACE_CMD} -e 's|O_SYNC|O_FSYNC|' \
		${WRKSRC}/SpiralSound/Midi.C
	@${REINPLACE_CMD} -e 's|True|true|; s|False|false|' \
		${WRKSRC}/SpiralSound/Plugins/MatrixPlugin/MatrixPlugin.C
	@${REINPLACE_CMD} -e 's|JackPort::||' \
		${WRKSRC}/SpiralSound/Plugins/JackPlugin/JackPlugin.h
	@${REINPLACE_CMD} -e 's|CVGUI::||' \
		${WRKSRC}/SpiralSound/Plugins/ControllerPlugin/ControllerPluginGUI.h
	@${REINPLACE_CMD} -e 's|Sample::||' \
		${WRKSRC}/SpiralSound/Sample.h
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -E -e \
		's,-l(dl|rt),,; s|g\+\+|$$(CXX)|; \
		/^(CC|CXX)[[:space:]]*=.+$$/d; \
		s,@FLTK_(C|CXX)FLAGS@,-I${LOCALBASE}/include,; \
		s,(bin|lib)dir),DESTDIR)$$(&,'
	@${FIND} ${WRKSRC} -type f -name "*.C" -o -name "*.cpp" -o -name "*.h" \
		| ${XARGS} ${REINPLACE_CMD} -e '/^#include <FL/s|.h>$$|.H>|; \
		/^#include "FL/s|.h"$$|.H"|; \
		s|fl_file_chooser.H|Fl_File_Chooser.H|g'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/SpiralPlugins/*.so

.include <bsd.port.mk>
