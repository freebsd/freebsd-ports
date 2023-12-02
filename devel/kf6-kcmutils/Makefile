PORTNAME=	kcmutils
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

COMMENT=	Utilities for KDE System Settings modules
MAINTAINER=	kde@FreeBSD.org

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	colorscheme config configwidgets coreaddons guiaddons i18n \
		itemviews kio service widgetsaddons xmlgui \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
