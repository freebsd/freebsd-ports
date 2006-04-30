# New ports collection makefile for:	gnomeutils2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gnomeutils2/Makefile,v 1.92 2006/04/19 04:46:41 marcus Exp $
#

PORTNAME=	gnomeutils2
PORTVERSION=	2.14.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-utils/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-utils-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 support utilities

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomepanel \
		libgnomeprintui gnomedesktop ltverhack
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-dictionary.1 gnome-search-tool.1 gnome-system-log.1
GCONF_SCHEMAS=	gnome-dictionary.schemas gnome-screenshot.schemas \
		gnome-search-tool.schemas logview.schemas

.include <bsd.port.mk>
