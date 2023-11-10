PORTNAME=	ki18n
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 advanced internationalization framework

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes

USES=		cmake compiler:c++11-lib gettext-runtime \
		gettext-tools:build,run kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	ecm:build
USE_QT=		core declarative network \
		buildtools:build qmake:build testlib:build

.include <bsd.port.mk>
