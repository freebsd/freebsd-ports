# New ports collection makefile for:	gpdf
# Date created:		12 April 2002
# Whom:			Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gpdf
PORTVERSION=	0.112.1
CATEGORIES=	graphics print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.112
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME version of xpdf

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui libgnomeprintui
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
