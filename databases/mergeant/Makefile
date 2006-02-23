# New ports collection makefile for:	mergeant
# Date created:				14 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/mergeant/Makefile,v 1.15 2005/08/07 21:55:46 marcus Exp $
#

PORTNAME=	mergeant
PORTVERSION=	0.62
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provide uniform access to data sources for the GNOME 2 environment

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomedb libgnomeprintui
USE_PERL5=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
