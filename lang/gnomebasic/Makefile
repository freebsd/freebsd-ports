# New ports collection makefile for:	gnomebasic
# Date created:				28th June 2000
# Whom:				Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomebasic
PORTVERSION=	0.0.20
PORTREVISION=	2
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gb/0.0
DISTNAME=	gb-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provide VB compatible functionality for GNOME, especially VBA

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gnomeprint
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
