# New ports collection makefile for:	gtodo
# Date created:				29 September 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gtodo
PORTVERSION=	0.14
PORTREVISION=	12
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Gtk2 Todo list manager

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget gnomevfs2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gtodo.schemas

.include <bsd.port.mk>
