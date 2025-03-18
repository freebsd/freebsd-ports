PORTNAME=	ki18n
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

COMMENT=	Advanced internationalization framework
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
