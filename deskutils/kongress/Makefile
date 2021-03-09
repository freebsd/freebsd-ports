# $FreeBSD$

PORTNAME=	kongress
DISTVERSION=	1.0.1
CATEGORIES=	deskutils
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Conference companion application

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

USES=		cmake compiler:c++17-lang gl kde:5 pkgconfig qt:5 tar:xz
USE_GL=		gl
USE_QT=		core dbus declarative gui \
		network quickcontrols quickcontrols2 \
		svg widgets \
		buildtools_build linguist_build qmake_build
USE_KDE=	calendarcore config coreaddons dbusaddons i18n kirigami2 notifications service \
		ecm_build

CMAKE_ON=	REMINDERS_ENABLED
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
