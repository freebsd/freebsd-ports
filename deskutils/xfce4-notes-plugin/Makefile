# New ports collection makefile for:	xfce4-notes-plugin
# Date created:		06 October 2003
# Whom:			Thorsten Greiner <thorsten.greiner@web.de>
#
# $FreeBSD$
#

PORTNAME=	xfce4-notes-plugin
PORTVERSION=	1.7.2
PORTREVISION=	5
CATEGORIES=	deskutils xfce
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/${PORTNAME}/1.7/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Sticky notes panel plugin for XFce4

LIB_DEPENDS=	unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
