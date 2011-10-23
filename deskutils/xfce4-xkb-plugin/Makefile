# New ports collection makefile for:	xfce4-xkb-plugin
# Date created:				2004-08-27
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	xfce4-xkb-plugin
PORTVERSION=	0.5.4.1
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Keyboard layout switching plugin for XFce4

LIB_DEPENDS=	xklavier.12:${PORTSDIR}/x11/libxklavier

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack pkgconfig librsvg2
USE_XFCE=	configenv panel

.include <bsd.port.mk>
