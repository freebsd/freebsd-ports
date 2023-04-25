PORTNAME=	kronometer
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Stopwatch application
WWW=		https://userbase.kde.org/Kronometer

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons crash i18n \
		widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		core dbus gui widgets xml \
		buildtools:build qmake:build testlib:build

.include <bsd.port.mk>
