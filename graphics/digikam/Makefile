# $FreeBSD$

PORTNAME=	digikam
DISTVERSION=	6.2.0
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	KDE/digikam/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE digital photo management application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libKF5KGeoMap.so:astro/libkgeomap \
		libKF5Sane.so:graphics/libksane \
		libboost_graph.so:devel/boost-libs \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libgphoto2.so:graphics/libgphoto2 \
		libicalss.so:devel/libical \
		libjasper.so:graphics/jasper \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		liblqr-1.so:graphics/liblqr-1 \
		libopencv_video.so:graphics/opencv \
		libopencv_core.so:graphics/opencv-core \
		libpgf.so:graphics/libpgf \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		bison cmake compiler:c++11-lib desktop-file-utils eigen:3 gl jpeg \
		kde:5 pkgconfig qt:5 shebangfix tar:xz
USE_GL=		gl glu
USE_GNOME=	glib20 libxml2 libxslt
USE_KDE=	archive auth bookmarks calendarcore codecs completion config \
		configwidgets coreaddons crash doctools ecm filemetadata \
		guiaddons i18n iconthemes itemmodels itemviews jobwidgets kdelibs4support \
		kio marble libkipi notifications notifyconfig parts service \
		solid sonnet textwidgets threadweaver unitconversion \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network opengl printsupport sql \
		widgets x11extras xml xmlpatterns \
		sql-sqlite3_run \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xext

USE_LDCONFIG=	yes
SHEBANG_FILES=	core/data/scripts/digitaglinktree/digitaglinktree

# Disable kipiplugins, as they are built in their own port: graphics/kipiplugins.
# Remember to keep that port in sync with this one.
CMAKE_ON=	DIGIKAMSC_COMPILE_DIGIKAM

OPTIONS_DEFINE=		DOCS DOXYGEN KDEPIM KVKONTAKTE MEDIAPLAYER MYSQL NLS WEBENGINE
OPTIONS_DEFAULT=	${OPTIONS_DEFINE:NWEBENGINE}
OPTIONS_SUB=		yes

DOCS_DESC=		Digikam documentation
DOCS_CMAKE_BOOL=	DIGIKAMSC_COMPILE_DOC
DOCS_USES=		gettext
DOCS_USE=		KDE=doctools

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_IMPLIES=	DOCS

KDEPIM_DESC=		KDEPim Addressbook support
KDEPIM_USE=		KDE=akonadi,akonadicontacts,contacts
KDEPIM_CMAKE_BOOL=	ENABLE_AKONADICONTACTSUPPORT
KDEPIM_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF5AkonadiContact

MEDIAPLAYER_DESC=	Enable mediaplayer
MEDIAPLAYER_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
				libQtAV.so:multimedia/QtAV
MEDIAPLAYER_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_FFmpeg \
				CMAKE_DISABLE_FIND_PACKAGE_QtAV

MYSQL_USE=		MYSQL=server QT=sql-mysql_run
MYSQL_CMAKE_BOOL=	ENABLE_INTERNALMYSQL \
			ENABLE_MYSQLSUPPORT
MYSQL_CMAKE_ON=		-DMYSQLD_PATH:PATH=${LOCALBASE}/libexec \
			-DMYSQL_TOOLS_PATH:PATH=${LOCALBASE}/bin
MYSQL_BUILD_DEPENDS=	${LOCALBASE}/lib/mysql/libmysqld.a:${_MYSQL_SERVER}

KVKONTAKTE_DESC=	vk.com Plugin
KVKONTAKTE_LIB_DEPENDS=	libKF5Vkontakte.so:net/libkvkontakte
KVKONTAKTE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF5Vkontakte

NLS_DESC=		Digikam i18n translations
NLS_CMAKE_BOOL=		DIGIKAMSC_COMPILE_PO
NLS_USES=		gettext
NLS_USE=		KDE=i18n

WEBENGINE_DESC=		Use Qt WebEngine instead of WebKit
WEBENGINE_USE=		QT=webengine
WEBENGINE_USE_OFF=	QT=webkit
WEBENGINE_CMAKE_BOOL=	ENABLE_QWEBENGINE

PLIST_SUB=		SHLIB_VER=${DISTVERSION}

post-extract:
# Remove localization file already installed by net/libkvkontakte.
	${RM} ${WRKSRC}/po/*/libkvkontakte.po

.include <bsd.port.mk>
