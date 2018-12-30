# $FreeBSD$

PORTNAME=		cantata
DISTVERSIONPREFIX=	v
DISTVERSION=		2.3.3
CATEGORIES=		audio kde

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Graphical client for MPD using Qt5

LICENSE=		GPLv3
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			cmake compiler:c++11-lang cpe pkgconfig qt:5 shebangfix
USE_GITHUB=		yes
GH_ACCOUNT=		CDrummond

USE_QT=			buildtools_build concurrent core dbus gui network \
			qmake_build sql sql-sqlite3_run svg widgets xml

CMAKE_ON=		CMAKE_DISABLE_FIND_PACKAGE_UDev

SHEBANG_FILES=		playlists/cantata-dynamic cantata-remote.cmake
CPE_VENDOR=		craig_drummond
USE_LDCONFIG=		yes

OPTIONS_DEFINE=		CDPARANOIA MTP NLS PROXY TAGLIB
OPTIONS_GROUP=		CDINFO REPLAYGAIN
OPTIONS_GROUP_CDINFO=	CDDB MUSICBRAINZ
OPTIONS_GROUP_REPLAYGAIN=	FFMPEG MPG123
OPTIONS_RADIO=		HSP
OPTIONS_RADIO_HSP=	QT5 VLC
OPTIONS_DEFAULT=	CDDB CDPARANOIA FFMPEG MPG123 MTP MUSICBRAINZ TAGLIB VLC
OPTIONS_SUB=		yes

CDDB_DESC=		CD info retrieval via CDDB
CDINFO_DESC=		AudioCD support
FFMPEG_DESC=		ReplayGain calculation support via FFmpeg
HSP_DESC=		MPD HTTP stream playback
MPG123_DESC=		ReplayGain calculation support via mpg123
MUSICBRAINZ_DESC=	CD info retrieval via MusicBrainz
PROXY_DESC=		Proxy configuration in settings dialog
QT5_DESC=		HTTP streams support via QtMultimedia
REPLAYGAIN_DESC=	Replaygain calculation support
TAGLIB_DESC=		Reading and editing Meta-Data of audio files
VLC_DESC=		HTTP streams support via libVLC

CDDB_IMPLIES=		CDPARANOIA
CDDB_LIB_DEPENDS=	libcddb.so:audio/libcddb
CDDB_CMAKE_BOOL=	ENABLE_CDDB

CDPARANOIA_IMPLIES=	TAGLIB
CDPARANOIA_LIB_DEPENDS=	libcdda_interface.so:audio/cdparanoia
CDPARANOIA_CMAKE_BOOL=	ENABLE_CDPARANOIA

FFMPEG_IMPLIES=		TAGLIB
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	ENABLE_FFMPEG

MPG123_IMPLIES=		TAGLIB
MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MPG123_CMAKE_BOOL=	ENABLE_MPG123

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_CMAKE_BOOL=		ENABLE_MTP

MUSICBRAINZ_IMPLIES=	CDPARANOIA
MUSICBRAINZ_LIB_DEPENDS=libmusicbrainz5.so:audio/libmusicbrainz5
MUSICBRAINZ_CMAKE_BOOL=	ENABLE_MUSICBRAINZ

NLS_USE=		QT=linguisttools_build
NLS_CMAKE_ON=		-DLCONVERT_EXECUTABLE:STRING=${QT_BINDIR}/lconvert \
			-DLRELEASE_EXECUTABLE:STRING=${QT_BINDIR}/lrelease
NLS_CMAKE_OFF=		-DLCONVERT_EXECUTABLE:BOOL=FALSE \
			-DLRELEASE_EXECUTABLE:BOOL=FALSE

PROXY_CMAKE_BOOL=	ENABLE_PROXY_CONFIG

QT5_USE=		QT=multimedia

TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib \
			libtag-extras.so:audio/taglib-extras
TAGLIB_USES=		localbase
TAGLIB_CMAKE_BOOL=	ENABLE_TAGLIB ENABLE_TAGLIB_EXTRAS

VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc
VLC_CMAKE_BOOL=		ENABLE_LIBVLC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFFMPEG} || ${PORT_OPTIONS:MMPG123}
LIB_DEPENDS+=		libebur128.so:audio/libebur128
PLIST_SUB+=		REPLAYGAIN=""
.else
PLIST_SUB+=		REPLAYGAIN="@comment "
.endif

.if ${PORT_OPTIONS:MQT5} || ${PORT_OPTIONS:MVLC}
CMAKE_ARGS+=		-DENABLE_HTTP_STREAM_PLAYBACK:BOOL=TRUE
.else
CMAKE_ARGS+=		-DENABLE_HTTP_STREAM_PLAYBACK:BOOL=FALSE
.endif

.include <bsd.port.mk>
