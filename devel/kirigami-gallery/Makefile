PORTNAME=	kirigami-gallery
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kirigami component gallery application
WWW=		https://invent.kde.org/sdk/kirigami-gallery

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL-2

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	itemmodels kirigami2 package \
		ecm:build
USE_QT=		core declarative gui network quickcontrols2 svg widgets \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
