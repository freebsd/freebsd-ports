# $FreeBSD$

PORTNAME=	xfce4-xkb-plugin
PORTVERSION=	0.5.5
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Keyboard layout switching plugin for Xfce4

LIB_DEPENDS=	xklavier:${PORTSDIR}/x11/libxklavier

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack librsvg2 libwnck
USE_XFCE=	configenv libmenu libutil panel
USE_XORG=	x11

CONFIGURE_ARGS=--disable-librsvg_2.36.2

.include <bsd.port.mk>
