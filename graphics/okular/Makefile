PORTNAME=	okular
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde kde-applications

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
		libQMobipocket6.so:graphics/kdegraphics-mobipocket \
		libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libqca-qt6.so:devel/qca@qt6 \
		libspectre.so:print/libspectre \
		libtiff.so:graphics/tiff \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++11-lib cpe desktop-file-utils gettext jpeg \
		kde:6 pkgconfig qt:6 tar:xz xorg
USE_KDE=	activities archive auth bookmarks codecs completion config \
		iconthemes itemmodels itemviews jobwidgets kio libkexiv2 parts \
		phonon pty service solid sonnet textwidgets threadweaver \
		wallet widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS PURPOSE
OPTIONS_DEFAULT=	PURPOSE

PURPOSE_DESC=	Enable 'Share' menu
PURPOSE_USE=	KDE=purpose
PURPOSE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF6Purpose

.include <bsd.port.mk>
