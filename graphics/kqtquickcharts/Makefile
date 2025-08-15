PORTNAME=	kqtquickcharts
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QtQuick plugin to render interactive charts
WWW=		https://invent.kde.org/libraries/kqtquickcharts

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
