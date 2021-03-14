# $FreeBSD$

PORTNAME=	strawberry
DISTVERSION=	0.9.1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/strawberrymusicplayer/${PORTNAME}/releases/download/${DISTVERSION}/ \
		https://files.jkvinge.net/packages/strawberry/

MAINTAINER=	menelkir@itroll.org
COMMENT=	Fork of clementine with many features

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libprotobuf.so:devel/protobuf \
		libtag.so:audio/taglib
TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		compiler:c++11-lang cmake desktop-file-utils gnome \
		gettext-runtime gettext-tools iconv pkgconfig \
		qt:5 sqlite pkgconfig tar:xz xorg

USE_GNOME=	glib20
USE_GSTREAMER1=	yes
USE_QT=		buildtools_build concurrent core dbus gui network \
		linguisttools qmake_build sql testlib_build widgets x11extras
USE_XORG=	ice sm x11 xcb xext
INSTALLS_ICONS=	yes

CMAKE_ARGS=	-DUSE_SYSTEM_TAGLIB=ON -DENABLE_UDISKS2=OFF \
		-DENABLE_GSTREAMER:BOOL=true \
		-DENABLE_TRANSLATIONS:BOOL=true

TEST_TARGET=	strawberry_test

# NLS is not optional, as of 0.6.11,
# src/core/utilities.cpp always includes iconv.h and calls iconv_*().

# GSTREAMER is not optional, as of 0.6.11, disabling it kills the build on
# src/core/mainwindow.cpp:229:7:
# error: member initializer 'transcode_dialog_' does not name a non-static data member or base class
# transcode_dialog_([=]() {

OPTIONS_DEFINE=		AUDIOCD IPOD MOODBAR MTPDEV MUSICBRAINZ \
			SUBSONIC TIDAL VLC

OPTIONS_DEFAULT=	PULSEAUDIO MOODBAR

OPTIONS_MULTI=		SOUND
OPTIONS_MULTI_SOUND=	ALSA PULSEAUDIO

AUDIOCD_DESC=		Enable support for Audio CDs
IPOD_DESC=		Enable support for iPod Classic
MOODBAR_DESC=		Enable moodbar
MTPDEV_DESC=		Enable support for Media Transport Protocol
MUSICBRAINZ_DESC=	Enable tag fetching from MusicBrainz
SUBSONIC_DESC=		Enable support for Subsonic music streamer
TIDAL_DESC=		Enable support for TIDAL music service
VLC_DESC=		Multimedia support via (lib)vlc

ALSA_CMAKE_BOOL=	ENABLE_ALSA
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

AUDIOCD_CMAKE_BOOL=	ENABLE_AUDIOCD
AUDIOCD_LIB_DEPENDS=	libcdio.so:sysutils/libcdio

IPOD_CMAKE_BOOL=	ENABLE_LIBGPOD
IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod \
			libimobiledevice-1.0.so:comms/libimobiledevice \
			libplist-2.0.so:devel/libplist

MTPDEV_CMAKE_BOOL=	ENABLE_LIBMTP
MTPDEV_LIB_DEPENDS=	libmtp.so:multimedia/libmtp

MOODBAR_CMAKE_BOOL=	ENABLE_MOODBAR
MOODBAR_LIB_DEPENDS=	libfftw3.so:math/fftw3

MUSICBRAINZ_CMAKE_BOOL=	ENABLE_CHROMAPRINT
MUSICBRAINZ_LIB_DEPENDS=	libchromaprint.so:audio/chromaprint

PULSEAUDIO_CMAKE_BOOL=	ENABLE_LIBPULSE
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

SUBSONIC_CMAKE_BOOL=	ENABLE_SUBSONIC

TIDAL_CMAKE_BOOL=	ENABLE_TIDAL

VLC_CMAKE_BOOL=		ENABLE_VLC
VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc

.include <bsd.port.mk>
