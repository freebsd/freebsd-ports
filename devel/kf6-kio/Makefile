PORTNAME=	kio
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

COMMENT=	Network transparent access to files and data
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake desktop-file-utils gettext gl gnome kde:6 qt:6 ssl \
		tar:xz xorg
USE_GL=		gl opengl
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive auth bookmarks colorscheme completion config \
		configwidgets coreaddons crash dbusaddons doctools guiaddons \
		i18n iconthemes itemviews jobwidgets notifications service \
		solid wallet widgetsaddons windowsystem \
		ecm:build
USE_QT=		5compat base
USE_XORG=	x11

.include <bsd.port.mk>
