PORTNAME=	kparts
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugin framework for user interface components

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	config coreaddons i18n jobwidgets kio service \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		base \
		declarative:build
USE_XORG=	x11

.include <bsd.port.mk>
