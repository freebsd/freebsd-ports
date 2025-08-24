PORTNAME=	digikam
DISTVERSION=	8.7.0
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION} \
		https://files.kde.org/${PORTNAME}/%SUBDIR%/:aitools,aesthetic,autotags,face,testimage,yunet \
		https://kde-applicationdata.mirrors.omnilance.com/${PORTNAME}/%SUBDIR%/:aitools,aesthetic,autotags,face,testimage,yunet \
		https://mirrors.ocf.berkeley.edu/kde-applicationdata/${PORTNAME}/%SUBDIR%/:aitools,aesthetic,autotags,face,testimage,yunet
MASTER_SITE_SUBDIR=	aestheticdetector/:aesthetic \
			aitools/:aitools \
			autotags/:autotags \
			facesengine/:testimage \
			facesengine/dnnface/:face \
			facesengine/yunet/:yunet
# One bit changed in the naming convention ..
DISTFILES=	digiKam-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}
DIST_SUBDIR=	KDE/${PORTNAME}
EXTRACT_ONLY=	digiKam-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE digital photo management application
WWW=		https://www.digikam.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libgphoto2.so:graphics/libgphoto2 \
		libjasper.so:graphics/jasper \
		libjxl.so:graphics/libjxl \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		libopencv_core.so:graphics/opencv \
		libheif.so:graphics/libheif \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libx265.so:multimedia/x265
RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool

USES=		bison cmake compiler:c++20-lang desktop-file-utils eigen:3 \
		gettext-tools gl gnome jpeg kde:6 magick pkgconfig qt:6 \
		shebangfix tar:xz xorg
USE_GL=		opengl glu
USE_GNOME=	glib20 libxml2 libxslt
USE_KDE=	calendarcore colorscheme completion config configwidgets \
		coreaddons doctools filemetadata guiaddons i18n iconthemes \
		jobwidgets kio libksane notifications notifyconfig service \
		solid sonnet texttemplate threadweaver widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_LDCONFIG=	yes
USE_QT=		base declarative networkauth positioning scxml svg \
		webchannel webengine \
		imageformats:run
USE_XORG=	ice sm x11 xext

SHEBANG_FILES=	core/data/scripts/digitaglinktree/digitaglinktree

CMAKE_ON=	BUILD_WITH_CCACHE \
		BUILD_WITH_QT6 \
		CMAKE_DISABLE_FIND_PACKAGE_VAAPI \
		DIGIKAMSC_COMPILE_DIGIKAM \
		ENABLE_KFILEMETADATASUPPORT

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

WITH_CCACHE_BUILD=	yes

OPTIONS_DEFINE=		KDEPIM MEDIAPLAYER
OPTIONS_GROUP=		DATA
DATA_DESC=		Binary data required for certain features
OPTIONS_GROUP_DATA=	AITOOLS AESTHETIC AUTOTAGS FACEDETECT
OPTIONS_MULTI=		DB
DB_DESC=		Database options
OPTIONS_MULTI_DB=	MYSQL MYSQL_INTERNAL SQLITE3
OPTIONS_DEFAULT=	${OPTIONS_DEFINE} \
			${OPTIONS_MULTI_DB:NMYSQL_INTERNAL}
OPTIONS_SUB=		yes

# Check core/data/dnnmodels/dnnmodels.conf for new and obsolete files
# for the AITOOLS. AESTHETIC, AUTOTAGS and FACEDETECT options with each update.
AITOOLS_DESC=		Install aitools (autorotate) data (~330 MiB)
AITOOLS_DISTFILES=	deep-image-orientation-angle-detection.onnx:aitools

AESTHETIC_DESC=		Install aesthetic detection data (~84 MiB)
AESTHETIC_DISTFILES=	weights_inceptionv3_299.pb:aesthetic

AUTOTAGS_DESC=		Install auto tags assignment data (~481 MiB)
AUTOTAGS_DISTFILES=	classification_classes_ILSVRC2012.txt:autotags \
			coco.names:autotags \
			efficientnetb7.onnx:autotags \
			yolo11n.onnx:autotags \
			yolo11x.onnx:autotags

FACEDETECT_DESC=	Install face management data (~37 MiB)
FACEDETECT_DISTFILES=	dnntestimage.jpeg:testimage \
			face_recognition_sface_2021dec.onnx:face \
			face_detection_yunet_2023mar.onnx:yunet

KDEPIM_DESC=		KDEPim Addressbook support
KDEPIM_USE=		KDE=akonadi,akonadicontacts,contacts,grantleetheme,itemmodels
KDEPIM_CMAKE_BOOL=	ENABLE_AKONADICONTACTSUPPORT

MEDIAPLAYER_DESC=		Enable media player
MEDIAPLAYER_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
MEDIAPLAYER_USE=		QT=multimedia XORG=xv
MEDIAPLAYER_CMAKE_BOOL=		ENABLE_MEDIAPLAYER
MEDIAPLAYER_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_FFmpeg

MYSQL_USE=		QT=sqldriver-mysql:run
MYSQL_CMAKE_BOOL=	ENABLE_MYSQLSUPPORT

MYSQL_INTERNAL_DESC=		Use a dedicated MySQL instance (requires MariaDB)
MYSQL_INTERNAL_USES=		mysql:server
MYSQL_INTERNAL_CMAKE_BOOL=	ENABLE_INTERNALMYSQL
# Only works with MariaDB. Try to keep this in sync with supported MySQL
# versions and add any version not ending with 'm' to the IGNORE list.
MYSQL_INTERNAL_VARS=		IGNORE_WITH_MYSQL="80 81"
MYSQL_INTERNAL_IMPLIES=		MYSQL

SQLITE3_USE=		QT=sqldriver-sqlite:run

post-install-AITOOLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/facesengine
.for f in ${AITOOLS_DISTFILES:C/:.*//}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${STAGEDIR}${DATADIR}/facesengine
.endfor

post-install-AESTHETIC-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/facesengine
.for f in ${AESTHETIC_DISTFILES:C/:.*//}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${STAGEDIR}${DATADIR}/facesengine
.endfor

post-install-AUTOTAGS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/facesengine
.for f in ${AUTOTAGS_DISTFILES:C/:.*//}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${STAGEDIR}${DATADIR}/facesengine
.endfor

post-install-FACEDETECT-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/facesengine
.for f in ${FACEDETECT_DISTFILES:C/:.*//}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${STAGEDIR}${DATADIR}/facesengine
.endfor

.include <bsd.port.mk>
