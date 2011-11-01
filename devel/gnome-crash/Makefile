# New ports collection makefile for:	gnomecrash
# Date created:				3rd November 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-crash
PORTVERSION=	0.0.5
PORTREVISION=	10
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small coredump analysis tool for GNOME

DEPRECATED=	No more supported upstream, not depend on anymore.
EXPIRATION_DATE=	2011-11-30

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libglade gnomeprint
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
