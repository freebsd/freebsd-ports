# New ports collection makefile for:	nautilus-open-terminal
# Date created:		2005-07-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/nautilus-open-terminal/Makefile,v 1.12 2008/02/28 18:19:56 kwm Exp $
#

PORTNAME=	nautilus-open-terminal
PORTVERSION=	0.9
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Nautilus extension which allows you to open a terminal

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	nautilus2 gnomeprefix intlhack gnomehack
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_XLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	nautilus-open-terminal.schemas

.include <bsd.port.mk>
