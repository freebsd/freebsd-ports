# $FreeBSD$

PORTNAME=	kwave
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sound editor for KDE

BUILD_DEPENDS=	convert:graphics/ImageMagick
LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libFLAC.so:audio/flac \
		libfftw3.so:math/fftw3 \
		libid3.so:audio/id3lib \
		libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libsamplerate.so:audio/libsamplerate \
		libvorbisenc.so:audio/libvorbis

USES=		cmake:outsource desktop-file-utils gettext kde:5 \
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

.include <bsd.port.pre.mk>

.  if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100000 && ${OSVERSION} < 1101505
BUILD_DEPENDS+=		llvm50>=0:devel/llvm50
# Build is broken on 11.x as clang is not new enough.
# Workaround by manually setting CC to clang50.
CC=		${LOCALBASE}/bin/clang50
CXX=		${LOCALBASE}/bin/clang++50
.  endif

.include <bsd.port.post.mk>
