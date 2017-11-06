# Created by: trevor
# $FreeBSD$

PORTNAME=	csound
PORTVERSION=	6.06
PORTREVISION=	11
CATEGORIES=	audio lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}6/${PORTNAME:S/c/C/}${PORTVERSION}
PKGNAMESUFFIX=	6
DISTNAME=	${PORTNAME:S/c/C/}${PORTVERSION}
DIST_SUBDIR=	csound

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sound synthesizer

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		swig>2:devel/swig20 \
		eigen>0:math/eigen3 \
		gmm++>0:math/gmm++
LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile

USES=		alias bison cmake:outsource,noninja localbase python:2
# math/gmm++ requires c++11
USE_CXXSTD=	c++11
CMAKE_ARGS=	-DBUILD_CSOUNDVST:BOOL=OFF \
		-DBUILD_JAVA_INTERFACE:BOOL=OFF \
		-DBUILD_P5GLOVE_OPCODES:BOOL=OFF \
		-DBUILD_PD_CLASS:BOOL=OFF \
		-DBUILD_STK_OPCODES:BOOL=OFF \
		-DBUILD_TESTS:BOOL=OFF \
		-DBUILD_WIIMOTE_OPCODES:BOOL=OFF \
		-DPYTHON_MODULE_INSTALL_DIR:PATH="${PYTHONPREFIX_SITELIBDIR}"
USE_LDCONFIG=	yes
SSP_UNSAFE=	yes

SUB_FILES=	pkg-message

CONFLICTS=		csound-5.*
CONFLICTS_INSTALL=	outguess-*

OPTIONS_DEFINE=		ALSA CURL DSSI FLTK FLUIDSYNTH HDF5 JACK LUA NLS \
			OPENMP OSC PNG PORTAUDIO PULSEAUDIO
OPTIONS_DEFAULT=	FLTK OPENMP
OPTIONS_SUB=		yes

ALSA_DESC=		Build ALSA I/O module
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_OFF=		-DUSE_ALSA:BOOL=OFF
ALSA_PREVENTS=		DSSI
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CMAKE_OFF=		-DUSE_CURL:BOOL=OFF
DSSI_DESC=		Build DSSI/LADSPA host opcodes
DSSI_BUILD_DEPENDS=	dssi>0:audio/dssi
DSSI_LIB_DEPENDS=	libdssialsacompat.so:audio/libdssialsacompat
DSSI_RUN_DEPENDS=	dssi>0:audio/dssi
DSSI_CMAKE_OFF=		-DBUILD_DSSI_OPCODES:BOOL=OFF
DSSI_CFLAGS=		-isystem ${LOCALBASE}/include/dssi
DSSI_PREVENTS=		ALSA
FLTK_DESC=		Build FLTK plugin and GUI
FLTK_LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk
FLTK_CMAKE_ON=		-DBUILD_WINSOUND:BOOL=ON
FLTK_CMAKE_OFF=		-DBUILD_CSOUND_AC:BOOL=OFF \
			-DBUILD_VIRTUAL_KEYBOARD:BOOL=OFF \
			-DUSE_FLTK:BOOL=OFF
FLUIDSYNTH_DESC=	Building FluidSynth opcodes
FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CMAKE_OFF=	-DBUILD_FLUID_OPCODES:BOOL=OFF
HDF5_DESC=		Build HDF5 read/write opcodes
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_CMAKE_OFF=		-DBUILD_HDF5_OPCODES:BOOL=OFF
JACK_DESC=		Build Jack I/O module and opcodes
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_OFF=		-DBUILD_JACK_OPCODES:BOOL=OFF \
			-DUSE_JACK:BOOL=OFF
LUA_DESC=		Build Lua Interface and opcodes
LUA_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUA_CMAKE_OFF=		-DBUILD_CSOUND_AC_LUA_INTERFACE:BOOL=OFF \
			-DBUILD_LUA_INTERFACE:BOOL=OFF \
			-DBUILD_LUA_OPCODES:BOOL=OFF
NLS_USES=		gettext
NLS_CMAKE_OFF=		-DGETTEXT_MSGFMT_EXECUTABLE:FILEPATH="" \
			-DGETTEXT_MSGMERGE_EXECUTABLE:FILEPATH="" \
			-DLIBINTL_LIBRARY:FILEPATH="" \
			-DUSE_GETTEXT:BOOL=OFF
OPENMP_USES=		compiler:gcc-c++11-lib
OPENMP_USES_OFF=	compiler:c++11-lib
OPENMP_CMAKE_OFF=	-DUSE_OPEN_MP:BOOL=OFF
OSC_DESC=		Build OSC opcodes
OSC_LIB_DEPENDS=	liblo.so:audio/liblo
OSC_CMAKE_OFF=		-DBUILD_OSC_OPCODES:BOOL=OFF
PNG_DESC=		Build Image opcodes
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_OFF=		-DBUILD_IMAGE_OPCODES:BOOL=OFF
PORTAUDIO_DESC=		Build PortAudio I/O module
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_OFF=	-DUSE_PORTAUDIO:BOOL=OFF
PULSEAUDIO_DESC=	Build PulseAudio I/O module
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_CMAKE_OFF=	-DUSE_PULSEAUDIO:BOOL=OFF

post-patch:
	@${REINPLACE_CMD} -e \
		'/-O3/s|^|#| ; \
		 /PYTHON_MODULE_INSTALL_DIR/s|^|#| ; \
		 /CMAKE_SYSTEM_NAME/s|"Linux"|"${OPSYS}"| ; \
		 s|(LIBINTL_LIBRARY OR LINUX)|(LIBINTL_LIBRARY)| ; \
		 s|(NOT LINUX)|(LINUX)| ; \
		 s|-D_GNU_SOURCE|| ; \
		 s| dl)|)|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/InOut/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|/usr/include/Python2.7|${PYTHON_INCLUDEDIR}| ; \
		 s|/usr/local|${LOCALBASE}| ; \
		 /linuxjoystick/s|^|#| ; \
		 s| dl)|)|' \
		${WRKSRC}/Opcodes/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		'/CMAKE_SYSTEM_NAME/s|"Linux"|"${OPSYS}"|' \
		${WRKSRC}/frontends/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's| mixer)| csmixer)|' \
		${WRKSRC}/util/CMakeLists.txt
.for i in Engine/auxfd.c H/prototyp.h OOps/diskin2.c OOps/dumpf.c \
	Opcodes/partials.c Top/csound.c
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]fd\)\(close\)|\1__\2|' ${WRKSRC}/${i}
.endfor

post-install:
	@${LN} -sf libcsnd6.so.6.0 ${STAGEDIR}${PREFIX}/lib/libcsnd6.so.6
	@${LN} -sf libcsound64.so.6.0 ${STAGEDIR}${PREFIX}/lib/libcsound64.so.6

post-install-FLTK-on:
	@${LN} -sf libCsoundAC.so.6.0 ${STAGEDIR}${PREFIX}/lib/libCsoundAC.so.6

.include <bsd.port.mk>
