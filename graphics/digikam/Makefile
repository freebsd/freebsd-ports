PORTNAME=	digikam
DISTVERSION=	8.2.0
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION} \
		https://files.kde.org/digikam/%SUBDIR%/:aesthetic,face,shape \
		https://kde-applicationdata.mirrors.omnilance.com/digikam/%SUBDIR%/:aesthetic,face,shape \
		https://mirrors.ocf.berkeley.edu/kde-applicationdata/digikam/%SUBDIR%/:aesthetic,face,shape
MASTER_SITE_SUBDIR=	aestheticdetector/:aesthetic \
			facesengine/dnnface/:face \
			facesengine/shape-predictor/:shape
# One bit changed in the naming convention ..
DISTFILES=	digiKam-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}
DIST_SUBDIR=	KDE/${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	digiKam-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE digital photo management application
WWW=		https://www.digikam.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libKF5Sane.so:graphics/libksane \
		libboost_graph.so:devel/boost-libs \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libgphoto2.so:graphics/libgphoto2 \
		libicalss.so:devel/libical \
		libjasper.so:graphics/jasper \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		liblqr-1.so:graphics/liblqr-1 \
		libopencv_core.so:graphics/opencv \
		libheif.so:graphics/libheif \
		libpgf.so:graphics/libpgf \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libx265.so:multimedia/x265

USES=		bison cmake compiler:c++17-lang desktop-file-utils eigen:3 gl \
		gnome jpeg kde:5 localbase:ldflags magick pkgconfig qt:5 \
		shebangfix tar:xz xorg
USE_GL=		gl glu
USE_GNOME=	glib20 libxml2 libxslt
USE_KDE=	archive auth bookmarks calendarcore codecs completion config \
		configwidgets coreaddons crash doctools filemetadata guiaddons \
		i18n iconthemes itemmodels itemviews jobwidgets \
		kdelibs4support kio libkipi marble notifications notifyconfig \
		parts service solid sonnet textwidgets threadweaver \
		unitconversion widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui location network \
		networkauth opengl printsupport sql webchannel widgets \
		x11extras xml xmlpatterns \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext

USE_LDCONFIG=	yes
SHEBANG_FILES=	core/data/scripts/digitaglinktree/digitaglinktree

WITH_CCACHE_BUILD=	yes

CMAKE_ON=	BUILD_WITH_CCACHE DIGIKAMSC_COMPILE_DIGIKAM ENABLE_KFILEMETADATASUPPORT \
		CMAKE_DISABLE_FIND_PACKAGE_VAAPI

OPTIONS_DEFINE=		FACEDETECT KDEPIM MEDIAPLAYER NLS WEBENGINE
OPTIONS_GROUP=		MP
MP_DESC=		Media player options
OPTIONS_GROUP_MP=	OPENAL PORTAUDIO PULSEAUDIO
OPTIONS_MULTI=		DB
DB_DESC=		Database options
OPTIONS_MULTI_DB=	MYSQL MYSQL_INTERNAL SQLITE3
OPTIONS_DEFAULT=	${OPTIONS_DEFINE:NFACEDETECT} \
			${OPTIONS_GROUP_MP:NPORTAUDIO:NPULSEAUDIO} \
			${OPTIONS_MULTI_DB:NMYSQL_INTERNAL}
OPTIONS_SUB=		yes

FACEDETECT_DESC=	Install data required for face detection (~420MB)
FACEDETECT_DISTFILES=	weights_inceptionv3_299.pb:aesthetic \
			deploy.prototxt:face \
			openface_nn4.small2.v1.t7:face \
			res10_300x300_ssd_iter_140000_fp16.caffemodel:face \
			yolov3-face.cfg:face \
			yolov3-wider_16000.weights:face \
			shapepredictor.dat:shape

KDEPIM_DESC=		KDEPim Addressbook support
KDEPIM_USE=		KDE=akonadi,akonadicontacts,contacts,grantleetheme
KDEPIM_USES=		grantlee:5
KDEPIM_CMAKE_BOOL=	ENABLE_AKONADICONTACTSUPPORT

MEDIAPLAYER_DESC=		Enable media player
MEDIAPLAYER_LIB_DEPENDS=	libass.so:multimedia/libass \
				libavcodec.so:multimedia/ffmpeg
MEDIAPLAYER_USE=		XORG=xv
MEDIAPLAYER_CMAKE_BOOL=		ENABLE_MEDIAPLAYER
MEDIAPLAYER_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_FFmpeg

MYSQL_USE=		QT=sql-mysql:run
MYSQL_CMAKE_BOOL=	ENABLE_MYSQLSUPPORT

MYSQL_INTERNAL_DESC=		Use a dedicated MySQL instance (requires MariaDB)
MYSQL_INTERNAL_USES=		mysql:server
MYSQL_INTERNAL_CMAKE_BOOL=	ENABLE_INTERNALMYSQL
# Only works with MariaDB. Try to keep this in sync with supported MySQL
# versions and add any version not ending with 'm' to the IGNORE list.
MYSQL_INTERNAL_VARS=		IGNORE_WITH_MYSQL="80 81"
MYSQL_INTERNAL_IMPLIES=		MYSQL

NLS_DESC=		Digikam i18n translations
NLS_CMAKE_BOOL=		DIGIKAMSC_COMPILE_PO
NLS_USES=		gettext
NLS_USE=		KDE=i18n

OPENAL_USES=		openal
OPENAL_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenAL
OPENAL_IMPLIES=		MEDIAPLAYER

PORTAUDIO_LIB_DEPENDS=		libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Portaudio
PORTAUDIO_IMPLIES=		MEDIAPLAYER

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_PulseAudio
PULSEAUDIO_IMPLIES=		MEDIAPLAYER

SQLITE3_USE=		QT=sql-sqlite3:run

WEBENGINE_DESC=		Use Qt WebEngine instead of WebKit
WEBENGINE_USE=		QT=webengine
WEBENGINE_USE_OFF=	QT=webkit
WEBENGINE_CMAKE_BOOL=	ENABLE_QWEBENGINE

PLIST_SUB=		SHLIB_VER=${DISTVERSION}

post-install-FACEDETECT-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/facesengine
.for f in ${FACEDETECT_DISTFILES:C/:.*//}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${STAGEDIR}${DATADIR}/facesengine
.endfor

.include <bsd.port.mk>
