PORTNAME=	calligra
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	editors kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE office suite
WWW=		https://calligra.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

IGNORE_i386=	is not supported on 32-bit systems

LIB_DEPENDS=	libImath.so:math/Imath \
		libboost_thread.so:devel/boost-libs \
		libgit2.so:devel/libgit2 \
		libetonyek-0.1.so:graphics/libetonyek01 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgsl.so:math/gsl \
		liblcms2.so:graphics/lcms2 \
		libKChart6.so:graphics/kdiagram-qt6 \
		libOkular6Core.so:graphics/okular \
		libodfgen-0.1.so:textproc/libodfgen01 \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libpoppler.so:graphics/poppler \
		libqca-qt6.so:devel/qca@qt6 \
		libqt6keychain.so:security/qtkeychain@qt6 \
		librevenge-0.0.so:textproc/librevenge \
		libvisio-0.1.so:textproc/libvisio01 \
		libwpd-0.10.so:textproc/libwpd010 \
		libwpg-0.3.so:graphics/libwpg03 \
		libwps-0.4.so:textproc/libwps
RUN_DEPENDS=	pstoedit:graphics/pstoedit

USES=		cmake compiler:c++17-lang cpe desktop-file-utils eigen:3 \
		gettext gl iconv:translit jpeg kde:6 localbase:ldflags perl5 \
		pkgconfig qt:6 shared-mime-info ssl tar:xz xorg
USE_GL=		gl opengl
USE_LDCONFIG=	yes
USE_KDE=	archive bookmarks colorscheme completion config configwidgets \
		coreaddons crash dbusaddons guiaddons i18n iconthemes \
		itemviews jobwidgets kcmutils kio notifications notifyconfig \
		phonon service solid sonnet textwidgets widgetsaddons \
		windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		base declarative positioning svg webchannel webengine \
		tools:build
USE_XORG=	ice sm x11 xext

CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH:STRING="${QT_INCDIR} ${LOCALBASE}/include" \
		-DPRODUCTSET:STRING="DESKTOP"

# Requested by upstream, to not include unfinished modules
CMAKE_ON=	RELEASE_BUILD
# Performance increase according to README.PACKAGERS
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS="-DKDE_NO_DEBUG_OUTPUT"

PLIST_SUB=	SHLIB_VER=40

.include <bsd.port.mk>
