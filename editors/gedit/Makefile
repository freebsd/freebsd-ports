# New ports collection makefile for:	gedit2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/gedit/Makefile,v 1.12 2005/10/03 15:49:09 ahze Exp $
#

PORTNAME=	gedit
PORTVERSION=	2.12.1
PORTREVISION=	1
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.12
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small but powerful text editor for Gnome 2 Desktop Environment

LIB_DEPENDS=	pspell.16:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack \
		libgnomeprintui libgnomeui eel2 gtksourceview desktopfileutils
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	VERSION="2.12"

MAN1=		gedit.1
GCONF_SCHEMAS=	gedit.schemas

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
