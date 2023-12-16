PORTNAME=	gwenview
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and browser for KDE
WWW=		http://gwenview.sourceforge.net

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml \
		wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libkImageAnnotator.so:graphics/kimageannotator
RUN_DEPENDS=	kipi-plugins>=0:graphics/kipi-plugins

USES=		compiler:c++11-lang cmake desktop-file-utils gettext jpeg pkgconfig \
		kde:5 qt:5 tar:xz xorg
USE_KDE=	activities auth baloo bookmarks codecs completion config \
		configwidgets coreaddons emoticons filemetadata guiaddons i18n \
		iconthemes init itemmodels itemviews jobwidgets \
		kdelibs4support kimageformats kio libkdcraw libkipi \
		notifications parts phonon service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network opengl printsupport \
		svg widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
