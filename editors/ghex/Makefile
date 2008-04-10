# New ports collection makefile for:	ghex2
# Date created:				15 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/ghex/Makefile,v 1.11 2008/02/27 04:39:06 mezz Exp $
#

PORTNAME=	ghex
PORTVERSION=	2.22.0
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 hex editor

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gail libgnomeprintui libgnomeui \
		gnomedocutils
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	ghex2.schemas

.include <bsd.port.mk>
