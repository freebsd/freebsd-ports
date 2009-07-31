# New ports collection makefile for:	gnomeattacks
# Date created:				01 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeattacks
PORTVERSION=	0.3
PORTREVISION=	10
CATEGORIES=	games gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME 2 game featuring a bizarre flying GNOME logo

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomevfs2 libgnomeui
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
