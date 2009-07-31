# New ports collection makefile for:	gnomeblog
# Date created:				20 September 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gnome-blog/Makefile,v 1.5 2007/08/08 21:52:36 mezz Exp $
#

PORTNAME=	gnome-blog
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME app to post to blogs

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix pygnome2 intlhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnomeblog.schemas

.include <bsd.port.mk>
