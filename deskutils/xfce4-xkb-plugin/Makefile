# $FreeBSD$

PORTNAME=	xfce4-xkb-plugin
PORTVERSION=	0.5.4.3
PORTREVISION=	3
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Keyboard layout switching plugin for Xfce4

LIB_DEPENDS=	xklavier:${PORTSDIR}/x11/libxklavier

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack librsvg2
USE_XFCE=	configenv panel

.include <bsd.port.mk>
