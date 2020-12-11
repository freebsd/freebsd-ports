# $FreeBSD$

PORTNAME=	itinerary
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Itinerary is a digital travel assistant

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	ecm coreaddons contacts i18n kpkpass notifications kosm kitinerary
USE_QT=		core location quick3d quickcontrols2 testlib \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
