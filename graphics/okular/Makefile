PORTNAME=	okular
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE universal document viewer
WWW=		https://okular.kde.org

LICENSE=	GPLv2

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lib gettext jpeg kde:5 cpe pkgconfig qca \
		qt:5 tar:xz xorg
USE_KDE=	activities archive auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons emoticons i18n \
		iconthemes init itemmodels itemviews jobwidgets \
		kio parts pty \
		service solid sonnet textwidgets threadweaver wallet \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network phonon4 printsupport \
		svg widgets \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

OPTIONS_DEFINE=		CHM DJVU DOCS EPUB MARKDOWN MOBIPOCKET PURPOSE SPECTRE
OPTIONS_DEFAULT=	CHM DJVU EPUB MARKDOWN MOBIPOCKET PURPOSE SPECTRE
OPTIONS_SUB=		yes
OPTIONS_EXCLUDE_purecap=CHM DJVU DOCS EPUB MARKDOWN MOBIPOCKET PURPOSE SPECTRE

CHM_CMAKE_DESC=		CHM
CHM_LIB_DEPENDS=	libchm.so:misc/chmlib

DJVU_CMAKE_DESC=	DJVU
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre

EPUB_CMAKE_DESC=	EPUB
EPUB_LIB_DEPENDS=	libepub.so:textproc/ebook-tools

MARKDOWN_CMAKE_DESC=	MARKDOWN
MARKDOWN_BUILD_DEPENDS=	markdown:textproc/discount
MARKDOWN_RUN_DEPENDS=	markdown:textproc/discount

MOBIPOCKET_CMAKE_DESC=	MOBIPOCKET
MOBIPOCKET_LIB_DEPENDS=	libqmobipocket.so:graphics/kdegraphics-mobipocket

SPECTRE_CMAKE_DESC=	SPECTRE
SPECTRE_LIB_DEPENDS=	libspectre.so:print/libspectre

PURPOSE_DESC=	Enable 'Share' menu
PURPOSE_USE=	KDE=purpose
PURPOSE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF5Purpose

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MCHM}
NOT_REQ_DEPS+=CHM
.endif

.if !${PORT_OPTIONS:MDJVU}
NOT_REQ_DEPS+=DjVuLibre
.endif

.if !${PORT_OPTIONS:MEPUB}
NOT_REQ_DEPS+=EPub
.endif

.if !${PORT_OPTIONS:MMARKDOWN}
NOT_REQ_DEPS+=Discount
.endif

.if !${PORT_OPTIONS:MMOBIPOCKET}
NOT_REQ_DEPS+=QMobipocket
.endif

.if !${PORT_OPTIONS:MSPECTRE}
NOT_REQ_DEPS+=LibSpectre
.endif

.if ${ABI:Mpurecap}
CMAKE_ARGS+=	-DBUILD_DESKTOP=True
NOT_REQ_DEPS+=	Discount KF5DocTools KF5JS KF5KHtml KF5KExiv2 KF5Purpose \
		LibZip Qt5TextToSpeech
.else
USES+=		desktop-file-utils
LIB_DEPENDS+=	libzip.so:archivers/libzip
USE_QT+=	speech xml
USE_KDE+=	js kdelibs4support khtml libkexiv2
.endif

CMAKE_ARGS+=	-DFORCE_NOT_REQUIRED_DEPENDENCIES="${NOT_REQ_DEPS:C/ /;/gW}"

.include <bsd.port.mk>
