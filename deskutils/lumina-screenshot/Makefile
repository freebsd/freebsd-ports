PORTNAME=	lumina-screenshot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Screenshot utility from the Lumina Desktop
WWW=		https://github.com/lumina-desktop/lumina/tree/master/src-qt5/desktop-utils/lumina-screenshot

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../../LICENSE

LIB_DEPENDS=	libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util

USES=		compiler:c++11-lang gl qmake qt:5 xorg
USE_QT=		buildtools:build concurrent core gui \
		multimedia network svg x11extras widgets
USE_XORG=	xcb xdamage
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_PROJECT=	lumina

QMAKE_ARGS=	L_MANDIR=${PREFIX}/share/man

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USE=	QT=linguist:build
NLS_QMAKE_ON=	CONFIG+=WITH_I18N

CONFLICTS_INSTALL=	lumina-1.2.*

WRKSRC_SUBDIR=	src-qt5/desktop-utils/${PORTNAME}

.include <bsd.port.mk>
