# New ports collection makefile for:	xfce4-mixer
# Date created:		3 July 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-mixer
PORTVERSION=	4.4.0
PORTREVISION=	1
CATEGORIES=	audio xfce
MASTER_SITES=	${MASTER_SITES_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 volume mixer module for xfce4-panel

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack libxml2 pkgconfig
USE_XFCE=	configenv libgui libmcs libutil mcsmanager panel
USE_XLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

.include <bsd.port.mk>
