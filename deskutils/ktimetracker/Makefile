PORTNAME=	ktimetracker
DISTVERSION=	5.0.1
PORTREVISION=	3
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Todo management and time tracker
WWW=		https://userbase.kde.org/KTimeTracker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	kio sonnet auth calendarcore codecs config configwidgets \
		coreaddons dbusaddons i18n idletime jobwidgets \
		notifications service textwidgets widgetsaddons \
		windowsystem xmlgui \
		doctools:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
