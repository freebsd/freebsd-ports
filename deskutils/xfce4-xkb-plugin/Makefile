# $FreeBSD$

PORTNAME=	xfce4-xkb-plugin
PORTVERSION=	0.5.6
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Keyboard layout switching plugin for the Xfce panel

LIB_DEPENDS=	libxklavier.so:${PORTSDIR}/x11/libxklavier

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext pkgconfig gmake
USE_GNOME=	gtk20 intltool intlhack librsvg2 libwnck
USE_XFCE=	configenv libmenu libutil panel
USE_XORG=	x11

.include <bsd.port.mk>
