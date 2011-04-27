# New ports collection makefile for:	xfce4-xkb-plugin
# Date created:				2004-08-27
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	xfce4-xkb-plugin
PORTVERSION=	0.5.3.3
CATEGORIES=	deskutils xfce
MASTER_SITES=	CRITICAL/.
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Keyboard layout switching plugin for XFce4

LIB_DEPENDS=	xklavier.12:${PORTSDIR}/x11/libxklavier

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig librsvg2
USE_XFCE=	configenv panel

.include <bsd.port.mk>
