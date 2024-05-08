PORTNAME=	kimageformats
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	graphics kde kde-frameworks

PATCH_SITES=	https://invent.kde.org/frameworks/kimageformats/-/commit/
PATCHFILES+=	c2c12b1d7e38728e7533f1346deca0270973d22d.patch:-p1 # Fix build w/ Qt >= 6.7.0 on 32-bit

COMMENT=	Plugins to allow QImage to support extra file formats
MAINTAINER=	kde@FreeBSD.org

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base

.include <bsd.port.mk>
