# New ports collection makefile for:	xfce4-xkb-plugin
# Date created:				2004-08-27
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	xfce4-xkb-plugin
PORTVERSION=	0.4.3
PORTREVISION=	13
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	des@FreeBSD.org
COMMENT=	Keyboard layout switching plugin for XFce4

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel

.include <bsd.port.mk>
