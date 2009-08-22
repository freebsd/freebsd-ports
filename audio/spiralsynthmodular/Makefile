# New ports collection makefile for:	spiralsynthmodular
# Date created:				2003 Jan 30
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	spiralsynthmodular
PORTVERSION=	0.2.2a
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/spiralmodular/spiralmodular/${PORTVERSION}%20%28Latest%20Version%29
DISTNAME=	spiralmodular-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An object orientated modular softsynth / sequencer / sampler

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		jackd:${PORTSDIR}/audio/jack
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		sndfile.1:${PORTSDIR}/audio/libsndfile

USE_XORG=	x11
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	FLTK_CONFIG="${FLTK_CONFIG}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

WRKSRC=	${WRKDIR}/spiralmodular-0.2.2

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's@(-O3|-ffast-math)@@g; \
		s|-Wall||; \
		s|CFLAGS="-pipe|CFLAGS="\$$\{CFLAGS\} ${PTHREAD_CFLAGS}|; \
		s|CXXFLAGS="-pipe|CXXFLAGS="\$$\{CXXFLAGS\} ${PTHREAD_CFLAGS}|; \
		s|^SpiralSound/Plugins/MidiPlugin/Makefile||; \
		s|MidiPlugin||' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

	@${REINPLACE_CMD} -e 's|-I/usr/X11R6/include|-I${LOCALBASE}/include|' \
		${WRKSRC}/SpiralSound/Plugins/LADSPAPlugin/Makefile.in

	@${REINPLACE_CMD} -e 's|O_SYNC|O_FSYNC|' \
		${WRKSRC}/SpiralSound/Midi.C

	@${REINPLACE_CMD} -e \
		's|True|true|; s|False|false|' \
		${WRKSRC}/SpiralSound/Plugins/MatrixPlugin/MatrixPlugin.C

	@${REINPLACE_CMD} -e \
		's|JackPort::||' \
		${WRKSRC}/SpiralSound/Plugins/JackPlugin/JackPlugin.h

	@${REINPLACE_CMD} -e \
		's|CVGUI::||' \
		${WRKSRC}/SpiralSound/Plugins/ControllerPlugin/ControllerPluginGUI.h

	@${REINPLACE_CMD} -e \
		's|Sample::||' \
		${WRKSRC}/SpiralSound/Sample.h

	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -E -e \
		's|-ldl||; \
		s|-lrt||; \
		s|^CC[[:space:]]*=.+$$|CC=${CC}|; \
		s|^CXX[[:space:]]*=.+$$|CXX=${CXX}|; \
		s|g\+\+|${CXX}|; \
		s,@FLTK_(C|CXX)FLAGS@,-I${LOCALBASE}/include,; \
		s|-lpthread|${PTHREAD_LIBS}|g'

.include <bsd.port.post.mk>
