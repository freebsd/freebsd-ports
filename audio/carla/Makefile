PORTNAME=	Carla
PORTVERSION=	2.6.0.a1.g20260319
CATEGORIES=	audio

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Audio plugin host for Jack and PulseAudio
WWW=		https://kx.studio/Applications:Carla \
		https://github.com/falkTX/Carla

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL.txt

LIB_DEPENDS=	liblo.so:audio/liblo \
		libsndfile.so:audio/libsndfile
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyliblo3>0:audio/py-pyliblo3@${PY_FLAVOR}

USES=		compiler:c++11-lib desktop-file-utils gl gmake localbase:ldflags \
		pkgconfig pyqt:6 python qt:6 sdl shared-mime-info shebangfix \
		tar:bz2 xorg
USE_PYQT=	pyqt6
USE_QT=		base
USE_GL=		gl
USE_XORG=	x11
USE_SDL=	sdl2
USE_LDCONFIG=	${PREFIX}/lib/carla

CONFLICTS_BUILD=	rtaudio rtmidi

SHEBANG_FILES=	bin/ data/ source/native-plugins/resources/ source/frontend/

USE_GITHUB=	yes
GH_ACCOUNT=	falkTX
GH_TAGNAME=	97a9e0740baf6df2df942495c02532a624c44682

MAKE_ARGS=	HAVE_QT4=false \
		HAVE_QT5=false \
		HAVE_FFMPEG=false \
		EXTERNAL_PLUGINS=false \
		PREFIX=${LOCALBASE}

OPTIONS_DEFINE=		FLUIDSYNTH
OPTIONS_DEFAULT=	FLUIDSYNTH JACK
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	JACK PULSEAUDIO
BACKEND_DESC=		Audio backend

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_MAKE_ARGS_OFF=	HAVE_FLUIDSYNTH=false

JACK_BUILD_DEPENDS=		jackit>0:audio/jack
JACK_RUN_DEPENDS=		${LOCALBASE}/lib/libjack.so:audio/jack
JACK_MAKE_ARGS_OFF=		HAVE_JACK=false

PULSEAUDIO_LIB_DEPENDS=		libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_MAKE_ARGS_OFF=	HAVE_PULSEAUDIO=false

CFLAGS_powerpc64=	-DEEL_TARGET_PORTABLE

post-install:
	@${SED} -i '' -e 's|^PYTHON=.*|PYTHON=${PYTHON_CMD}|' \
		${STAGEDIR}${PREFIX}/bin/carla*
	${RMDIR} ${STAGEDIR}${PREFIX}/share/carla/resources/translations

devel-features: patch
	@${ECHO} "Developer command: show build features"
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} features

.include <bsd.port.mk>
