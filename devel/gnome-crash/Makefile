# New ports collection makefile for:	gnomecrash
# Date created:				3rd November 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-crash
PORTVERSION=	0.0.5
PORTREVISION=	8
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small coredump analysis tool for GNOME

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libglade gnomeprint
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
