# New ports collection makefile for:	mpc plugin for xfce4
# Date created:				12 July 2006
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-mpc-plugin
PORTVERSION=	0.3.3
PORTREVISION=	5
CATEGORIES=	audio xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A mpc plugin for xfce

LIB_DEPENDS=	mpd.1:${PORTSDIR}/audio/libmpd

USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel

.include <bsd.port.mk>
