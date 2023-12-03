PORTNAME=	calligra
DISTVERSION=	3.2.1
PORTREVISION=	59
CATEGORIES=	editors kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTNAME}

PATCH_SITES=	https://invent.kde.org/office/calligra/-/commit/
# Poppler 22.03
PATCHFILES=	236bacbe13739414e919de868283b0caf2df5d8a.diff:-p1 \
		6b75bec784c9835c78993349845d8c2ef22ec3de.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE office suite
WWW=		https://calligra.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pstoedit:graphics/pstoedit
LIB_DEPENDS=	libImath.so:math/Imath \
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
		libpng.so:graphics/png \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libpoppler.so:graphics/poppler \
		librevenge-0.0.so:textproc/librevenge \
		libtiff.so:graphics/tiff \
		libvisio-0.1.so:textproc/libvisio01 \
		libwpd-0.10.so:textproc/libwpd010 \
		libwpg-0.3.so:graphics/libwpg03 \
		libwps-0.4.so:textproc/libwps
RUN_DEPENDS=	pstoedit:graphics/pstoedit

USES=		cmake compiler:c++17-lang cpe desktop-file-utils eigen:3 \
		gettext iconv:translit jpeg kde:5 localbase:ldflags perl5 \
		pkgconfig qca qt:5 shared-mime-info sqlite tar:xz xorg
USE_LDCONFIG=	yes
USE_KDE=	activities akonadicontacts archive auth bookmarks calendarcore \
		codecs completion config configwidgets contacts coreaddons \
		crash dbusaddons doctools emoticons guiaddons holidays i18n \
		iconthemes init itemmodels itemviews jobwidgets js kcmutils \
		kdelibs4support khtml kio kross notifications notifyconfig \
		okular parts phonon service solid sonnet texteditor textwidgets \
		threadweaver unitconversion wallet widgetsaddons windowsystem \
		xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network opengl \
		printsupport script sql svg testlib widgets x11extras \
		xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext

OPTIONS_DEFINE=	OPENEXR WEBKIT
OPTIONS_DEFAULT=	OPENEXR

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR
WEBKIT_DESC=		Use obsolete qt5-webkit to build Browser Plugin
WEBKIT_USE=		QT=webkit
WEBKIT_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebKit

CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH:STRING="${QT_INCDIR} ${LOCALBASE}/include" \
		-DPRODUCTSET:STRING="DESKTOP"

# Requested by upstream, to not include unfinished modules
CMAKE_ON=	RELEASE_BUILD
# Performance increase according to README.PACKAGERS
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS="-DKDE_NO_DEBUG_OUTPUT"

PLIST_SUB+=	SHLIB_VER=17.0.0

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 160
	@${REINPLACE_CMD} -e 's|std::binary_function|std::__binary_function|g' \
		${WRKSRC}/filters/words/msword-odf/wv2/src/word97_helper.cpp
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/filters/words/msword-odf/wv2/src/utilities.h
.endif

.include <bsd.port.post.mk>
