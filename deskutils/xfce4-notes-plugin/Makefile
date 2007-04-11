# New ports collection makefile for:	xfce4-notes-plugin
# Date created:		06 October 2003
# Whom:			Thorsten Greiner <thorsten.greiner@web.de>
#
# $FreeBSD$
#

PORTNAME=	xfce4-notes-plugin
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Sticky notes panel plugin for XFce4

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel
USE_XLIB=	yes

.include <bsd.port.mk>
