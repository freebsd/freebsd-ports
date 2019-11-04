# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	liblxqt
PORTVERSION=	0.14.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Shared library for LXQt applications

LICENSE=	LGPL21+

LIB_DEPENDS=	libpolkit-qt5-core-1.so:sysutils/polkit-qt

USES=	cmake compiler:c++14-lang gettext kde:5 lxqt \
	pkgconfig qt:5 tar:xz xorg
USE_QT=	buildtools_build qmake_build dbus core gui linguisttools \
	svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools qtxdg
USE_XORG=	x11 xscrnsaver
USE_LDCONFIG=	yes

.include <bsd.port.mk>
