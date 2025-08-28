PORTNAME=	liblxqt
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Shared library for LXQt applications
WWW=		https://github.com/lxqt/liblxqt

LICENSE=	LGPL21+

LIB_DEPENDS=	libpolkit-qt6-core-1.so:sysutils/polkit-qt-1@qt6

USES=		cmake compiler:c++20-lang gnome kde:6 lxqt:2 \
		pkgconfig qt:6 tar:xz xorg
USE_GNOME=	glib20
USE_QT=		base:run tools:build svg
USE_KDE=	windowsystem
USE_XORG=	x11 xscrnsaver
USE_LDCONFIG=	yes
USE_LXQT=	buildtools2 qt6xdg

.include <bsd.port.mk>
