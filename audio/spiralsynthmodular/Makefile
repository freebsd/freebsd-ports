# New ports collection makefile for:	spiralsynthmodular
# Date created:				2003 Jan 30
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	spiralsynthmodular
PORTVERSION=	0.2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	spiralmodular
DISTNAME=	spiralmodular-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	FLTK_CONFIG="${FLTK_CONFIG}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's@(-O3|-ffast-math)@@g; \
		s|CFLAGS="-pipe|CFLAGS="\$$\{CFLAGS\} ${PTHREAD_CFLAGS}|; \
		s|CXXFLAGS="-pipe|CXXFLAGS="\$$\{CXXFLAGS\} ${PTHREAD_CFLAGS}|' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-I/usr/X11R6/include|-I${LOCALBASE}/include -I${X11BASE}/include|' \
		${WRKSRC}/SpiralSound/Plugins/LADSPAPlugin/Makefile.in
	@${REINPLACE_CMD} -e 's|O_SYNC|O_FSYNC|' \
		${WRKSRC}/SpiralSound/Midi.C
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -E -e \
		's|-ldl||; \
		s@^C(C|XX)[[:space:]]*=.+$$@@; \
		s|g\+\+|${CXX}|; \
		s,@FLTK_(C|CXX)FLAGS@,-I${X11BASE}/include,; \
		s|-lpthread|${PTHREAD_LIBS}|g'

.include <bsd.port.mk>
