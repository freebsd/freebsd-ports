# Created by: elbarto
# $FreeBSD$

PORTNAME=	higan
PORTVERSION=	0.92
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}-source

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Nintendo multi-system emulator

USES=		pkgconfig
USE_XZ=		yes
USE_GMAKE=	yes
USE_GCC=	yes
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	i386 amd64
MAKE_ENV+=	c="${CC} -std=gnu99" cpp="${CXX} -std=gnu++0x"

OPTIONS_DEFINE=		DEBUG
OPTIONS_SINGLE=		PROFILE GUI
OPTIONS_SINGLE_PROFILE=	ACCURACY BALANCED PERFORMANCE
OPTIONS_SINGLE_GUI=	GTK2 QT4
OPTIONS_MULTI=		VIDEO SOUND INPUT
OPTIONS_MULTI_VIDEO=	GLX SDL XV
OPTIONS_MULTI_SOUND=	AO OPENAL OSS PULSEAUDIO
OPTIONS_MULTI_INPUT=	INPUT_SDL INPUT_X
OPTIONS_DEFAULT=	BALANCED GTK2 GLX XV SDL \
			OSS INPUT_SDL INPUT_X

ACCURACY_DESC=		Use accuracy profile
BALACNED_DESC=		Use balanced profile
PERFORMANCE_DESC=	Use performance profile
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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MACCURACY}
MAKE_ENV+=	profile="accuracy"
.elif ${PORT_OPTIONS:MBALANCED}
MAKE_ENV+=	profile="balanced"
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
USES+=		openal:al
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
		${WRKSRC}/higan/target-ethos/Makefile
.if ${PORT_OPTIONS:MDEBUG}
	${REINPLACE_CMD} -e 's|-O3|-g|g' \
		${WRKSRC}/ananke/Makefile \
		${WRKSRC}/higan/Makefile
	${REINPLACE_CMD} -e 's|:= -s|:= #|g' \
		${WRKSRC}/higan/Makefile
.endif
	${RM} ${WRKSRC}/shaders/Sepia.Direct3D.shader

do-build:
.for d in higan ananke
.if ${PORT_OPTIONS:MQT4}
	cd ${WRKSRC}/${d}/phoenix/qt && ${MOC} -i -o platform.moc platform.moc.hpp
.endif
	cd ${WRKSRC}/${d} && ${GMAKE} ${MAKE_ENV}
.endfor

do-install:
	${INSTALL_LIB} ${WRKSRC}/ananke/libananke.so ${PREFIX}/lib/libananke.so.1
	${LN} -sf ${PREFIX}/lib/libananke.so.1 ${PREFIX}/lib/libananke.so
	${INSTALL_PROGRAM} ${WRKSRC}/higan/out/higan ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/higan/data/higan.png ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/higan/data/higan.desktop ${PREFIX}/share/applications/
	${MKDIR} ${DATADIR}/Video\ Shaders
	(cd ${WRKSRC}/higan/profile && ${COPYTREE_SHARE} \* ${DATADIR}/)
	${INSTALL_DATA} ${WRKSRC}/shaders/* ${DATADIR}/Video\ Shaders/

.include <bsd.port.mk>
