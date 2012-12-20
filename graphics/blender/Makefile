# New ports collection makefile for:    blender
# Date created:         14 November 2000
# Whom:                 Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.63a
PORTREVISION=	2
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	3D modeling/rendering/animation/gaming package

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

USE_XORG=	x11 xext xmu
USE_GL=		glew
USE_CMAKE=	yes
USE_PYTHON=	3.2
WANT_GNOME=	yes

MAKE_JOBS_SAFE=	yes

CMAKE_OUTSOURCE=	yes
CMAKE_ARGS+=	-DWITH_BUILTIN_GLEW:BOOL=OFF -DWITH_PYTHON_INSTALL:BOOL=OFF

SUB_FILES=	blender blenderplayer
MAN1=		blender.1

OUTDIR=		${INSTALL_WRKSRC}/bin/2.63

LANG=	ar bg ca cs de el es es_ES fa fi fr hr id it ja ky ne pl pt \
	ru sr sr@latin sv tr uk zh_CN zh_TW

OPTIONS_DEFINE=	BULLET CARVE CINEON CAMERATRACK CYCLES DDS FFMPEG FFTW3 \
		GAMEENGINE HDR HEADLESS JACK NLS MENU OCEANSIM OPENAL OPENEXR \
		OPENJPEG OPENMP PLAYER REDCODE SAMPLERATE SDL SNDFILE TIFF \
		XINPUT
OPTIONS_DEFAULT=	BULLET CARVE CINEON CAMERATRACK CYCLES DDS FFMPEG \
			FFTW3 GAMEENGINE HDR MENU OCEANSIM OPENAL OPENEXR \
			OPENJPEG OPENMP SAMPLERATE SDL TIFF XINPUT
BULLET_DESC=		Enable bullet physics engine
CARVE_DESC=		Carve boolean library support
CINEON_DESC=		CINEON and DPX graphics format support
CAMERATRACK_DESC=	Camera tracking support
CYCLES_DESC=		Cycles render engine support
DDS_DESC=		DDS graphics format support
FFTW3_DESC=		Floating point support using fftw
GAMEENGINE_DESC=	Enable the game engine
HDR_DESC=		Generic high dynamic-range (HDR) support
HEADLESS_DESC=		Disable user interface
MENU_DESC=		Install desktop menu
OCEANSIM_DESC=		Ocean simulation support
PLAYER_DESC=		Enable blender player
REDCODE_DESC=		RedCode graphics format support
SDL_DESC=		Audio and Joystick support using SDL
XINPUT_DESC=		Enable X11 Xinput (tablet) support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBULLET}
CMAKE_ARGS+=	-DWITH_BULLET:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_BULLET:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MCARVE}
CMAKE_ARGS+=	-DWITH_CARVE:BOOL=ON
LIB_DEPENDS+=	boost_thread.4:${PORTSDIR}/devel/boost-libs
.else
CMAKE_ARGS+=	-DWITH_CARVE:BOOL=OFF
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
.else
CMAKE_ARGS+=	-DWITH_CYCLES:BOOL=ON
.if ${ARCH} == "i386" || ${OSVERSION} < 803000
# this is needed for linking with openimageio
USE_GCC=	4.6+
LDFLAGS+=	-L${LOCALBASE}/lib/gcc46 -rpath ${LOCALBASE}/lib/gcc46
.endif
.endif
LIB_DEPENDS+=	OpenImageIO:${PORTSDIR}/graphics/openimageio
PLIST_SUB+=	CYCLES=""
.else
CMAKE_ARGS+=	-DWITH_CYCLES:BOOL=OFF
PLIST_SUB+=	CYCLES="@comment "
.endif

.if ${PORT_OPTIONS:MDDS}
CMAKE_ARGS+=	-DWITH_IMAGE_DDS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_IMAGE_DDS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MFFMPEG}
CMAKE_ARGS+=	-DWITH_CODEC_FFMPEG:BOOL=ON
LIB_DEPENDS+=	avutil.1:${PORTSDIR}/multimedia/ffmpeg
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
.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CMAKE_ARGS+=	-DWITH_JACK:BOOL=ON
.else
BROKEN=		JACK requires SAMPLERATE
.endif
.else
CMAKE_ARGS+=	-DWITH_JACK:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MMENU}
USE_GNOME=	desktopfileutils
PLIST_SUB+=	MENU=""
.else
PLIST_SUB+=	MENU="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
USE_ICONV=	yes
PLIST_SUB+=	NLS=""
CMAKE_ARGS+=	-DWITH_INTERNATIONAL:BOOL=ON
.else
PLIST_SUB+=	NLS="@comment "
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

.if ${PORT_OPTIONS:MOPENEXR}
LIB_DEPENDS+=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR
CMAKGE_ARGS+=	-DWITH_IMAGE_OPENEXR:BOOL=ON
.else
CMAKGE_ARGS+=	-DWITH_IMAGE_OPENEXR:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
LIB_DEPENDS+=	openjpeg.2:${PORTSDIR}/graphics/openjpeg
CMAKE_ARGS+=	-DWITH_IMAGE_OPENJPEG:BOOL=ON
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
PLIST_SUB+=	PLAYER=""
CMAKE_ARGS+=	-DWITH_PLAYER:BOOL=ON
.else
BROKEN=		PLAYER requires GAMEENGINE
.endif
.else
PLIST_SUB+=	PLAYER="@comment "
CMAKE_ARGS+=	-DWITH_PLAYER:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MREDCODE}
.if ${PORT_OPTIONS:MOPENJPEG}
CMAKE_ARGS+=	-DWITH_IMAGE_REDCODE:BOOL=ON
.else
BROKEN=		REDCODE requires OPENJPEG
.endif
.else
CMAKE_ARGS+=	-DWITH_IMAGE_REDCODE:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
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
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
CMAKE_ARGS+=	-DWITH_CODEC_SNDFILE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_CODEC_SNDFILE:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
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

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/blender ${PREFIX}/bin/blender
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/blender \
		${PREFIX}/bin/blender-bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/bin/blender-thumbnailer.py \
		${PREFIX}/bin/blender-thumbnailer.py

.if ${PORT_OPTIONS:MPLAYER}
	@${INSTALL_SCRIPT} ${WRKDIR}/blenderplayer ${PREFIX}/bin/blenderplayer
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/blenderplayer \
		${PREFIX}/bin/blenderplayer-bin
.endif

	@${CP} -R ${OUTDIR}/scripts ${DATADIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/bin/${PORTNAME}.svg \
		${PREFIX}/share/pixmaps/${PORTNAME}.svg

.if ${PORT_OPTIONS:NLS}
.for ii in ${LANG}
	@${MKDIR} ${DATADIR}/datafiles/locale/${ii}/LC_MESSAGES
	@${INSTALL_DATA} \
		${OUTDIR}/datafiles/locale/${ii}/LC_MESSAGES/${PORTNAME}.mo \
		${DATADIR}/datafiles/locale/${ii}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.endif

.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${INSTALL_WRKSRC}/bin/${PORTNAME}.1 \
		${MAN1PREFIX}/man/man1
.endif

.if ${PORT_OPTIONS:MMENU}
	@${MKDIR} ${DESKTOPDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/bin/${PORTNAME}.desktop \
		${DESKTOPDIR}
	@-update-desktop-database -q
.endif

.include <bsd.port.mk>
