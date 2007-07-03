# New ports collection makefile for:	gnomebasic
# Date created:				28th June 2000
# Whom:				Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomebasic
PORTVERSION=	0.0.20
PORTREVISION=	3
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gb/0.0
DISTNAME=	gb-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provide VB compatible functionality for GNOME, especially VBA

DEPRECATED=	Five years abandoned project; functionality folded into mono
EXPIRATION_DATE=2007-09-04

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gnomeprint
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700000
BROKEN=		Does not package
.endif

.include <bsd.port.post.mk>
