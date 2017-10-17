# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	liblxqt
PORTVERSION=	0.11.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	LXQT

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Shared library for LXQt applications

LICENSE=	LGPL21+

USES=	cmake:outsource compiler:c++11-lib gettext kde:5 lxqt \
	pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build dbus core gui linguisttools \
	svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools qtxdg
USE_XORG=	x11 xscrnsaver

.include <bsd.port.mk>
