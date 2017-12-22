# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina-calculator
PORTVERSION=	1.4.1
CATEGORIES=	deskutils

MAINTAINER=	jt@ixsystems.com
COMMENT=	Scientific calculator from the Lumina Desktop

LICENSE=	BSD3CLAUSE

LIB_DEPENDS+=	libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util

CONFLICTS_INSTALL=	lumina-1.2.*

OPTIONS_DEFINE=	I18N
OPTIONS_DEFAULT=	I18N
I18N_DESC=	Install localization files

.include <bsd.port.options.mk>

MAKE_JOBS_UNSAFE=yes

USES=		qmake
USE_GL=		gl
USE_XORG=	x11 xdamage xcb
USE_QT5=	core gui widgets network svg \
		buildtools_build x11extras concurrent multimedia
USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	lumina
GH_TAGNAME=	b6536c1547571ae8dd0618bed752e2e0025bf2a7
WRKSRC_SUBDIR=	src-qt5/desktop-utils/${PORTNAME}

.if${PORT_OPTIONS:MI18N}
USE_QT5+=	linguist_build
QMAKE_ARGS+=CONFIG+=WITH_I18N
.endif

.include <bsd.port.mk>
