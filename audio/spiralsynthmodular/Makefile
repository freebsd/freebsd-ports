# New ports collection makefile for:	spiralsynthmodular
# Date created:				2003 Jan 30
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	spiralsynthmodular
PORTVERSION=	0.2.2a
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	spiralmodular
DISTNAME=	spiralmodular-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	An object orientated modular softsynth / sequencer / sampler

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		sndfile.1:${PORTSDIR}/audio/libsndfile

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	FLTK_CONFIG="${FLTK_CONFIG}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} -L${LOCALBASE}/lib"

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

WRKSRC=	${WRKDIR}/spiralmodular-0.2.2

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on amd64 or ia64"
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

	@${REINPLACE_CMD} -e 's|-I/usr/X11R6/include|-I${LOCALBASE}/include -I${X11BASE}/include|' \
		${WRKSRC}/SpiralSound/Plugins/LADSPAPlugin/Makefile.in

	@${REINPLACE_CMD} -e 's|O_SYNC|O_FSYNC|' \
		${WRKSRC}/SpiralSound/Midi.C

	@${REINPLACE_CMD} -e \
		's|True|true|; s|False|false|' \
		${WRKSRC}/SpiralSound/Plugins/MatrixPlugin/MatrixPlugin.C

	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -E -e \
		's|-ldl||; \
		s|^CC[[:space:]]*=.+$$|CC=${CC}|; \
		s|^CXX[[:space:]]*=.+$$|CXX=${CXX}|; \
		s|g\+\+|${CXX}|; \
		s,@FLTK_(C|CXX)FLAGS@,-I${X11BASE}/include -I${LOCALBASE}/include,; \
		s|-lpthread|${PTHREAD_LIBS}|g'

.include <bsd.port.post.mk>
