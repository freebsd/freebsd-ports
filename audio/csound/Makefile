# Created by: trevor
# $FreeBSD$

PORTNAME=	csound
PORTVERSION=	5.19.01
PORTREVISION=	5
CATEGORIES=	audio lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}${PORTVERSION:R} \
		SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}${PORTVERSION:R}/manual:manual
DISTFILES=	${PORTNAME:S/c/C/}${PORTVERSION}${EXTRACT_SUFX}
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

OPTIONS_DEFINE=	ALSA PNG DSSI FLTK FLUIDSYNTH JACK OSC PORTAUDIO PULSEAUDIO DOCS
OPTIONS_DEFAULT=FLTK
OPTIONS_SUB=	yes

ALSA_DESC=		ALSA I/O module
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MAKE_ARGS=		useALSA=1
ALSA_MAKE_ARGS_OFF=	useALSA=0
ALSA_VARS=		ALSA_H=alsa/asoundlib.h
ALSA_VARS_OFF=		ALSA_H=##alsa/asoundlib.h##

PNG_DESC=		Image opcodes
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MAKE_ARGS=		buildImageOpcodes=1
PNG_MAKE_ARGS_OFF=	buildImageOpcodes=0

DSSI_DESC=		DSSI/LADSPA host opcodes
DSSI_BUILD_DEPENDS=	dssi>=0:audio/dssi
DSSI_LIB_DEPENDS=	libasound.so:audio/alsa-lib
DSSI_RUN_DEPENDS=	dssi>=0:audio/dssi
DSSI_MAKE_ARGS=		buildDSSI=1
DSSI_MAKE_ARGS_OFF=	buildDSSI=0

FLUIDSYNTH_DESC=	FluidSynth opcodes
FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_VARS=	FLUIDSYNTH_H=fluidsynth.h
FLUIDSYNTH_VARS_OFF=	FLUIDSYNTH_H=##fluidsynth.h##

JACK_DESC=		Jack I/O module and opcodes
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_MAKE_ARGS=		useJack=1
JACK_MAKE_ARGS_OFF=	useJack=0

OSC_DESC=		OSC opcodes
OSC_LIB_DEPENDS=	liblo.so:audio/liblo
OSC_MAKE_ARGS=		useOSC=1
OSC_MAKE_ARGS_OFF=	useOSC=0

PORTAUDIO_DESC=		PortAudio I/O module
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_MAKE_ARGS=	usePortAudio=1
PORTAUDIO_MAKE_ARGS_OFF=usePortAudio=0

PULSEAUDIO_DESC=	PulseAudio I/O module
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_VARS=	PULSEAUDIO_H=pulse/simple.h
PULSEAUDIO_VARS_OFF=	PULSEAUDIO_H=##pulse/simple.h##

FLTK_DESC=		FLTK plugin and GUI
FLTK_LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk
FLTK_MAKE_ARGS=		buildCsound5GUI=1 buildCSEditor=1 buildWinsound=1 useFLTK=1
FLTK_MAKE_ARGS_OFF=	buildCsound5GUI=0 buildCSEditor=0 buildWinsound=0 useFLTK=0

DOCS_DISTFILES=		Csound${PORTVERSION:R}_manual_html.zip:manual

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == sparc64 || ${ARCH} == ia64
MAKE_ARGS+=	Word64=1
.endif

.if ${OPSYS} == FreeBSD
CXXLIB=		c++
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

.include <bsd.port.post.mk>
