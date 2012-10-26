# Created by: elbarto
# $FreeBSD$

PORTNAME=	bsnes
PORTVERSION=	0.91
CATEGORIES=	emulators
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}-source

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Super Nintendo/Super Famicom emulator

USE_XZ=		yes
USE_GMAKE=	yes
USE_GCC=	4.6+
USE_PKGCONFIG=	build

ONLY_FOR_ARCHS=	i386 amd64
MAKE_ENV+=	c="${CC} -std=gnu99" cpp="${CXX} -std=gnu++0x"

OPTIONS_SINGLE=		PROFILE GUI
OPTIONS_SINGLE_PROFILE=	ACCURACY COMPATIBILITY PERFORMANCE
OPTIONS_SINGLE_GUI=	GTK2 QT4
OPTIONS_MULTI=		VIDEO SOUND INPUT
OPTIONS_MULTI_VIDEO=	GLX SDL XV
OPTIONS_MULTI_SOUND=	AO OPENAL OSS PULSEAUDIO
OPTIONS_MULTI_INPUT=	INPUT_SDL INPUT_X
OPTIONS_DEFAULT=	COMPATIBILITY GTK2 GLX XV SDL \
			OSS INPUT_SDL INPUT_X

ACCURACY_DESC=		Favor accuracy over compatibility
COMPATIBILITY_DESC=	Favor compatibility over accuracy
PERFORMANCE_DESC=	Favor performance over accuracy
GTK2_DESC=		Build with GTK+2 GUI
QT4_DESC=		Build with QT4 GUI
GLX_DESC=		Build GLX video driver
SDL_DESC=		Build SDL video driver
XV_DESC=		Build Xv video driver
AO_DESC=		Build AO sound driver
OPENAL_DESC=		Build OpenAL sound driver
OSS_DESC=		Build OSS sound driver
PULSEAUDIO_DESC=	Build Pulseaudio sound driver
INPUT_SDL_DESC=		Build SDL input driver
INPUT_X_DESC=		Build X input driver

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MACCURACY}
MAKE_ENV+=	profile="accuracy"
.elif ${PORT_OPTIONS:MCOMPATIBILITY}
MAKE_ENV+=	profile="compatibility"
.else
MAKE_ENV+=	profile="performance"
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
MAKE_ENV+=	phoenix="gtk"
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4+=	gui moc_build
MAKE_ENV+=	phoenix="qt"
.endif

.if ${PORT_OPTIONS:MGLX}
USE_GL+=	gl
VIDEO_DRIVER+=	video.glx
.endif

.if ${PORT_OPTIONS:MXV}
USE_XORG+=	xv
VIDEO_DRIVER+=	video.xv
.endif

.if ${PORT_OPTIONS:MSDL}
USE_XORG+=	xv
USE_SDL+=	sdl
VIDEO_DRIVER+=	video.sdl
.endif

.if ${PORT_OPTIONS:MOPENAL}
USE_OPENAL+=	al
AUDIO_DRIVER+=	audio.openal
.endif

.if ${PORT_OPTIONS:MOSS}
AUDIO_DRIVER+=	audio.oss
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
AUDIO_DRIVER+=	audio.pulseaudio
.endif

.if ${PORT_OPTIONS:MAO}
LIB_DEPENDS+=	ao:${PORTSDIR}/audio/libao
AUDIO_DRIVER+=	audio.ao
.endif

.if ${PORT_OPTIONS:MINPUT_X}
INPUT_DRIVER+=	input.x
.endif

.if ${PORT_OPTIONS:MINPUT_SDL}
USE_SDL+=	sdl
INPUT_DRIVER+=	input.sdl
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's|%%VIDEO%%|${VIDEO_DRIVER}|' \
		-e 's|%%AUDIO%%|${AUDIO_DRIVER}|' \
		-e 's|%%INPUT%%|${INPUT_DRIVER}|' \
		${WRKSRC}/bsnes/target-ethos/Makefile

do-build:
.for d in bsnes purify
.if ${PORT_OPTIONS:MQT4}
	cd ${WRKSRC}/${d}/phoenix/qt && ${MOC} -i -o platform.moc platform.moc.hpp
.endif
	cd ${WRKSRC}/${d} && ${GMAKE} ${MAKE_ENV}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsnes/out/bsnes ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/purify/purify ${PREFIX}/bin/snespurify
	${INSTALL_DATA} ${WRKSRC}/bsnes/data/bsnes.png ${PREFIX}/share/pixmaps/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/bsnes/data/bsnes.desktop ${PREFIX}/share/applications/

.include <bsd.port.mk>
