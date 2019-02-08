# $FreeBSD$

PORTNAME=	okular
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE universal document viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	markdown:textproc/discount
RUN_DEPENDS=	markdown:textproc/discount
LIB_DEPENDS=	libchm.so:misc/chmlib \
		libdjvulibre.so:graphics/djvulibre \
		libepub.so:textproc/ebook-tools \
		libfreetype.so:print/freetype2 \
		libqmobipocket.so:graphics/kdegraphics-mobipocket \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libqca-qt5.so:devel/qca@qt5 \
		libspectre.so:print/libspectre \
		libtiff.so:graphics/tiff \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++11-lib desktop-file-utils \
		gettext jpeg kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	activities archive auth bookmarks codecs completion config \
		configwidgets coreaddons dbusaddons ecm emoticons i18n \
		iconthemes init itemmodels itemviews jobwidgets js \
		kdelibs4support khtml kio libkexiv2 parts pty \
		service solid sonnet textwidgets threadweaver wallet \
		widgetsaddons windowsystem xmlgui
USE_QT=		core dbus declarative gui network phonon4 printsupport speech \
		svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS PURPOSE
OPTIONS_DEFAULT=	PURPOSE

PURPOSE_DESC=	Enable 'Share' menu
PURPOSE_USE=	KDE=purpose
PURPOSE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KDEExperimentalPurpose

.include <bsd.port.mk>
