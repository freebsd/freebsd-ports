# New ports collection makefile for:	spiralsynth
# Date created:				2000-09-05
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	spiralsynth
PORTVERSION=	0.1.7
CATEGORIES=	audio
MASTER_SITES=	http://www.pawfal.org/SpiralSynth/dload/
DISTNAME=	SpiralSynth-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	MIDI-capable synthesizer for X

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

DOC_FILES=	CHANGES COPYING README

post-patch:
.for ii in \
        Makefile.in \
        PluginLink.sh \
        SpiralInfo.C \
        SpiralSound/Midi.h \
        SpiralSound/Output.h \
        SpiralSound/SpiralInfo.h \
        SpiralSound/Synth.C \
        SpiralSound/Synth.h \
        SpiralSound/_SynthInfo.C \
        Synth.h
	${MV} ${WRKSRC}/${ii} ${WRKSRC}/${ii}.orig
	${SED} -e 's|-O3|${PTHREAD_CFLAGS}|g ; \
			s|CC	=|CC?	=|g ; \
			s|CFLAGS =|CFLAGS +=|g ; \
			s|CXX	=|CXX?	=|g ; \
			s|CXXFLAGS=|CXXFLAGS+=|g ; \
			s|LINK	=	g++|LINK	=	${CXX}|g ; \
			s|-lm|${PTHREAD_LIBS} -lm|g ; \
			s|/usr/X11R6|${X11BASE}|g ; \
			s|iostream.h|iostream|g ;\
			s|<strstream>|<sstream>|g ;\
			s|machine/soundcard|sys/soundcard|g' \
			< ${WRKSRC}/${ii}.orig \
			> ${WRKSRC}/${ii}
.endfor
# Use as a plugin to SpiralLoops 2.0.0 results in "Can't open audio driver."
.if defined(PLUGIN)
	${MV} ${WRKSRC}/Synth.C ${WRKSRC}/Synth.C.orig
	${SED} -e 's|^//#define PLUGIN|#define PLUGIN|g' \
		< ${WRKSRC}/Synth.C.orig > ${WRKSRC}/Synth.C

post-build:
	cd ${WRKSRC}; ${SH} ./PluginLink.sh
.endif		# defined(PLUGIN)

pre-install:
.if defined(PLUGIN)
	${ECHO_CMD} lib/SpiralSynth.so > ${PLIST}
.else
	${ECHO_CMD} bin/SpiralSynth > ${PLIST}
.endif
.if !defined(NOPORTDOCS)
.for ii in ${DOC_FILES}
	${ECHO_CMD} share/doc/spiralsynth/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/spiralsynth >> ${PLIST}
.endif

do-install:
.if defined(PLUGIN)
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralSynth.so ${PREFIX}/lib
.else
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralSynth ${PREFIX}/bin
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
