# $FreeBSD$

PORTNAME=	kirigami-gallery
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kirigami component gallery application

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL-2

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm kirigami2 package
USE_QT=		core declarative gui network quickcontrols2 svg widgets \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
