# New ports collection makefile for:	mpc plugin for xfce4
# Date created:				12 July 2006
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-mpc-plugin
PORTVERSION=	0.3.5
CATEGORIES=	audio xfce
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/${PORTNAME}/0.3/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A mpc plugin for xfce

LIB_DEPENDS=	mpd.2:${PORTSDIR}/audio/libmpd

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel

.include <bsd.port.mk>
