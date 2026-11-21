PORTNAME=	kirigami-gallery
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kirigami component gallery application
WWW=		https://invent.kde.org/sdk/kirigami-gallery

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL-2

USES=		cmake compiler:c++11-lang kde:6 qt:6 tar:xz
USE_KDE=	itemmodels kirigami2 \
		ecm:build
USE_QT=		base declarative svg \
		tools:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
