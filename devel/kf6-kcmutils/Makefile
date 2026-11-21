PORTNAME=	kcmutils
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Utilities for KDE System Settings modules

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	config configwidgets coreaddons guiaddons i18n itemviews \
		kio kirigami2 widgetsaddons xmlgui \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11

.include <bsd.port.mk>
