# Created by: Olivier Duchateau

PORTNAME=	lxqt-notificationd
PORTVERSION=	1.0.0
CATEGORIES=	deskutils
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt notification daemon

LICENSE=	LGPL21+

USES=	cmake compiler:c++14-lang gettext kde:5 lxqt qt:5 \
	pkgconfig tar:xz gnome xorg
USE_QT=	buildtools_build qmake_build dbus core gui \
	linguisttools svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt
USE_GNOME=	glib20
USE_XORG=	x11

.include <bsd.port.mk>
