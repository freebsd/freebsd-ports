# Created by: trevor
# $FreeBSD$

PORTNAME=	csound
PORTVERSION=	5.18.02
PORTREVISION=	1
CATEGORIES=	audio lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}5.18/ \
		SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}${PORTVERSION:R}/manual:manual
DISTNAME=	${PORTNAME:S/c/C/}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Sound synthesizer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

DIST_SUBDIR=	csound
BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13 \
		${LOCALBASE}/include/gmm/gmm.h:${PORTSDIR}/math/gmm++ \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile

OPTIONS_DEFINE=	ALSA DSSI FLUIDSYNTH JACK OSC PORTAUDIO PULSEAUDIO FLTK
OPTIONS_DEFAULT=FLTK
ALSA_DESC=	Build ALSA I/O module
DSSI_DESC=	Build DSSI/LADSPA host opcodes
FLUIDSYNTH_DESC=Building FluidSynth opcodes
JACK_DESC=	Build Jack I/O module and opcodes
OSC_DESC=	Build OSC opcodes
PORTAUDIO_DESC=	Build the PortAudio I/O module
PULSEAUDIO_DESC=Build the PulseAudio I/O module
FLTK_DESC=	Build FLTK plugin and GUI

CONFLICTS_INSTALL=	outguess-*

SSP_UNSAFE=	yes
USE_PYTHON=	2.6+
USES=		bison gettext
NO_STAGE=	yes
USE_SCONS=	yes
SCONS_BUILDENV=	PATH=${LOCALBASE}/bin:$$PATH
SCONS_ARGS=	prefix="${PREFIX}" CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		buildCsoundAC=0 buildCsoundVST=0 buildInterfaces=1 \
		buildRelease=1 buildVirtual=1 dynamicCsoundLibrary=1 \
		install=1 noDebug=1 useDouble=1 \
		useGettext=1 usePortMIDI=0
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
SCONS_ARGS+=	useALSA=1
PLIST_SUB+=	ALSA=""
ALSA_H=		alsa/asoundlib.h
.else
SCONS_ARGS+=	useALSA=0
PLIST_SUB+=	ALSA="@comment "
ALSA_H=		##alsa/asoundlib.h##
.endif

.if ${PORT_OPTIONS:MDSSI}
BUILD_DEPENDS+=	dssi>=0:${PORTSDIR}/audio/dssi
RUN_DEPENDS+=	dssi>=0:${PORTSDIR}/audio/dssi
SCONS_ARGS+=	buildDSSI=1
PLIST_SUB+=	DSSI=""
.else
SCONS_ARGS+=	buildDSSI=0
PLIST_SUB+=	DSSI="@comment "
.endif

.if ${PORT_OPTIONS:MFLUIDSYNTH}
LIB_DEPENDS+=	fluidsynth:${PORTSDIR}/audio/fluidsynth
PLIST_SUB+=	FLUIDSYNTH=""
FLUIDSYNTH_H=	fluidsynth.h
.else
PLIST_SUB+=	FLUIDSYNTH="@comment "
FLUIDSYNTH_H=	##fluidsynth.h##
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
SCONS_ARGS+=	useJack=1
PLIST_SUB+=	JACK=""
.else
SCONS_ARGS+=	useJack=0
PLIST_SUB+=	JACK="@comment "
.endif

.if ${PORT_OPTIONS:MOSC}
LIB_DEPENDS+=	lo:${PORTSDIR}/audio/liblo
SCONS_ARGS+=	useOSC=1
PLIST_SUB+=	OSC=""
.else
SCONS_ARGS+=	useOSC=0
PLIST_SUB+=	OSC="@comment "
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
BUILD_DEPENDS+=	portaudio2>=0:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	portaudio2>=0:${PORTSDIR}/audio/portaudio2
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

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse-simple:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSEAUDIO=""
PULSEAUDIO_H=	pulse/simple.h
.else
PLIST_SUB+=	PULSEAUDIO="@comment "
PULSEAUDIO_H=	##pulse/simple.h##
.endif

.if ${PORT_OPTIONS:MFLTK}
LIB_DEPENDS+=	fltk:${PORTSDIR}/x11-toolkits/fltk
PLIST_SUB+=	FLTK=""
SCONS_ARGS+=	buildCsound5GUI=1 buildCSEditor=1 buildWinsound=1 useFLTK=1
.else
PLIST_SUB+=	FLTK="@comment "
SCONS_ARGS+=	buildCsound5GUI=0 buildCSEditor=0 buildWinsound=0 useFLTK=0
.endif

.if ${PORT_OPTIONS:MDOCS}
EXTRACT_DEPENDS+=${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
DISTFILES+=	Csound${PORTVERSION:R}_manual_html.zip:manual
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == sparc64 || ${ARCH} == ia64
CMAKE_ARGS+=	Word64=1
.endif

post-extract:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${UNZIP_CMD} -qo \
		Csound${PORTVERSION:R}_manual_html.zip -d ${WRKDIR})
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
	@${REINPLACE_CMD} -e "s|linux/if.h|sys/types.h|" \
		${WRKSRC}/OOps/remote.c
	@${REINPLACE_CMD} '1658,1659d' \
		${WRKSRC}/SConstruct
post-install:
	@${LN} -sf libcsound64.so.5 ${PREFIX}/lib/libcsound64.so
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${ECHO_MSG} " Installing manual ${PORTVERSION}. "
	@(cd ${WRKDIR}/html && ${COPYTREE_SHARE} . ${DOCSDIR})
	@${ECHO_MSG} " Done."
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
