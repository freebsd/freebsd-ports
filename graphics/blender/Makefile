# New ports collection makefile for:    blender
# Date created:         14 November 2000
# Whom:                 Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.59
PORTREVISION=	1
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	3D modeling/rendering/animation/gaming package

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
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

OUTDIR=		${INSTALL_WRKSRC}/bin/2.59

LANG=		ar bg ca cs de el es fi fr hr hr_HR it ja ko nl pl pt_BR ro \
		ru sr sr@Latn sv uk zh_CN

OPTIONS=	BULLET		"Enable bullet physics engine" on \
		CINEON		"CINEON and DPX graphics format support" on \
		DDS		"DDS graphics format support" on \
		FFMPEG		"Audio and video support using ffmpeg" on \
		FFTW3		"Floating point support using fftw" off \
		GAMEENGINE	"Enable game engine" on \
		HDR		"Generic high dynamic-range (HDR) support" on \
		HEADLESS	"Disable user interface" off \
		JACK		"Audio support using JackAudio" off \
		NLS		"Native language support" on \
		MENU		"Install desktop menu" on \
		OPENAL		"3D sound support using OpenAL" on \
		OPENEXR		"High dynamic-range (HDR) support using OpenEXR" on \
		OPENJPEG	"Enhanced JPEG graphics support using OpenJPEG" on \
		OPENMP		"Parallel processing support" on \
		PLAYER		"Enable blender player" off \
		REDCODE		"RedCode graphics format support" off \
		SAMPLERATE	"Enable samplerate conversion" on \
		SDL		"Audio and Joystick support using SDL" on \
		SNDFILE		"Audio support using libsndfile" off \
		TIFF		"Tiff graphics format support using LibTiff" on \
		XINPUT		"Enable X11 Xinput (tablet) support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_BULLET)
CMAKE_ARGS+=	-DWITH_BULLET:BOOL=OFF
.else
CMAKE_ARGS+=	-DWITH_BULLET:BOOL=ON
.endif

.if defined(WITHOUT_CINEON)
CMAKE_ARGS+=	-DWITH_IMAGE_CINEON:BOOL=OFF
.else
CMAKE_ARGS+=	-DWITH_IMAGE_CINEON:BOOL=ON
.endif

.if defined(WITHOUT_DDS)
CMAKE_ARGS+=	-DWITH_IMAGE_DDS:BOOL=OFF
.else
CMAKE_ARGS+=	-DWITH_IMAGE_DDS:BOOL=ON
.endif

.if defined(WITHOUT_FFMPEG)
CMAKE_ARGS+=	-DWITH_CODEC_FFMPEG:BOOL=OFF
.else
LIB_DEPENDS+=	avutil.1:${PORTSDIR}/multimedia/ffmpeg
CMAKE_ARGS+=	-DWITH_CODEC_FFMPEG:BOOL=ON
.endif

.if defined(WITH_FFTW3)
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
CMAKE_ARGS+=	-DWITH_FFTW3:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_FFTW3:BOOL=OFF
.endif

.if defined(WITHOUT_GAMEENGINE)
CMAKE_ARGS+=	-DWITH_GAMEENGINE:BOOL=OFF
.else
CMAKE_ARGS+=	-DWITH_GAMEENGINE:BOOL=ON
.endif

.if defined(WITHOUT_HDR)
CMAKE_ARGS+=	-DWITH_IMAGE_HDR:BOOL=OFF
.else
CMAKE_ARGS+=	-DWITH_IMAGE_HDR:BOOL=ON
.endif

.if defined(WITH_HEADLESS)
CMAKE_ARGS+=	-DWITH_HEADLESS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_HEADLESS:BOOL=OFF
.endif

.if defined(WITH_JACK)
.if defined(WITHOUT_SAMPLERATE)
BROKEN=		WITH_JACK requires WITH_SAMPLERATE
.endif
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CMAKE_ARGS+=	-DWITH_JACK:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_JACK:BOOL=OFF
.endif

.if defined(WITHOUT_MENU)
PLIST_SUB+=	MENU="@comment "
.else
USE_GNOME=	desktopfileutils
PLIST_SUB+=	MENU=""
.endif

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
CMAKE_ARGS+=	-DWITH_INTERNATIONAL:BOOL=OFF
.else
USE_GETTEXT=	yes
USE_ICONV=	yes
PLIST_SUB+=	NLS=""
CMAKE_ARGS+=	-DWITH_INTERNATIONAL:BOOL=ON
.endif

.if defined(WITHOUT_OPENAL)
CMAKE_ARGS+=	-DWITH_OPENAL:BOOL=OFF
.else
.if defined(WITHOUT_SAMPLERATE)
BROKEN=		WITH_OPENAL requires WITH_SAMPLERATE
.endif
USE_OPENAL=	al alut
CMAKE_ARGS+=	-DWITH_OPENAL:BOOL=ON
.endif

.if defined(WITHOUT_OPENEXR)
CMAKGE_ARGS+=	-DWITH_IMAGE_OPENEXR:BOOL=OFF
.else
LIB_DEPENDS+=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR
CMAKGE_ARGS+=	-DWITH_IMAGE_OPENEXR:BOOL=ON
.endif

.if defined(WITHOUT_OPENJPEG)
CMAKE_ARGS+=	-DWITH_IMAGE_OPENJPEG:BOOL=OFF
.else
LIB_DEPENDS+=	openjpeg.2:${PORTSDIR}/graphics/openjpeg
CMAKE_ARGS+=	-DWITH_IMAGE_OPENJPEG:BOOL=ON
.endif

.if defined(WITHOUT_OPENMP)
CMAKE_ARGS+=	-DWITH_OPENMP:BOOL=OFF
.else
CMAKE_ARGS+=	-DWITH_OPENMP:BOOL=ON
.endif

.if defined(WITH_PLAYER)
.if defined(WITHOUT_GAMEENGINE)
BROKEN=		WITH_PLAYER requires WITH_GAMEENGINE
.endif
PLIST_SUB+=	PLAYER=""
CMAKE_ARGS+=	-DWITH_PLAYER:BOOL=ON
.else
PLIST_SUB+=	PLAYER="@comment "
CMAKE_ARGS+=	-DWITH_PLAYER:BOOL=OFF
.endif

.if defined(WITH_REDCODE)
.if defined(WITHOUT_OPENJPEG)
BROKEN=		WITH_REDCODE requires WITH_OPENJPEG
.endif
CMAKE_ARGS+=	-DWITH_IMAGE_REDCODE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_IMAGE_REDCODE:BOOL=OFF
.endif

.if defined(WITHOUT_SAMPLERATE)
CMAKE_ARGS+=	-DWITH_SAMPLERATE:BOOL=OFF
.else
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
CMAKE_ARGS+=	-DWITH_SAMPLERATE:BOOL=ON
.endif

.if defined(WITHOUT_SDL)
CMAKE_ARGS+=	-DWITH_SDL:BOOL=OFF
.else
.if defined(WITHOUT_SAMPLERATE)
BROKEN=		WITH_SDL requires WITH_SAMPLERATE
.endif
USE_SDL=	sdl
CMAKE_ARGS+=	-DWITH_SDL:BOOL=ON
.endif

.if defined(WITH_SNDFILE)
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
CMAKE_ARGS+=	-DWITH_CODEC_SNDFILE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_CODEC_SNDFILE:BOOL=OFF
.endif

.if defined(WITHOUT_TIFF)
CMAKE_ARGS+=	-DWITH_IMAGE_TIFF:BOOL=OFF
.else
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
CMAKE_ARGS+=	-DWITH_IMAGE_TIFF:BOOL=ON
.endif

.if defined(WITHOUT_XINPUT)
CMAKE_ARGS+=	-DWITH_X11_XINPUT:BOOL=OFF
.else
USE_XORG+=	xi
CMAKE_ARGS+=	-DWITH_X11_XINPUT:BOOL=ON
.endif

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/blender ${PREFIX}/bin/blender
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/blender \
		${PREFIX}/bin/blender-bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/bin/blender-thumbnailer.py \
		${PREFIX}/bin/blender-thumbnailer.py

.if defined(WITH_PLAYER)
	@${INSTALL_SCRIPT} ${WRKDIR}/blenderplayer ${PREFIX}/bin/blenderplayer
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/blenderplayer \
		${PREFIX}/bin/blenderplayer-bin
.endif

	@${CP} -R ${OUTDIR}/scripts ${DATADIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/bin/${PORTNAME}.svg \
		${PREFIX}/share/pixmaps/${PORTNAME}.svg

.if !defined(WITHOUT_NLS)
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

.if !defined(WITHOUT_MENU)
	@${MKDIR} ${DESKTOPDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/bin/${PORTNAME}.desktop \
		${DESKTOPDIR}
	@-update-desktop-database -q
.endif

.include <bsd.port.post.mk>
