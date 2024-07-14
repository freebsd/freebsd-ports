PORTNAME=	digikam
DISTVERSION=	8.4.0
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION} \
		https://files.kde.org/digikam/%SUBDIR%/:aesthetic,autotags,face,shape \
		https://kde-applicationdata.mirrors.omnilance.com/digikam/%SUBDIR%/:aesthetic,autotags,face,shape \
		https://mirrors.ocf.berkeley.edu/kde-applicationdata/digikam/%SUBDIR%/:aesthetic,autotags,face,shape
MASTER_SITE_SUBDIR=	aestheticdetector/:aesthetic \
			autotags/:autotags \
			facesengine/dnnface/:face \
			facesengine/shape-predictor/:shape
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
LIB_DEPENDS=	libKF5Sane.so:graphics/libksane \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libgphoto2.so:graphics/libgphoto2 \
		libjasper.so:graphics/jasper \
		libjxl.so:graphics/libjxl \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		libopencv_core.so:graphics/opencv \
		libheif.so:graphics/libheif \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libx265.so:multimedia/x265
RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool

USES=		bison cmake compiler:c++17-lang desktop-file-utils eigen:3 gl \
		gnome jpeg kde:5 magick pkgconfig qt:5 \
		shebangfix tar:xz xorg
USE_GL=		opengl glu
USE_GNOME=	glib20 libxml2 libxslt
USE_KDE=	auth calendarcore codecs completion config configwidgets \
		coreaddons doctools filemetadata i18n iconthemes jobwidgets \
		kio notifications notifyconfig service solid sonnet \
		threadweaver widgetsaddons windowsystem xmlgui \
		ecm:build
USE_LDCONFIG=	yes
USE_QT=		concurrent core dbus declarative gui location network \
		networkauth opengl printsupport sql svg webchannel webengine \
		widgets x11extras xml xmlpatterns \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext

SHEBANG_FILES=	core/data/scripts/digitaglinktree/digitaglinktree

CMAKE_ON=	BUILD_WITH_CCACHE DIGIKAMSC_COMPILE_DIGIKAM ENABLE_KFILEMETADATASUPPORT \
		CMAKE_DISABLE_FIND_PACKAGE_VAAPI

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

WITH_CCACHE_BUILD=	yes

OPTIONS_DEFINE=		AUTOTAGS FACEDETECT KDEPIM MEDIAPLAYER NLS
OPTIONS_MULTI=		DB
DB_DESC=		Database options
OPTIONS_MULTI_DB=	MYSQL MYSQL_INTERNAL SQLITE3
OPTIONS_DEFAULT=	${OPTIONS_DEFINE:NAUTOTAGS:NFACEDETECT} \
			${OPTIONS_MULTI_DB:NMYSQL_INTERNAL}
OPTIONS_SUB=		yes

AUTOTAGS_DESC=		Install data required for autotagging (~436 MiB)
AUTOTAGS_DISTFILES=	classification_classes_ILSVRC2012.txt:autotags \
			coco.names:autotags \
			resnet50.onnx:autotags \
			yolov5n_batch_16_s320.onnx:autotags \
			yolov5x_batch_16_s320.onnx:autotags

FACEDETECT_DESC=	Install data required for face detection (~419 MiB)
FACEDETECT_DISTFILES=	weights_inceptionv3_299.pb:aesthetic \
			deploy.prototxt:face \
			openface_nn4.small2.v1.t7:face \
			res10_300x300_ssd_iter_140000_fp16.caffemodel:face \
			yolov3-face.cfg:face \
			yolov3-wider_16000.weights:face \
			shapepredictor.dat:shape

KDEPIM_DESC=		KDEPim Addressbook support
KDEPIM_USES=		grantlee:5
KDEPIM_USE=		KDE=akonadi,akonadicontacts,contacts,grantleetheme,itemmodels
KDEPIM_CMAKE_BOOL=	ENABLE_AKONADICONTACTSUPPORT

MEDIAPLAYER_DESC=		Enable media player
MEDIAPLAYER_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
				libvdpau.so:multimedia/libvdpau
MEDIAPLAYER_USE=		QT=multimedia XORG=xv
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
NLS_USES=		gettext-tools
NLS_USE=		KDE=i18n
NLS_CMAKE_BOOL=		DIGIKAMSC_COMPILE_PO

SQLITE3_USE=		QT=sql-sqlite3:run

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
