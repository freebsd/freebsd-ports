# Created by: Jimmy Olgeni <olgeni@uli.it>
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.65a
PORTREVISION=	4
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	3D modeling/rendering/animation/gaming package

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

USE_XORG=	x11 xext xmu
USE_GL=		glew
USE_CMAKE=	yes
USE_PYTHON=	3.3
WANT_GNOME=	yes

MAKE_JOBS_SAFE=	yes

CMAKE_OUTSOURCE=	yes
CMAKE_ARGS+=	-DWITH_PYTHON_INSTALL:BOOL=OFF \
		-DWITH_PYTHON_INSTALL_NUMPY:BOOL=OFF

SUB_FILES=	blender blenderplayer
MAN1=		blender.1

OUTDIR=		${INSTALL_WRKSRC}/bin/2.65

LANG=	ar cs de eo es es_ES fa fr he hr hu id it ja ky nl pt pt_BR ru \
	sr sr@latin sv tr uk zh_CN zh_TW

OPTIONS_DEFINE=	BOOLEAN BULLET CINEON CAMERATRACK CYCLES CYCLESOSL DDS FFMPEG \
		FFTW3 GAMEENGINE HDR HEADLESS JACK NLS MENU OCEANSIM OPENAL \
		OPENCOLORIO OPENEXR OPENJPEG OPENMP PLAYER RAYOPTIMIZATION \
		REDCODE SAMPLERATE SDL SNDFILE TIFF XINPUT XF86VMODE
OPTIONS_DEFAULT=	BOOLEAN BULLET CINEON CYCLES CYCLESOSL DDS GAMEENGINE \
			HDR JACK OPENAL OPENCOLORIO OPENEXR OPENJPEG OPENMP \
			PLAYER SAMPLERATE SDL TIFF XINPUT XF86VMODE

BOOLEAN_DESC=		Boolean library support
BULLET_DESC=		Bullet physics engine
CINEON_DESC=		CINEON and DPX graphics format support
CAMERATRACK_DESC=	Camera tracking support
CYCLES_DESC=		Cycles render engine support
CYCLESOSL_DESC=		Shading support for the cycles render engine
DDS_DESC=		DDS graphics format support
FFTW3_DESC=		Use fftw for smoke and audio effects
GAMEENGINE_DESC=	Enable the game engine
HDR_DESC=		Generic high dynamic-range (HDR) support
HEADLESS_DESC=		Disable user interface (for render-farms)
MENU_DESC=		Install desktop menu
OCEANSIM_DESC=		Ocean simulation support
OPENCOLORIO_DESC=	OpenColorIO-based color management support
PLAYER_DESC=		Enable blender player
RAYOPTIMIZATION_DESC=	Enable SSE optimizatons for raytracing
REDCODE_DESC=		RedCode graphics format support
SDL_DESC=		Audio and Joystick support using SDL
XINPUT_DESC=		X11 Xinput (tablet) support
XF86VMODE_DESC=		X11 video mode switching support

# TODO: provide switches for the following options
#
# WITH_IMAGE_FRAMESERVER WITH_LZO WITH_LZMA WITH_LIBMV WITH_INPUT_NDOF

.include <bsd.port.options.mk>

. if ${PORT_OPTIONS:MBOOLEAN}
CMAKE_ARGS+=	-DWITH_MOD_BOOLEAN:BOOL=ON
LIB_DEPENDS+=	boost_thread:${PORTSDIR}/devel/boost-libs
.else
CMAKE_ARGS+=	-DWITH_MOD_BOOLEAN:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MBULLET}
CMAKE_ARGS+=	-DWITH_BULLET:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_BULLET:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MCINEON}
CMAKE_ARGS+=	-DWITH_IMAGE_CINEON:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_IMAGE_CINEON:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MCAMERATRACK}
CMAKE_ARGS+=	-DWITH_LIBMV:BOOL=ON
LIB_DEPENDS+=	unwind:${PORTSDIR}/devel/libunwind
.else
CMAKE_ARGS+=	-DWITH_LIBMV:BOOL=OFF
.endif

# openimageio to enable cycles requires 8.0 or higher
.if ${PORT_OPTIONS:MCYCLES}
.if ${OSVERSION} < 800000
IGNORE=	cycles render engine only works in FreeBSD 8 or later
.endif
CMAKE_ARGS+=	-DWITH_CYCLES:BOOL=ON
LIB_DEPENDS+=	OpenImageIO:${PORTSDIR}/graphics/openimageio
.else
CMAKE_ARGS+=	-DWITH_CYCLES:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MCYCLESOSL}
.if !${PORT_OPTIONS:MCYCLES}
IGNORE=	support for the OpenShadingLanguage in cycles obviously requires CYCLES
.endif
CMAKE_ARGS+=	-DWITH_CYCLES_OSL:BOOL=ON
LIB_DEPENDS+=	oslexec:${PORTSDIR}/graphics/openshadinglanguage
.else
CMAKE_ARGS+=	-DWITH_CYCLES_OSL:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MDDS}
CMAKE_ARGS+=	-DWITH_IMAGE_DDS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_IMAGE_DDS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MFFMPEG}
CMAKE_ARGS+=	-DWITH_CODEC_FFMPEG:BOOL=ON
LIB_DEPENDS+=	avutil:${PORTSDIR}/multimedia/ffmpeg
.else
CMAKE_ARGS+=	-DWITH_CODEC_FFMPEG:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MFFTW3}
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
CMAKE_ARGS+=	-DWITH_FFTW3:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_FFTW3:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGAMEENGINE}
CMAKE_ARGS+=	-DWITH_GAMEENGINE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_GAMEENGINE:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MHDR}
CMAKE_ARGS+=	-DWITH_IMAGE_HDR:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_IMAGE_HDR:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MHEADLESS}
CMAKE_ARGS+=	-DWITH_HEADLESS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_HEADLESS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
CMAKE_ARGS+=	-DWITH_JACK:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_JACK:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MMENU}
USE_GNOME=	desktopfileutils
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
USE_ICONV=	yes
CMAKE_ARGS+=	-DWITH_INTERNATIONAL:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_INTERNATIONAL:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MOCEANSIM}
.if ${PORT_OPTIONS:MFFTW3}
CMAKE_ARGS+=	-DWITH_MOD_OCEANSIM:BOOL=ON
.else
BROKEN=		OCEANSIM requires FFTW3
.endif
.else
CMAKE_ARGS+=	-DWITH_MOD_OCEANSIM:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MOPENAL}
.if ${PORT_OPTIONS:MSAMPLERATE}
USE_OPENAL=	al alut
CMAKE_ARGS+=	-DWITH_OPENAL:BOOL=ON
.else
BROKEN=		OPENAL requires SAMPLERATE
.endif
.else
CMAKE_ARGS+=	-DWITH_OPENAL:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MOPENCOLORIO}
LIB_DEPENDS+=	OpenColorIO:${PORTSDIR}/graphics/opencolorio
CMAKGE_ARGS+=	-DWITH_OPENCOLORIO:BOOL=ON
.else
CMAKGE_ARGS+=	-DWITH_OPENCOLORIO:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MOPENEXR}
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
CMAKGE_ARGS+=	-DWITH_IMAGE_OPENEXR:BOOL=ON
.else
CMAKGE_ARGS+=	-DWITH_IMAGE_OPENEXR:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
LIB_DEPENDS+=	openjpeg:${PORTSDIR}/graphics/openjpeg
CMAKE_ARGS+=	-DWITH_SYSTEM_OPENJPEG:BOOL=ON -DWITH_IMAGE_OPENJPEG:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_IMAGE_OPENJPEG:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MOPENMP}
CMAKE_ARGS+=	-DWITH_OPENMP:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_OPENMP:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MPLAYER}
.if ${PORT_OPTIONS:MGAMEENGINE}
CMAKE_ARGS+=	-DWITH_PLAYER:BOOL=ON
.else
BROKEN=		PLAYER requires GAMEENGINE
.endif
.else
CMAKE_ARGS+=	-DWITH_PLAYER:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MRAYOPTIMIZATION}
CMAKE_ARGS+=	-DWITH_RAYOPTIMIZATION:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_RAYOPTIMIZATION:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MREDCODE}
.if ${PORT_OPTIONS:MOPENJPEG} && ${PORT_OPTIONS:MFFMPEG}
CMAKE_ARGS+=	-DWITH_IMAGE_REDCODE:BOOL=ON
.else
BROKEN=		REDCODE requires OPENJPEG and FFMPEG
.endif
.else
CMAKE_ARGS+=	-DWITH_IMAGE_REDCODE:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=	samplerate:${PORTSDIR}/audio/libsamplerate
CMAKE_ARGS+=	-DWITH_SAMPLERATE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_SAMPLERATE:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MSDL}
.if ${PORT_OPTIONS:MSAMPLERATE}
USE_SDL=	sdl
CMAKE_ARGS+=	-DWITH_SDL:BOOL=ON
.else
BROKEN=		SDL requires SAMPLERATE
.endif
.else
CMAKE_ARGS+=	-DWITH_SDL:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
CMAKE_ARGS+=	-DWITH_CODEC_SNDFILE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_CODEC_SNDFILE:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
CMAKE_ARGS+=	-DWITH_IMAGE_TIFF:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_IMAGE_TIFF:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MXINPUT}
USE_XORG+=	xi
CMAKE_ARGS+=	-DWITH_X11_XINPUT:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_X11_XINPUT:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MXF86VMODE}
USE_XORG+=	xi xxf86vm
CMAKE_ARGS+=	-DWITH_X11_XF86VMODE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_X11_XF86VMODE:BOOL=OFF
.endif

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/blender ${PREFIX}/bin/blender
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/blender \
		${PREFIX}/bin/blender-bin
	@${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/bin/blender-thumbnailer.py \
		${PREFIX}/bin/blender-thumbnailer.py
	@${ECHO} bin/blender >> ${TMPPLIST}
	@${ECHO} bin/blender-bin >> ${TMPPLIST}
	@${ECHO} bin/blender-thumbnailer.py >> ${TMPPLIST}

.if ${PORT_OPTIONS:MPLAYER}
	@${INSTALL_SCRIPT} ${WRKDIR}/blenderplayer ${PREFIX}/bin/blenderplayer
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/blenderplayer \
		${PREFIX}/bin/blenderplayer-bin
	@${ECHO} bin/blenderplayer >> ${TMPPLIST}
	@${ECHO} bin/blenderplayer-bin >> ${TMPPLIST}
.endif

.if ${PORT_OPTIONS:MMENU}
	@${MKDIR} ${DESKTOPDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/bin/${PORTNAME}.desktop \
		${DESKTOPDIR}
	@-update-desktop-database -q
	@${ECHO} share/applications/${PORTNAME}.desktop >> ${TMPPLIST}
.endif

	@${MKDIR} ${DATADIR}
	@(cd ${OUTDIR} && ${COPYTREE_SHARE} scripts ${DATADIR})
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/bin/${PORTNAME}.svg \
		${PREFIX}/share/pixmaps/${PORTNAME}.svg
	@(cd ${OUTDIR}; ${FIND} scripts -type f) | ${SORT} | ${SED} "s|^|${DATADIR_REL}/|" >> ${TMPPLIST}
	@(cd ${OUTDIR}; ${FIND} scripts -type d) | ${SORT} -r | ${SED} "s|^|@dirrm ${DATADIR_REL}/|" >> ${TMPPLIST}
	@${ECHO} share/pixmaps/${PORTNAME}.svg >> ${TMPPLIST}

.if ${PORT_OPTIONS:MOPENCOLORIO}
	@cd ${OUTDIR} && ${COPYTREE_SHARE} datafiles/colormanagement ${DATADIR}
	@(cd ${OUTDIR}; ${FIND} datafiles/colormanagement -type f) | ${SORT} | ${SED} "s|^|${DATADIR_REL}/|" >> ${TMPPLIST}
	@(cd ${OUTDIR}; ${FIND} datafiles/colormanagement -type d) | ${SORT} -r | ${SED} "s|^|@dirrm ${DATADIR_REL}/|" >> ${TMPPLIST}
.endif

.if ${PORT_OPTIONS:MNLS}
.for ii in ${LANG}
	@${MKDIR} ${DATADIR}/datafiles/locale/${ii}/LC_MESSAGES
	@${INSTALL_DATA} \
		${OUTDIR}/datafiles/locale/${ii}/LC_MESSAGES/${PORTNAME}.mo \
		${DATADIR}/datafiles/locale/${ii}/LC_MESSAGES/${PORTNAME}.mo
.endfor
	@(cd ${OUTDIR}; ${FIND} datafiles/locale -type f -name ${PORTNAME}.mo) | ${SORT} | ${SED} "s|^|${DATADIR_REL}/|" >> ${TMPPLIST}
	@(cd ${OUTDIR}; ${FIND} datafiles/locale -type d) | ${SORT} -r | ${SED} "s|^|@dirrm ${DATADIR_REL}/|" >> ${TMPPLIST}

.endif
	@${ECHO} @dirrm ${DATADIR_REL}/datafiles >> ${TMPPLIST}
	@${ECHO} @dirrm ${DATADIR_REL} >> ${TMPPLIST}

.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${INSTALL_WRKSRC}/bin/${PORTNAME}.1 \
		${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.mk>
