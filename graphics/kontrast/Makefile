PORTNAME=	kontrast
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics accessibility kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Color contrast checker

USES=		compiler:c++11-lang cmake pkgconfig \
		kde:5 qt:5 tar:xz
USE_KDE=	coreaddons i18n kdeclarative kirigami2 \
		ecm_build
USE_QT=		core dbus declarative gui network quickcontrols2 sql svg widgets \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
