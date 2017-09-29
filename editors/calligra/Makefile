# $FreeBSD$

# TODO (when these parts are available in KF5):
#  - add calendarcore to USE_KDE when KDE PIM is available
#  - add libOkular5Core.so:graphics/okular to LIB_DEPENDS
#
PORTNAME=	calligra
PORTVERSION=	3.0.1
PORTREVISION=	5
CATEGORIES=	editors kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE office suite

LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR \
		libImath-2_2.so:graphics/ilmbase \
		libKPropertyCore3.so:x11-toolkits/kproperty \
		libKReport3.so:textproc/kreport \
		libboost_thread.so:devel/boost-libs \
		libetonyek-0.1.so:graphics/libetonyek01 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgsl.so:math/gsl \
		liblcms2.so:graphics/lcms2 \
		libKGantt.so:graphics/kdiagram \
		libodfgen-0.1.so:textproc/libodfgen01 \
		libopenjpeg.so:graphics/openjpeg15 \
		libpng.so:graphics/png \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libpoppler.so:graphics/poppler \
		libqca-qt5.so:devel/qca-qt5 \
		librevenge-0.0.so:textproc/librevenge \
		libtiff.so:graphics/tiff \
		libvisio-0.1.so:textproc/libvisio01 \
		libwpd-0.10.so:textproc/libwpd010 \
		libwpg-0.3.so:graphics/libwpg03 \
		libwps-0.3.so:textproc/libwps03

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3 \
		pstoedit:graphics/pstoedit
RUN_DEPENDS=	pstoedit:graphics/pstoedit

USES=		cmake:outsource cpe compiler:c++11-lib desktop-file-utils \
		gettext iconv:translit jpeg kde:5 localbase:ldflags perl5 pkgconfig \
		shared-mime-info sqlite tar:xz
USE_KDE=	activities archive auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons doctools ecm \
		emoticons guiaddons i18n iconthemes init itemmodels itemviews \
		jobwidgets js kcmutils kdelibs4support khtml kio \
		kross notifications notifyconfig parts service solid sonnet \
		texteditor textwidgets threadweaver unitconversion wallet \
		widgetsaddons windowsystem xmlgui
USE_QT5=	buildtools_build core dbus gui network opengl \
		phonon4 printsupport qmake_build qml \
		quick script sql svg testlib webkit widgets x11extras xml
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH:STRING="${QT_INCDIR} ${LOCALBASE}/include" \
		-DPRODUCTSET:STRING="DESKTOP"

# Requested by upstream, to not include unfinished modules
CMAKE_ARGS+=	-DRELEASE_BUILD:BOOL=TRUE
# Performance increase according to README.PACKAGERS
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS="-DKDE_NO_DEBUG_OUTPUT"

# Disable KDE Pim support
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_KF5Akonadi:BOOL=FALSE \
		-DCMAKE_DISABLE_FIND_PACKAGE_KF5AkonadiContact:BOOL=FALSE

PLIST_SUB+=	SHLIB_VER=15.0.0

.include <bsd.port.mk>
