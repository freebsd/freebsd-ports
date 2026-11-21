PORTNAME=	knotifyconfig
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Configuration system for KNotify

LIB_DEPENDS=	libcanberra.so:audio/libcanberra

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	completion config i18n kio \
		ecm:build
USE_QT=		base \
		declarative:build
USE_XORG=	x11

.include <bsd.port.mk>
