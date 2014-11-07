# $FreeBSD$

PORTNAME=	kid3
PORTVERSION=	3.1.1
CATEGORIES=	audio kde
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT?=	MP3/Ogg/FLAC tag editor for KDE

LICENSE=	GPLv2

USE_PERL5=	build
USES=		cmake:outsource perl5
CMAKE_ARGS=	-DWITH_DOCBOOKDIR=${LOCALBASE}/share/xsl/docbook \
		-DWITH_MANDIR=man \
		-DFFMPEG_ROOT=${LOCALBASE}
CXXFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	CHROMAPRINT FLAC ID3LIB MP4V2 VORBIS TAGLIB \
		CLI
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
OPTIONS_SUB=	yes
NO_OPTIONS_SORT=	yes

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-qt5"
CONFLICTS_INSTALL+=	kid3-qt4-3.*

USE_QT5=	core dbus gui multimedia network testlib xml widgets \
		buildtools_build linguisttools_build qmake_build
CMAKE_ARGS+=	-DWITH_QT5=true
.else
# Qt 4 and KDE 4
USE_QT4=	qmake_build moc_build rcc_build uic_build \
		linguist_build
.endif

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-qt4"
CONFLICTS_INSTALL+=	kid3-qt5-3.*

USE_QT4+=	corelib dbus gui network xml

OPTIONS_DEFINE+=	PHONON
PHONON_DESC=	Build with Phonon support
PHONON_CMAKE_OFF=	-DWITH_PHONON=OFF
PHONON_USE=	QT4=phonon
.endif

.if defined(PKGNAMESUFFIX)
# Qt 4 and Qt 5
CONFLICTS_INSTALL+=	kid3-3.*

BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

USES+=		desktop-file-utils
USE_GNOME=	libxslt:build
CMAKE_ARGS+=	-DWITH_APPS="${KID3_CLI}QT"
PLIST_SUB+=	QT="" KDE="@comment "
.else
CONFLICTS_INSTALL+=	kid3-qt4-3.* kid3-qt5-3.*

USE_KDE4=	kdelibs automoc4 kdeprefix
CMAKE_ARGS+=	-DWITH_APPS="${KID3_CLI}KDE"
PLIST_SUB+=	QT="@comment " KDE=""
.endif

PLIST_SUB+=	SHLIB_VER=${PORTVERSION}

CLI_DESC=	Build and install command line utility
CLI_USES=	readline

FLAC_DESC=	Support for FLAC files
FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CMAKE_ON=		-DWITH_FLAC=ON
FLAC_CMAKE_OFF=		-DWITH_FLAC=OFF

ID3LIB_DESC=	Support for mp3 files
ID3LIB_LIB_DEPENDS=	libid3.so:${PORTSDIR}/audio/id3lib
ID3LIB_CMAKE_ON=	-DWITH_ID3LIB=ON
ID3LIB_CMAKE_OFF=	-DWITH_ID3LIB=OFF

MP4V2_DESC=	Support for mp4 files
MP4V2_LIB_DEPENDS=	libmp4v2.so:${PORTSDIR}/multimedia/mp4v2
MP4V2_CMAKE_ON=		-DWITH_MP4V2=ON
MP4V2_CMAKE_OFF=	-DWITH_MP4V2=OFF

VORBIS_DESC=	Support for Ogg/Vorbis files
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
			libogg.so:${PORTSDIR}/audio/libogg
VORBIS_CMAKE_ON=	-DWITH_VORBIS=ON
VORBIS_CMAKE_OFF=	-DWITH_VORBIS=OFF

TAGLIB_DESC=	Support for various audio formats
TAGLIB_LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib
TAGLIB_CMAKE_ON=	-DWITH_TAGLIB=ON
TAGLIB_CMAKE_OFF=	-DWITH_TAGLIB=OFF

CHROMAPRINT_DESC=	Support for Chromaprint audio fingerprints
CHROMAPRINT_LIB_DEPENDS=	libchromaprint.so:${PORTSDIR}/audio/chromaprint
CHROMAPRINT_CMAKE_ON=	-DWITH_CHROMAPRINT=ON
CHROMAPRINT_CMAKE_OFF=	-DWITH_CHROMAPRINT=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLI}
KID3_CLI=	CLI;
.endif

.if ${PORT_OPTIONS:MFLAC} || ${PORT_OPTIONS:MVORBIS}
PLIST_SUB+=	OGGFLAC=""
.else
PLIST_SUB+=	OGGFLAC="@comment "
.endif

.include <bsd.port.mk>
