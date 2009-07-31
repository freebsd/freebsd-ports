# New ports collection makefile for:	at-poke
# Date created:				24 Oct 2006
# Whom:					Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	at-poke
PORTVERSION=	0.2.3
PORTREVISION=	4
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Accessibility testing and poking tool

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix libglade2 libgailgnome
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
