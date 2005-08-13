# New ports collection makefile for:	gpdf
# Date created:		12 April 2002
# Whom:			Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gpdf
PORTVERSION=	2.10.0
PORTREVISION=	2
CATEGORIES=	graphics print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME version of xpdf

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libgnomeprintui \
		desktopfileutils
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gpdf.schemas

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
