# Created by: trevor
# $FreeBSD$

PORTNAME=	csound
PORTVERSION=	5.19.01
PORTREVISION=	2
CATEGORIES=	audio lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}${PORTVERSION:R} \
		SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}${PORTVERSION:R}/manual:manual
DISTFILES=	${PORTNAME:S/c/C/}${PORTVERSION}${EXTRACT_SUFX} \
		${CSOUND_DOCS:S/$/:manual/}
DIST_SUBDIR=	csound

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sound synthesizer

LICENSE=	LGPL21

BUILD_DEPENDS=	swig13>0:${PORTSDIR}/devel/swig13 \
		eigen>0:${PORTSDIR}/math/eigen3 \
		gmm++>0:${PORTSDIR}/math/gmm++
LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

PORTSCOUT=	limit:^5\.

OPTIONS_DEFINE=	ALSA PNG DSSI FLTK FLUIDSYNTH JACK OSC PORTAUDIO PULSEAUDIO DOCS
OPTIONS_DEFAULT=FLTK
OPTIONS_SUB=	yes
ALSA_DESC=	Build ALSA I/O module
PNG_DESC=	Build image opcodes
DSSI_DESC=	Build DSSI/LADSPA host opcodes
FLUIDSYNTH_DESC=Building FluidSynth opcodes
JACK_DESC=	Build Jack I/O module and opcodes
OSC_DESC=	Build OSC opcodes
PORTAUDIO_DESC=	Build the PortAudio I/O module
PULSEAUDIO_DESC=Build the PulseAudio I/O module
FLTK_DESC=	Build FLTK plugin and GUI

CONFLICTS_INSTALL=	outguess-* csound6

WRKSRC=		${WRKDIR}/${PORTNAME:S/c/C/}${PORTVERSION}

USES=		bison gettext scons compiler:openmp python
MAKE_ARGS=	instdir="${STAGEDIR}" prefix="${PREFIX}" \
		CC="${CC}" CXX="${CXX}" \
		buildCsoundAC=0 buildCsoundVST=0 buildInterfaces=1 \
		buildRelease=1 buildVirtual=1 dynamicCsoundLibrary=1 \
		install=1 noDebug=1 useDouble=1 \
		useGettext=1 usePortMIDI=0
USE_LDCONFIG=	yes
SSP_UNSAFE=	yes

CFLAGS+=	-fPIC -fopenmp -DUSE_OPENMP
LDFLAGS+=	-pthread -Wl,-export-dynamic

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
MAKE_ARGS+=	useALSA=1
ALSA_H=		alsa/asoundlib.h
.else
MAKE_ARGS+=	useALSA=0
ALSA_H=		##alsa/asoundlib.h##
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng.so:${PORTSDIR}/graphics/png
MAKE_ARGS+=	buildImageOpcodes=1
.else
MAKE_ARGS+=	buildImageOpcodes=0
.endif

.if ${PORT_OPTIONS:MDSSI}
BUILD_DEPENDS+=	dssi>=0:${PORTSDIR}/audio/dssi
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	dssi>=0:${PORTSDIR}/audio/dssi
MAKE_ARGS+=	buildDSSI=1
.else
MAKE_ARGS+=	buildDSSI=0
.endif

.if ${PORT_OPTIONS:MFLUIDSYNTH}
LIB_DEPENDS+=	libfluidsynth.so:${PORTSDIR}/audio/fluidsynth
FLUIDSYNTH_H=	fluidsynth.h
.else
FLUIDSYNTH_H=	##fluidsynth.h##
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack
MAKE_ARGS+=	useJack=1
.else
MAKE_ARGS+=	useJack=0
.endif

.if ${PORT_OPTIONS:MOSC}
LIB_DEPENDS+=	liblo.so:${PORTSDIR}/audio/liblo
MAKE_ARGS+=	useOSC=1
.else
MAKE_ARGS+=	useOSC=0
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
BUILD_DEPENDS+=	portaudio2>=0:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	portaudio2>=0:${PORTSDIR}/audio/portaudio2
MAKE_ARGS+=	usePortAudio=1
PORTAUDIO_L=	"${LOCALBASE}/lib/portaudio2"
PORTAUDIO_R=	"-Wl,-rpath,${LOCALBASE}/lib/portaudio2"
.else
MAKE_ARGS+=	usePortAudio=0
PORTAUDIO_L=	# empty
PORTAUDIO_R=	# empty
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse-simple.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_H=	pulse/simple.h
.else
PULSEAUDIO_H=	##pulse/simple.h##
.endif

.if ${PORT_OPTIONS:MFLTK}
LIB_DEPENDS+=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk
MAKE_ARGS+=	buildCsound5GUI=1 buildCSEditor=1 buildWinsound=1 useFLTK=1
.else
MAKE_ARGS+=	buildCsound5GUI=0 buildCSEditor=0 buildWinsound=0 useFLTK=0
.endif

.if ${PORT_OPTIONS:MDOCS}
CSOUND_DOCS=	Csound${PORTVERSION:R}_manual_html.zip
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == sparc64 || ${ARCH} == ia64
MAKE_ARGS+=	Word64=1
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>0:${PORTSDIR}/textproc/flex
MAKE_ENV+=	PATH=${LOCALBASE}/bin:$$PATH
.endif

.if ${OSVERSION} >= 1000054
CXXLIB=		c++
.else
CXXLIB=		# empty
.endif

.include <bsd.port.options.mk>

post-patch:
	@${SED} -e "s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|; \
		s|%%PORTAUDIO_L%%|${PORTAUDIO_L}|; \
		s|%%PORTAUDIO_R%%|${PORTAUDIO_R}|" \
		< ${FILESDIR}/custom.py.in > ${WRKSRC}/custom.py
	@${REINPLACE_CMD} -e "s|'unsupported'|'linux'|; \
		s|Exit(-1)|print \"\"|; \
		/CCFLAGS/s|\['-Wno-format'\]|Split('${CFLAGS}')|; \
		/CXXFLAGS/s|\['-Wno-format'\]|Split('${CXXFLAGS}')|; \
		s|/usr/local|${LOCALBASE}|; \
		s|/usr/X11R6|${LOCALBASE}|; \
		/LINKFLAGS/s|\['-Wl,-Bdynamic'\]|Split('${LDFLAGS}')|; \
		s|\"pthread\"|\"\"|; \
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
		s|'stdc++'|'${CXXLIB}'|; \
		/linuxjoystick/s|^.*|    print \"\"|; \
		s|\"fluidsynth.h\"|\"${FLUIDSYNTH_H}\"|; \
		/mixer_main.c/s|'mixer'|'csmixer'|; \
		/jpluginEnvironment/s|'asound'|''|; \
		/portaudioEnvironment/s|'asound'|''|; \
		/jackEnvironment/s|'asound'|''|" ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e "s|<portaudio.h>|<portaudio2/portaudio.h>|" \
		${WRKSRC}/InOut/rtpa.c
	@${REINPLACE_CMD} -e "s|linux/if.h|sys/types.h|" \
		${WRKSRC}/OOps/remote.c

post-install:
	${LN} -sf libcsound64.so.5 ${STAGEDIR}${PREFIX}/lib/libcsound64.so
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/*.so* \
		${STAGEDIR}${PREFIX}/lib/csound/plugins64/*.so

.include <bsd.port.post.mk>
