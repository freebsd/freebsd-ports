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
		libkImageAnnotator-Qt6.so:graphics/kimageannotator@qt6 \
		libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++11-lang desktop-file-utils gettext jpeg \
		kde:6 pkgconfig qt:6 tar:xz xorg
USE_KDE=	activities auth baloo bookmarks codecs completion config \
		configwidgets coreaddons filemetadata guiaddons i18n \
		iconthemes itemmodels itemviews jobwidgets \
		kimageformats kio libkdcraw notifications parts phonon \
		purpose service solid sonnet textwidgets widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		base imageformats:run
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
