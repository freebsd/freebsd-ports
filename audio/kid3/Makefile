PORTNAME=	kid3
PORTVERSION=	3.9.7
CATEGORIES=	audio kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Audio file tag editor
WWW=		https://kid3.kde.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl
LIB_DEPENDS=	libtag.so:audio/taglib

FLAVORS=	qt6 kf6
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake compiler:c++17-lang desktop-file-utils gl gnome \
		pkgconfig qt:6 tar:xz
USE_GL=		opengl
USE_GNOME=	libxslt:build
USE_LDCONFIG=	yes
USE_QT=		base multimedia tools:build

CMAKE_ARGS=	-DWITH_DOCBOOKDIR="${LOCALBASE}/share/xsl/docbook" \
		-DWITH_LIBDIR=lib \
		-DWITH_MANDIR=share/man \
		-DWITH_PLUGINSDIR=lib/kid3 \
		-DFFMPEG_ROOT="${LOCALBASE}" \
		-DWITH_APPS="${_KID3_APPS:S/ /;/gW}"
CMAKE_OFF=	WITH_ID3LIB \
		WITH_MP4V2 \
		WITH_QML
CMAKE_ON=	BUILD_WITH_QT6 \
		WITH_TAGLIB
PLIST_SUB+=	SHLIB_VER=${PORTVERSION}

.if ${FLAVOR} == qt6
PLIST_SUB+=	KF="@comment " \
		QT="" \
		QT_SUFX="-qt"
_KID3_APPS+=	QT
.elif ${FLAVOR} == kf6
USES+=		kde:6
USE_KDE=	colorscheme config configwidgets coreaddons guiaddons kio \
		widgetsaddons xmlgui doctools:build ecm:build
PLIST_SUB+=	KF="" \
		QT="@comment " \
		QT_SUFX=""
_KID3_APPS+=	KDE
.endif

.for f in ${FLAVORS}
.  if ${FLAVOR} != ${f}
CONFLICTS_INSTALL+=	kid3-${f}
.  endif
.endfor

OPTIONS_DEFINE=		CLI ACOUSTID FLAC VORBIS TEST
OPTIONS_DEFAULT=	CLI ACOUSTID FLAC VORBIS
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes

ACOUSTID_LIB_DEPENDS=	libchromaprint.so:audio/chromaprint \
			libavcodec.so:multimedia/ffmpeg
ACOUSTID_CMAKE_BOOL=	WITH_CHROMAPRINT WITH_FFMPEG

CLI_DESC=		Build and install command line utility
CLI_USES=		python:test readline
CLI_VARS=		_KID3_APPS+=CLI

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CMAKE_BOOL=	WITH_FLAC
FLAC_IMPLIES=		VORBIS

TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TARGET=		# define to override CMAKE_ARGS from Uses/kde.mk
TEST_WRKSRC=		${BUILD_WRKSRC}/src/test
TEST_VARS=		_KID3_APPS+=TEST

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_CMAKE_BOOL=	WITH_VORBIS

.include <bsd.port.options.mk>

pre-test:
	@${CP} ${WRKSRC}/src/test/*.py ${TEST_WRKSRC}

do-test:
	-@(cd ${TEST_WRKSRC}; ${SETENVI} ${WRK_ENV} ${TEST_ENV} ./kid3-test)

do-test-CLI-on:
	-@(cd ${TEST_WRKSRC}; ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} test_cli_functions.py)

.include <bsd.port.mk>
