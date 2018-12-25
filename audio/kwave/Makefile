# $FreeBSD$

PORTNAME=	kwave
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sound editor for KDE

BUILD_DEPENDS=	convert:graphics/ImageMagick6
LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libFLAC.so:audio/flac \
		libfftw3.so:math/fftw3 \
		libid3.so:audio/id3lib \
		libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libsamplerate.so:audio/libsamplerate \
		libvorbisenc.so:audio/libvorbis

USES=		cmake desktop-file-utils gettext kde:5 \
		localbase:ldflags pkgconfig qt:5 tar:xz
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm i18n iconthemes itemviews \
		jobwidgets kio service solid sonnet textwidgets widgetsaddons \
		xmlgui
USE_QT=		concurrent core dbus gui multimedia network widgets xml \
		buildtools_build qmake_build

OPTIONS_GROUP=			AUDIOPLUGIN
OPTIONS_GROUP_AUDIOPLUGIN=	ALSA PULSEAUDIO
ALSA_CMAKE_BOOL=		WITH_ALSA
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
PULSEAUDIO_CMAKE_BOOL=		WITH_PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
