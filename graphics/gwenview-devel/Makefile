PORTNAME=	gwenview
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications kde-devel

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
		libxkbcommon.so:x11/libxkbcommon \
		libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl jpeg \
		kde:6 pkgconfig qt:6 tar:xz xorg
USE_KDE=	activities baloo5 bookmarks colorscheme completion config \
		configwidgets coreaddons filemetadata guiaddons i18n \
		iconthemes itemmodels itemviews jobwidgets kio notifications \
		parts phonon purpose service solid wayland widgetsaddons windowsystem \
		xmlgui \
		ecm:build
USE_QT=		base svg wayland
USE_XORG=	x11
USE_GL=		gl opengl

OPTIONS_DEFINE=	DOCS

CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

.include <bsd.port.mk>
