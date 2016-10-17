# $FreeBSD$

PORTNAME=	zeal
PORTVERSION=	0.3.1
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	devel

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Offline documentation browser

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxcb.so:x11/libxcb \
		libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		compiler:c++11-lib desktop-file-utils libarchive \
		pkgconfig qmake:outsource
USE_GL=		gl  # Dependency added by qt5-gui.
USE_GITHUB=	yes
USE_QT5=	concurrent core gui network sql webkit widgets x11extras \
		buildtools_build sql-sqlite3_run
USE_XORG=	x11 xcb

GH_ACCOUNT=	zealdocs
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
