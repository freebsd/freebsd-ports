# $FreeBSD$

PORTNAME=	ktimetracker
DISTVERSION=	5.0.1
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Todo management and time tracker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	kio sonnet auth calendarcore codecs config configwidgets \
		coreaddons dbusaddons i18n idletime jobwidgets \
		notifications service textwidgets widgetsaddons \
		windowsystem xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
