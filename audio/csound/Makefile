# New ports collection makefile for:	csound
# Date created:				2000-10-11
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	csound
PORTVERSION=	5.15.0
CATEGORIES=	audio lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}${PORTVERSION:R} \
		SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}${PORTVERSION:R}/manual:manual
DISTNAME=	${PORTNAME:S/c/C/}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	csound

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sound synthesizer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13 \
		${LOCALBASE}/include/gmm/gmm.h:${PORTSDIR}/math/gmm++ \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

OPTIONS=	ALSA "Build ALSA I/O module" off \
		DSSI "Build DSSI/LADSPA host opcodes" off \
		FLUIDSYNTH "Building FluidSynth opcodes" off \
		JACK "Build Jack I/O module and opcodes" off \
		OSC "Build OSC opcodes" off \
		PORTAUDIO "Build the PortAudio I/O module" off \
		PULSEAUDIO "Build the PulseAudio I/O module" off \
		FLTKGUI "Build FLTK plugin and GUI" on

CONFLICTS_INSTALL=	outguess-*

USE_PYTHON=	2.6+
USE_BISON=	build
USE_GETTEXT=	yes
USE_SCONS=	yes
SCONS_BUILDENV=	PATH=${LOCALBASE}/bin:$$PATH
SCONS_ARGS=	prefix="${PREFIX}" CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		buildCsoundAC=0 buildCsoundVST=0 buildInterfaces=1 \
		buildRelease=1 buildVirtual=1 dynamicCsoundLibrary=1 \
		install=1 noDebug=1 useDouble=1 \
		useGettext=1 usePortMIDI=0
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
SCONS_ARGS+=	useALSA=1
PLIST_SUB+=	ALSA=""
ALSA_H=		alsa/asoundlib.h
.else
SCONS_ARGS+=	useALSA=0
PLIST_SUB+=	ALSA="@comment "
ALSA_H=		##alsa/asoundlib.h##
.endif

.if defined(WITH_DSSI)
BUILD_DEPENDS+=	dssi>=0:${PORTSDIR}/audio/dssi
RUN_DEPENDS+=	dssi>=0:${PORTSDIR}/audio/dssi
SCONS_ARGS+=	buildDSSI=1
PLIST_SUB+=	DSSI=""
.else
SCONS_ARGS+=	buildDSSI=0
PLIST_SUB+=	DSSI="@comment "
.endif

.if defined(WITH_FLUIDSYNTH)
LIB_DEPENDS+=	fluidsynth.1:${PORTSDIR}/audio/fluidsynth
PLIST_SUB+=	FLUIDSYNTH=""
FLUIDSYNTH_H=	fluidsynth.h
.else
PLIST_SUB+=	FLUIDSYNTH="@comment "
FLUIDSYNTH_H=	##fluidsynth.h##
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
SCONS_ARGS+=	useJack=1
PLIST_SUB+=	JACK=""
.else
SCONS_ARGS+=	useJack=0
PLIST_SUB+=	JACK="@comment "
.endif

.if defined(WITH_OSC)
LIB_DEPENDS+=	lo.7:${PORTSDIR}/audio/liblo
SCONS_ARGS+=	useOSC=1
PLIST_SUB+=	OSC=""
.else
SCONS_ARGS+=	useOSC=0
PLIST_SUB+=	OSC="@comment "
.endif

.if defined(WITH_PORTAUDIO)
BUILD_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
SCONS_ARGS+=	usePortAudio=1
PLIST_SUB+=	PORTAUDIO=""
PORTAUDIO_L=	"${LOCALBASE}/lib/portaudio2"
PORTAUDIO_R=	"-Wl,-rpath,${LOCALBASE}/lib/portaudio2"
.else
SCONS_ARGS+=	usePortAudio=0
PLIST_SUB+=	PORTAUDIO="@comment "
PORTAUDIO_L=	# empty
PORTAUDIO_R=	# empty
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse-simple.0:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSEAUDIO=""
PULSEAUDIO_H=	pulse/simple.h
.else
PLIST_SUB+=	PULSEAUDIO="@comment "
PULSEAUDIO_H=	##pulse/simple.h##
.endif

.if !defined(WITHOUT_FLTKGUI)
LIB_DEPENDS+=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
PLIST_SUB+=	FLTKGUI=""
SCONS_ARGS+=	buildCsound5GUI=1 buildCSEditor=1 buildWinsound=1 useFLTK=1
.else
PLIST_SUB+=	FLTKGUI="@comment "
SCONS_ARGS+=	buildCsound5GUI=0 buildCSEditor=0 buildWinsound=0 useFLTK=0
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
DISTFILES+=	Csound${PORTVERSION:R}_manual_html.zip:manual
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == sparc64 || ${ARCH} == ia64
CMAKE_ARGS+=	Word64=1
.endif

post-patch:
	@${SED} -e "s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|; \
		s|%%PORTAUDIO_L%%|${PORTAUDIO_L}|; \
		s|%%PORTAUDIO_R%%|${PORTAUDIO_R}|; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|" \
		< ${FILESDIR}/custom.py.in > ${WRKSRC}/custom.py
	@${REINPLACE_CMD} -e "s|'unsupported'|'linux'|; \
		s|Exit(-1)|print \"\"|; \
		/CCFLAGS/s|\['-Wno-format'\]|Split('${CFLAGS}')|; \
		/CXXFLAGS/s|\['-Wno-format'\]|Split('${CXXFLAGS}')|; \
		s|/usr/local|${LOCALBASE}|; \
		s|/usr/X11R6|${LOCALBASE}|; \
		/\"pthread\"/d; \
		s|'pthread'|''|; \
		s|\"portaudio.h\"|\"portaudio2/portaudio.h\"|; \
		s|\"boost/any.hpp\"|\"##boost/any.hpp##\"|; \
		s|\"alsa/asoundlib.h\"|\"${ALSA_H}\"|; \
		s|'xmlfile.h'|'##xmlfile.h##'|; \
		s|\"pulse/simple.h\"|\"${PULSEAUDIO_H}\"|; \
		s|\"m_pd.h\"|\"##m_pd.h##\"|; \
		s|\"tcl.h\"|\"##tcl.h##\"|; \
		s|'5.2'|'5'|; \
		s|'dl'|''|; \
		s|'stdc++'|''|; \
		s|'-DNO_FLTK_THREADS'|''|; \
		s|\"fluidsynth.h\"|\"${FLUIDSYNTH_H}\"|; \
		/mixer_main.c/s|'mixer'|'csmixer'|; \
		/jpluginEnvironment/s|'asound'|''|; \
		/portaudioEnvironment/s|'asound'|''|; \
		/jackEnvironment/s|'asound'|''|; \
		s| stdc++ | |; \
		s| pthread | |" ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e "s|<portaudio.h>|<portaudio2/portaudio.h>|" \
		${WRKSRC}/InOut/rtpa.c
	@${REINPLACE_CMD} -e "s|linux/if.h|sys/socket.h|" \
		${WRKSRC}/OOps/remote.c
	@${REINPLACE_CMD} -e "s|values.h|limits.h|" \
		${WRKSRC}/Opcodes/cpumeter.c
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|" \
		${WRKSRC}/frontends/CsoundAC/Counterpoint.hpp

post-install:
	@${LN} -s libcsound64.so.5 ${PREFIX}/lib/libcsound64.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${ECHO_MSG} " Installing the manual."
	@(cd ${WRKDIR}/Csound${PORTVERSION:R}_manual_html \
		&& ${COPYTREE_SHARE} . ${DOCSDIR})
	@${ECHO_MSG} " Done."
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
