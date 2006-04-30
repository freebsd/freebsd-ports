# New ports collection makefile for:	bugbuddy2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/bugbuddy/Makefile,v 1.29 2006/04/13 07:52:31 bland Exp $
#

PORTNAME=	bugbuddy
PORTVERSION=	2.14.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/bug-buddy/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	bug-buddy-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A bug reporting tool for GNOME 2

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop gnomemenus \
		desktopfileutils gnomedocutils
GNOME_DESKTOP_VERSION=2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		bug-buddy.1
GCONF_SCHEMAS=	bug-buddy.schemas

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
