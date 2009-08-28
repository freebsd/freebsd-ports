# New ports collection makefile for:    bsnes
# Date created:                         2009-06-13
# Whom:                                 elbarto
#
# $FreeBSD$

PORTNAME=	bsnes
PORTVERSION=	0.50
CATEGORIES=	emulators
MASTER_SITES=	http://byuusan.kuro-hitsuji.net/ \
		ftp://ftp.arcadebsd.org/pub/ArcadeBSD/ports/distfiles/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}

MAINTAINER=	elbarto@ArcadeBSD.org
COMMENT=	Super Nintendo/Super Famicom emulator

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	videoproto xv x11
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build rcc_build gui

ONLY_FOR_ARCHS=	i386 amd64
WRKSRC=		${WRKDIR}/src/
MAKE_ENV+=	enable_gzip=true

OPTIONS=	VIDEO_GLX "Build GLX Video Driver" on \
		VIDEO_XV "Build Xv Video Driver" off \
		VIDEO_SDL "Build SDL Video Driver" on \
		VIDEO_QT "Build QtImage Video Driver" off \
		SOUND_OPENAL "Build OpenAL Sound Driver" off \
		SOUND_OSS "Build OSS Sound Driver" on \
		SOUND_PULSE "Build Pulseaudio Sound Driver" off \
		SOUND_AO "Build AO Sound Driver" off \
		INPUT_X "Build X Input Driver" on \
		INPUT_SDL "Build SDL Input Driver" on

.include <bsd.port.pre.mk>

.if defined(WITH_VIDEO_GLX)
USE_GL+=	gl
VIDEO_DRIVER+=	video.glx
.endif

.if defined(WITH_VIDEO_XV)
VIDEO_DRIVER+=	video.xv
.endif

.if defined(WITH_VIDEO_SDL)
USE_SDL+=	sdl
VIDEO_DRIVER+=	video.sdl
.endif

.if defined(WITH_VIDEO_QT)
VIDEO_DRIVER+=	video.qtimage
.endif

.if defined(WITH_SOUND_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
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
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao
AUDIO_DRIVER+=	audio.ao
.endif

.if defined(WITH_INPUT_X)
INPUT_DRIVER+=	input.x
.endif

.if defined(WITH_INPUT_SDL)
USE_SDL+=	sdl
INPUT_DRIVER+=	input.sdl
.endif

.if !defined(VIDEO_DRIVER)
IGNORE=	you have to choose at least a video driver first
.endif

.if !defined(AUDIO_DRIVER)
IGNORE=	you have to choose at least a audio driver first
.endif

.if !defined(INPUT_DRIVER)
IGNORE=	you have to choose at least an input driver first
.endif

PLIST_FILES=	bin/bsnes

post-patch:
	${REINPLACE_CMD} -e 's|VIDEO|${VIDEO_DRIVER}|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|AUDIO|${AUDIO_DRIVER}|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|INPUT|${INPUT_DRIVER}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.post.mk>
