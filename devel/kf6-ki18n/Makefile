PORTNAME=	ki18n
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced internationalization framework

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes

USES=		cmake gettext gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
