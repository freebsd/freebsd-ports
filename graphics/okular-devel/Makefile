PORTNAME=	okular
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	3
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
		libKExiv2Qt6.so:graphics/libkexiv2-devel \
		libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libspectre.so:print/libspectre \
		libtiff.so:graphics/tiff \
		libzip.so:archivers/libzip \
		libxkbcommon.so:x11/libxkbcommon
#		libQMobipocket6.so:graphics/kdegraphics-mobipocket@qt6 \

USES=		cmake compiler:c++11-lib cpe desktop-file-utils \
		gettext gl jpeg \
		kde:6 pkgconfig qca qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	activities archive auth bookmarks codecs colorscheme \
		completion config configwidgets coreaddons crash i18n \
		iconthemes itemmodels itemviews jobwidgets kio parts \
		phonon pty service solid sonnet textwidgets threadweaver \
		wallet widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base declarative multimedia speech svg
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS PURPOSE
OPTIONS_DEFAULT=	PURPOSE

PURPOSE_DESC=	Enable 'Share' menu
PURPOSE_USE=	KDE=purpose
PURPOSE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF6Purpose

.include <bsd.port.mk>
