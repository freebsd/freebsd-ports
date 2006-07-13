# New ports collection makefile for:	gnomemag
# Date created:			12 April 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/accessibility/gnomemag/Makefile,v 1.1 2006/03/13 23:49:23 mezz Exp $
#

PORTNAME=	gnome-mag
PORTVERSION=	0.12.6
CATEGORIES=	accessibility gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen magnifier

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix atspi libbonobo intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

DOCSDIR=	${PREFIX}/share/doc/gnome-mag-${PORTVERSION}

.include <bsd.port.mk>
