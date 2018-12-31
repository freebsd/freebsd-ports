# $FreeBSD$

PORTNAME=	kwrited
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	devel kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 daemon listening for wall and write messages

USES=		cmake compiler:c++11-lib cpe gettext kde:5 qt:5 tar:xz
USE_KDE=	coreaddons dbusaddons ecm i18n notifications pty
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
