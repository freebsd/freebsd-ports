PORTNAME=	itinerary
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Digital travel assistant for KDE

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 qt:5 tar:xz
USE_KDE=	calendarcore coreaddons contacts crash dbusaddons i18n mime \
		kpkpass notifications kosm kitinerary kpublictransport qqc2-desktop-style \
		ecm_build
USE_QT=		core dbus declarative gui location network quick3d quickcontrols2 \
		testlib widgets \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
