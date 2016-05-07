# Created by: trevor
# $FreeBSD$

PORTNAME=	csound
PORTVERSION=	5.19.01
PORTREVISION=	4
CATEGORIES=	audio lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}${PORTVERSION:R} \
		SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}${PORTVERSION:R}/manual:manual
DISTFILES=	${PORTNAME:S/c/C/}${PORTVERSION}${EXTRACT_SUFX} \
		${CSOUND_DOCS:S/$/:manual/}
DIST_SUBDIR=	csound

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sound synthesizer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig13>0:devel/swig13 \
		eigen>0:math/eigen3 \
		gmm++>0:math/gmm++
LIB_DEPENDS=	libsndfile.so:audio/libsndfile

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

USES=		bison cpe gettext scons compiler:openmp python
CPE_VENDOR=	csounds
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
LINKFLAGS=	# empty

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:audio/alsa-lib
MAKE_ARGS+=	useALSA=1
ALSA_H=		alsa/asoundlib.h
.else
MAKE_ARGS+=	useALSA=0
ALSA_H=		##alsa/asoundlib.h##
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng.so:graphics/png
MAKE_ARGS+=	buildImageOpcodes=1
.else
MAKE_ARGS+=	buildImageOpcodes=0
.endif

.if ${PORT_OPTIONS:MDSSI}
BUILD_DEPENDS+=	dssi>=0:audio/dssi
LIB_DEPENDS+=	libasound.so:audio/alsa-lib
RUN_DEPENDS+=	dssi>=0:audio/dssi
MAKE_ARGS+=	buildDSSI=1
.else
MAKE_ARGS+=	buildDSSI=0
.endif

.if ${PORT_OPTIONS:MFLUIDSYNTH}
LIB_DEPENDS+=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_H=	fluidsynth.h
.else
FLUIDSYNTH_H=	##fluidsynth.h##
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:audio/jack
MAKE_ARGS+=	useJack=1
.else
MAKE_ARGS+=	useJack=0
.endif

.if ${PORT_OPTIONS:MOSC}
LIB_DEPENDS+=	liblo.so:audio/liblo
MAKE_ARGS+=	useOSC=1
.else
MAKE_ARGS+=	useOSC=0
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	libportaudio.so:audio/portaudio
MAKE_ARGS+=	usePortAudio=1
.else
MAKE_ARGS+=	usePortAudio=0
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_H=	pulse/simple.h
.else
PULSEAUDIO_H=	##pulse/simple.h##
.endif

.if ${PORT_OPTIONS:MFLTK}
LIB_DEPENDS+=	libfltk.so:x11-toolkits/fltk
MAKE_ARGS+=	buildCsound5GUI=1 buildCSEditor=1 buildWinsound=1 useFLTK=1
.else
MAKE_ARGS+=	buildCsound5GUI=0 buildCSEditor=0 buildWinsound=0 useFLTK=0
.endif

.if ${PORT_OPTIONS:MDOCS}
CSOUND_DOCS=	Csound${PORTVERSION:R}_manual_html.zip
.endif

.if ${ARCH} == amd64 || ${ARCH} == sparc64 || ${ARCH} == ia64
MAKE_ARGS+=	Word64=1
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>0:textproc/flex
MAKE_ENV+=	PATH=${LOCALBASE}/bin:$$PATH
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000054
CXXLIB=		c++
.else
CXXLIB=		# empty
.endif

BROKEN_powerpc64=	Does not build

post-patch:
	@${SED} -e "s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|" \
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
	@${REINPLACE_CMD} -e "s|linux/if.h|sys/types.h|" \
		${WRKSRC}/OOps/remote.c
	@${REINPLACE_CMD} -e "/Str/!s|fdclose|my_fdclose|" \
		${WRKSRC}/OOps/*.c \
		${WRKSRC}/Top/csound.c \
		${WRKSRC}/Engine/auxfd.c \
		${WRKSRC}/H/prototyp.h

post-install:
	${LN} -sf libcsound64.so.5 ${STAGEDIR}${PREFIX}/lib/libcsound64.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/*.so* \
		${STAGEDIR}${PREFIX}/lib/csound/plugins64/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
