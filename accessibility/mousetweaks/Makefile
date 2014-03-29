# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/accessibility/mousetweaks/Makefile,v 1.53 2010/11/15 21:25:36 kwm Exp $

PORTNAME=	mousetweaks
PORTVERSION=	2.32.1
PORTREVISION=	1
CATEGORIES=	accessibility
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mouse accessibility enhancements for the GNOME desktop

USE_XORG=	x11 xfixes xcursor xtst
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnomepanel intlhack
USES=		gmake gettext pkgconfig
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	mousetweaks.schemas pointer-capture-applet.schemas

.include <bsd.port.mk>
