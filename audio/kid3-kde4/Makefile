# $FreeBSD$

PORTNAME=	kid3
PORTVERSION=	3.6.2
PORTREVISION?=	2
CATEGORIES=	audio kde
MASTER_SITES=	SF
PKGNAMESUFFIX=	-${SLAVE}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Audio file tag editor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl

USES=		cmake gnome pkgconfig
USE_GNOME=	libxslt:build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DWITH_DOCBOOKDIR="${LOCALBASE}/share/xsl/docbook" \
		-DWITH_LIBDIR=lib \
		-DWITH_MANDIR=man \
		-DWITH_PLUGINSDIR=lib/kid3 \
		-DFFMPEG_ROOT="${LOCALBASE}" \
		-DWITH_QML=OFF \
		-DWITH_APPS="${KID3_APPS:S/ /;/gW}"
PLIST_SUB+=	SHLIB_VER=${PORTVERSION}

SLAVE?=		kde4
.if ${SLAVE} == qt4 || ${SLAVE} == qt5
# Qt4 and Qt5
USES+=		desktop-file-utils
PLIST_SUB+=	KDE="@comment " KDE4="@comment " KF5="@comment " QT="" QT_SUFX="-qt"
KID3_APPS+=	QT
.else
# KDE4 and KF5
PLIST_SUB+=	KDE="" QT="@comment " QT_SUFX=""
KID3_APPS+=	KDE
.endif

.if ${SLAVE} == kde4 || ${SLAVE} == qt4
# KDE4 and Qt4
DEPRECATED=	Qt4 and KDE4 EOL upstream. Use audio/kid3-qt5 or audio/kid3-kf5 instead 
EXPIRATION_DATE=	2018-12-31

USES+=		qt:4
USE_QT+=	corelib dbus gui network xml \
		qmake_build moc_build rcc_build uic_build \
		linguisttools_build
CMAKE_ON+=	WITH_QT4
.else
# KF5 and Qt5
USES+=		compiler:c++11-lang qt:5
USE_QT+=	core dbus gui multimedia network xml widgets \
		buildtools_build linguisttools_build qmake_build
CMAKE_ON+=	WITH_QT5
OPTIONS_EXCLUDE+=	PHONON
.endif

.if ${SLAVE} == kde4
# KDE4 only
USES+=		kde:4
USE_KDE+=	kdelibs automoc4
USE_QT+=	svg
PLIST_SUB+=	KDE4="" KF5="@comment "
OPTIONS_SLAVE+=	PHONON
.elif ${SLAVE} == kf5
# KF5 only
USES+=		desktop-file-utils kde:5
USE_KDE+=	auth codecs config configwidgets coreaddons \
		widgetsaddons xmlgui doctools_build ecm_build
PLIST_SUB+=	KDE4="@comment " KF5=""
.endif

.for s in kde4 kf5 qt4 qt5
.  if ${SLAVE} != ${s}
CONFLICTS_INSTALL+=	kid3-${s}
.  endif
.endfor

OPTIONS_DEFINE=		CLI ACOUSTID FLAC MP3 MP4 VORBIS TAGLIB PHONON TEST
OPTIONS_DEFAULT=	CLI ACOUSTID FLAC MP3 MP4 VORBIS TAGLIB
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes

ACOUSTID_LIB_DEPENDS=	libchromaprint.so:audio/chromaprint \
			libavcodec.so:multimedia/ffmpeg
ACOUSTID_CMAKE_BOOL=	WITH_CHROMAPRINT WITH_FFMPEG

CLI_DESC=		Build and install command line utility
CLI_USES=		python:3.4+,test readline
CLI_VARS=		KID3_APPS+=CLI

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CMAKE_BOOL=	WITH_FLAC

MP3_LIB_DEPENDS=	libid3.so:audio/id3lib
MP3_CMAKE_BOOL=		WITH_ID3LIB

MP4_LIB_DEPENDS=	libmp4v2.so:multimedia/mp4v2
MP4_CMAKE_BOOL=		WITH_MP4V2

PHONON_USE=		QT=phonon
PHONON_CMAKE_BOOL=	WITH_PHONON

TAGLIB_DESC=		Various audio formats support via Taglib
TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CMAKE_BOOL=	WITH_TAGLIB

TEST_USE=		LOCALE=en_US.UTF-8
.if ${SLAVE} == qt4 || ${SLAVE} == kde4
TEST_USE+=		QT=qtestlib_build
.else
TEST_USE+=		QT=testlib_build
.endif
TEST_WRKSRC=		${BUILD_WRKSRC}/src/test
TEST_VARS=		KID3_APPS+=TEST

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_CMAKE_BOOL=	WITH_VORBIS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLAC} || ${PORT_OPTIONS:MVORBIS}
PLIST_SUB+=	OGGFLAC=""
.else
PLIST_SUB+=	OGGFLAC="@comment "
.endif

pre-test:
	@${CP} ${WRKSRC}/src/test/*.py ${TEST_WRKSRC}

do-test:
	-@(cd ${TEST_WRKSRC}; ${SETENV} ${TEST_ENV} ./kid3-test)

do-test-CLI-on:
	-@(cd ${TEST_WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHON_CMD} test_cli_functions.py)

.include <bsd.port.mk>
