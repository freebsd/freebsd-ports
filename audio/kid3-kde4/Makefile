# $FreeBSD$

PORTNAME=	kid3
PORTVERSION=	3.5.1
PORTREVISION?=	1
CATEGORIES=	audio kde
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	MP3/Ogg/FLAC tag editor for KDE

LICENSE=	GPLv2+

USES=		cmake:outsource kde:4 pkgconfig
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DWITH_DOCBOOKDIR=${LOCALBASE}/share/xsl/docbook \
		-DWITH_LIBDIR=lib \
		-DWITH_MANDIR=man \
		-DWITH_PLUGINSDIR=lib/kid3 \
		-DFFMPEG_ROOT=${LOCALBASE} \
		-DWITH_QML=OFF

OPTIONS_DEFINE=		CLI ACOUSTID FLAC MP3 MP4 VORBIS TAGLIB PHONON
OPTIONS_DEFAULT=	CLI ACOUSTID FLAC MP3 MP4 VORBIS TAGLIB
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes

.if defined(PKGNAMESUFFIX)
# Qt 4 and Qt 5
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl

USES+=		desktop-file-utils
USE_GNOME=	libxslt:build
CMAKE_ARGS+=	-DWITH_APPS="${KID3_CLI}QT"
PLIST_SUB+=	QT="" KDE="@comment "
.  if ${PKGNAMESUFFIX} == "-qt5"
# Qt 5 only
CONFLICTS_INSTALL=	kid3-3.* kid3-qt4-3.*

USE_QT5=	core dbus gui multimedia network testlib xml widgets \
		buildtools_build linguisttools_build qmake_build
CMAKE_ARGS+=	-DWITH_QT5=true
OPTIONS_EXCLUDE=PHONON
.  elif ${PKGNAMESUFFIX} == "-qt4"
# Qt 4 only
CONFLICTS_INSTALL=	kid3-3.* kid3-qt5-3.*

USE_QT4=	corelib dbus gui network xml \
		qmake_build moc_build rcc_build uic_build \
		linguisttools_build
.  endif
.else
# KDE 4 only
CONFLICTS_INSTALL=	kid3-qt4-3.* kid3-qt5-3.*

USE_QT4=	corelib dbus gui network svg xml \
		qmake_build moc_build rcc_build uic_build \
		linguisttools_build
USE_KDE=	kdelibs automoc4
CMAKE_ARGS+=	-DWITH_APPS="${KID3_CLI}KDE"
PLIST_SUB+=	QT="@comment " KDE=""
OPTIONS_SLAVE=	PHONON
.endif

PLIST_SUB+=	SHLIB_VER=${PORTVERSION}

ACOUSTID_LIB_DEPENDS=	libchromaprint.so:audio/chromaprint \
			libavcodec.so:multimedia/ffmpeg
ACOUSTID_CMAKE_BOOL=	WITH_CHROMAPRINT WITH_FFMPEG

CLI_DESC=		Build and install command line utility
CLI_USES=		readline
CLI_VARS=		KID3_CLI=CLI;

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CMAKE_BOOL=	WITH_FLAC

MP3_LIB_DEPENDS=	libid3.so:audio/id3lib
MP3_CMAKE_BOOL=		WITH_ID3LIB

MP4_LIB_DEPENDS=	libmp4v2.so:multimedia/mp4v2
MP4_CMAKE_BOOL=		WITH_MP4V2

PHONON_USE=		QT4=phonon
PHONON_CMAKE_BOOL=	WITH_PHONON

TAGLIB_DESC=		Various audio formats support via Taglib
TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CMAKE_BOOL=	WITH_TAGLIB

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_CMAKE_BOOL=	WITH_VORBIS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLAC} || ${PORT_OPTIONS:MVORBIS}
PLIST_SUB+=	OGGFLAC=""
.else
PLIST_SUB+=	OGGFLAC="@comment "
.endif

.include <bsd.port.mk>
