PORTNAME=	plasma5support
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	devel kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Support components for porting from KF5/Qt5 to KF6/Qt6

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	colorscheme completion config configwidgets coreaddons i18n \
		jobwidgets kio package service solid widgetsaddons xmlgui \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
