# Created by: elbarto
# $FreeBSD$

PORTNAME=	higan
PORTVERSION=	0.94
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://byuu.org/files/ \
		http://www.cyberbotx.com/higan/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}-source

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Nintendo multi-system emulator

USES=		compiler:c++11-lib gmake pkgconfig tar:xz
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	i386 amd64
MAKE_ENV+=	compiler="${CXX}" cflags="-x c -std=c99 ${CFLAGS}" \
		cppflags="-x c++ -std=c++11 ${CXXFLAGS}"

OPTIONS_DEFINE=		DEBUG
OPTIONS_SINGLE=		PROFILE GUI
OPTIONS_SINGLE_PROFILE=	ACCURACY BALANCED PERFORMANCE
OPTIONS_SINGLE_GUI=	GTK2 QT4
OPTIONS_MULTI=		VIDEO SOUND INPUT
OPTIONS_MULTI_VIDEO=	GLX SDL XSHM XV
OPTIONS_MULTI_SOUND=	AO OPENAL OSS PULSEAUDIO
OPTIONS_MULTI_INPUT=	INPUT_SDL INPUT_X
OPTIONS_DEFAULT=	BALANCED GTK2 GLX XSHM XV SDL \
			OSS INPUT_SDL INPUT_X

ACCURACY_DESC=		Use accuracy profile
BALANCED_DESC=		Use balanced profile
PERFORMANCE_DESC=	Use performance profile
GTK2_DESC=		Build with GTK+2 GUI
QT4_DESC=		Build with QT4 GUI
GLX_DESC=		Build GLX video driver
SDL_DESC=		Build SDL video driver
XSHM_DESC=		Build XShm video driver
XV_DESC=		Build Xv video driver
AO_DESC=		Build AO sound driver
OPENAL_DESC=		Build OpenAL sound driver
OSS_DESC=		Build OSS sound driver
PULSEAUDIO_DESC=	Build Pulseaudio sound driver
INPUT_SDL_DESC=		Build SDL input driver
INPUT_X_DESC=		Build X input driver

ACCURACY_MAKE_ENV=	profile="accuracy"
BALANCED_MAKE_ENV=	profile="balanced"
PERFORMANCE_MAKE_ENV=	profile="performance"

GTK2_USE=	GNOME=gtk20
GTK2_MAKE_ENV=	phoenix="gtk"

QT4_USE=	QT4=gui,moc_build
QT4_MAKE_ENV=	phoenix="qt"

GLX_USE=	GL=gl
GLX_VARS=	VIDEO_DRIVER+=video.glx

SDL_USE=	XORG=xv SDL=sdl
SDL_VARS=	VIDEO_DRIVER+=video.sdl

XSHM_USE=	XORG=xext
XSHM_VARS=	VIDEO_DRIVER+=video.xshm

XV_USE=		XORG=xv
XV_VARS=	VIDEO_DRIVER+=video.xv

AO_LIB_DEPENDS=	libao.so:audio/libao
AO_VARS=	AUDIO_DRIVER+=audio.ao

OPENAL_USES=	openal:al
OPENAL_VARS=	AUDIO_DRIVER+=audio.openal

OSS_VARS=	AUDIO_DRIVER+=audio.oss

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	AUDIO_DRIVER+=audio.pulseaudio

INPUT_SDL_USE=	SDL=sdl
INPUT_SDL_VARS=	INPUT_DRIVER+=input.sdl

INPUT_X_VARS=	INPUT_DRIVER+=input.xlib

post-patch:
	${REINPLACE_CMD} \
		-e 's|%%VIDEO%%|${VIDEO_DRIVER}|' \
		-e 's|%%AUDIO%%|${AUDIO_DRIVER}|' \
		-e 's|%%INPUT%%|${INPUT_DRIVER}|' \
		${WRKSRC}/target-ethos/Makefile
	${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|' \
		${WRKSRC}/nall/string/platform.hpp

post-patch-DEBUG-on:
	${REINPLACE_CMD} -e 's|-O3|-g|g' \
		${WRKSRC}/ananke/Makefile \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|:= -s|:= #|g' \
		${WRKSRC}/Makefile

pre-build-QT4-on:
	(cd ${WRKSRC}/phoenix/qt && ${MOC} -i -o platform.moc platform.moc.hpp)

do-build:
.for d in . ananke
	(cd ${WRKSRC}/${d} && ${MAKE_CMD} ${MAKE_ENV})
.endfor

do-install:
	${INSTALL_LIB} ${WRKSRC}/ananke/libananke.so ${STAGEDIR}${PREFIX}/lib/libananke.so.1
	${LN} -sf libananke.so.1 ${STAGEDIR}${PREFIX}/lib/libananke.so
	${INSTALL_PROGRAM} ${WRKSRC}/out/higan ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/data/higan.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/data/higan.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${DATADIR}/shaders
	(cd ${WRKSRC}/profile && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/)
	(cd ${WRKSRC}/shaders && ${COPYTREE_SHARE} \*.shader ${STAGEDIR}${DATADIR}/shaders/)

.include <bsd.port.mk>
