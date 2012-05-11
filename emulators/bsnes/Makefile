# New ports collection makefile for:    bsnes
# Date created:                         2009-06-13
# Whom:                                 elbarto
#
# $FreeBSD$

PORTNAME=	bsnes
PORTVERSION=	0.88
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}-source

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Super Nintendo/Super Famicom emulator

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_GCC=	4.6

ONLY_FOR_ARCHS=	i386 amd64
MAKE_ENV+=	c="${CC} -std=gnu99" cpp="${CXX} -std=gnu++0x" profile="performance"
USE_LDCONFIG=	yes

OPTIONS=	GUI_GTK "Build with GTK+ GUI" on \
		GUI_QT4 "Build with QT4 GUI" off \
		VIDEO_GLX "Build GLX Video Driver" on \
		VIDEO_XV "Build Xv Video Driver" on \
		VIDEO_SDL "Build SDL Video Driver" on \
		SOUND_OPENAL "Build OpenAL Sound Driver" off \
		SOUND_OSS "Build OSS Sound Driver" on \
		SOUND_PULSE "Build Pulseaudio Sound Driver" off \
		SOUND_AO "Build AO Sound Driver" off \
		INPUT_X "Build X Input Driver" on \
		INPUT_SDL "Build SDL Input Driver" on

.include <bsd.port.options.mk>

.if defined(WITH_GUI_GTK)
MAKE_ENV+=	phoenix="gtk"
.else
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui
MAKE_ENV+=	phoenix="qt"
.endif

.if defined(WITH_VIDEO_GLX)
USE_GL+=	gl
VIDEO_DRIVER+=	video.glx
.endif

.if defined(WITH_VIDEO_XV)
USE_XORG+=	xv
VIDEO_DRIVER+=	video.xv
.endif

.if defined(WITH_VIDEO_SDL)
USE_XORG+=	xv
USE_SDL+=	sdl
VIDEO_DRIVER+=	video.sdl
.endif

.if defined(WITH_SOUND_OPENAL)
USE_OPENAL=	al
AUDIO_DRIVER+=	audio.openal
.endif

.if defined(WITH_SOUND_OSS)
AUDIO_DRIVER+=	audio.oss
.endif

.if defined(WITH_SOUND_PULSE)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
AUDIO_DRIVER+=	audio.pulseaudio
.endif

.if defined(WITH_SOUND_AO)
LIB_DEPENDS+=	ao.4:${PORTSDIR}/audio/libao
AUDIO_DRIVER+=	audio.ao
.endif

.if defined(WITH_INPUT_X)
INPUT_DRIVER+=	input.x
.endif

.if defined(WITH_INPUT_SDL)
USE_SDL+=	sdl
INPUT_DRIVER+=	input.sdl
.endif

.if !defined(WITH_GUI_GTK) && !defined(WITH_GUI_QT4)
IGNORE=	you have to choose a GUI
.endif
.if defined(WITH_GUI_GTK) && defined(WITH_GUI_QT4)
IGNORE=	you may only choose one GUI
.endif

.if !defined(VIDEO_DRIVER)
IGNORE=	you have to choose at least one video driver
.endif

.if !defined(AUDIO_DRIVER)
IGNORE=	you have to choose at least one audio driver
.endif

.if !defined(INPUT_DRIVER)
IGNORE=	you have to choose at least one input driver
.endif

post-patch:
	${REINPLACE_CMD} -e 's|VIDEO|${VIDEO_DRIVER}|' ${WRKSRC}/bsnes/target-ui/Makefile
	${REINPLACE_CMD} -e 's|AUDIO|${AUDIO_DRIVER}|' ${WRKSRC}/bsnes/target-ui/Makefile
	${REINPLACE_CMD} -e 's|INPUT|${INPUT_DRIVER}|' ${WRKSRC}/bsnes/target-ui/Makefile

do-build:
	(cd ${WRKSRC}/bsnes && ${GMAKE} ${MAKE_ENV})
	(cd ${WRKSRC}/purify && ${GMAKE} ${MAKE_ENV})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsnes/out/bsnes ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/purify/purify ${PREFIX}/bin/snespurify
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/bsnes/data/bsnes.png ${PREFIX}/share/pixmaps/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/bsnes/data/bsnes.desktop ${PREFIX}/share/applications/

.include <bsd.port.mk>
