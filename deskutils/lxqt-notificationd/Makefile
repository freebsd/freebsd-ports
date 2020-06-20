# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-notificationd
PORTVERSION=	0.15.0
CATEGORIES=	deskutils
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt notification daemon

LICENSE=	LGPL21+

USES=	cmake compiler:c++14-lang gettext kde:5 lxqt qt:5 \
	pkgconfig tar:xz gnome
USE_QT=	buildtools_build qmake_build dbus core gui \
	linguisttools svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt
USE_GNOME=	glib20

.include <bsd.port.mk>
