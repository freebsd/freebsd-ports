# $FreeBSD$

PORTNAME=	calligra
DISTVERSION=	3.1.0
PORTREVISION=	7
CATEGORIES=	editors kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE office suite

LIB_DEPENDS=	libImath.so:graphics/ilmbase \
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
		libqca-qt5.so:devel/qca@qt5 \
		librevenge-0.0.so:textproc/librevenge \
		libtiff.so:graphics/tiff \
		libvisio-0.1.so:textproc/libvisio01 \
		libwpd-0.10.so:textproc/libwpd010 \
		libwpg-0.3.so:graphics/libwpg03 \
		libwps-0.3.so:textproc/libwps03

BUILD_DEPENDS=	pstoedit:graphics/pstoedit
RUN_DEPENDS=	pstoedit:graphics/pstoedit

USES=		cmake:outsource cpe compiler:c++11-lib desktop-file-utils eigen:3 \
		gettext iconv:translit jpeg kde:5 localbase:ldflags perl5 pkgconfig \
		qt:5 shared-mime-info sqlite tar:xz
USE_KDE=	activities archive auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons doctools ecm \
		emoticons guiaddons i18n iconthemes init itemmodels itemviews \
		jobwidgets js kcmutils kdelibs4support khtml kio \
		kross notifications notifyconfig parts service solid sonnet \
		texteditor textwidgets threadweaver unitconversion wallet \
		widgetsaddons windowsystem xmlgui \
		calendarcore okular
USE_QT=		buildtools_build core dbus declarative gui network opengl \
		phonon4 printsupport qmake_build \
		script sql svg testlib webkit widgets x11extras xml
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENEXR
OPTIONS_DEFAULT=	OPENEXR

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR

CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH:STRING="${QT_INCDIR} ${LOCALBASE}/include" \
		-DPRODUCTSET:STRING="DESKTOP"

# Requested by upstream, to not include unfinished modules
CMAKE_ON=	RELEASE_BUILD
# Performance increase according to README.PACKAGERS
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS="-DKDE_NO_DEBUG_OUTPUT"

PLIST_SUB+=	SHLIB_VER=16.0.0

.include <bsd.port.mk>
