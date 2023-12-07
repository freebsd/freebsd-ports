PORTNAME=	okular
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications kde-devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE universal document viewer
WWW=		https://okular.kde.org

LICENSE=	GPLv2

BUILD_DEPENDS=	markdown:textproc/discount
RUN_DEPENDS=	markdown:textproc/discount
LIB_DEPENDS=	libchm.so:misc/chmlib \
		libdjvulibre.so:graphics/djvulibre \
		libepub.so:textproc/ebook-tools \
		libfreetype.so:print/freetype2 \
		libqmobipocket.so:graphics/kdegraphics-mobipocket \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libspectre.so:print/libspectre \
		libtiff.so:graphics/tiff \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++11-lib desktop-file-utils \
		gettext jpeg kde:5 cpe pkgconfig qca qt:5 tar:xz xorg
USE_KDE=	activities archive auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons emoticons i18n \
		iconthemes init itemmodels itemviews jobwidgets js \
		kdelibs4support khtml kio libkexiv2 parts phonon pty \
		service solid sonnet textwidgets threadweaver wallet \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network printsupport speech \
		svg widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS PURPOSE
OPTIONS_DEFAULT=	PURPOSE

PURPOSE_DESC=	Enable 'Share' menu
PURPOSE_USE=	KDE=purpose
PURPOSE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF5Purpose

.include <bsd.port.mk>
