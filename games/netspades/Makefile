# New ports collection Makefile for:	NetSpades
# Date created:				23 July 2002
# Whom:					Frank Laszlo <laszlof@freebsdmatrix.net>
#
# $FreeBSD$
#

PORTNAME=	NetSpades
PORTVERSION=	4.2.0
CATEGORIES=	games
MASTER_SITES=	http://www.ece.rice.edu/~brentmh/spades/

MAINTAINER=	laszlof@freebsdmatrix.net

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -ltermcap"

MAN6=		gspades.6 slspades.6 spadesd.6

.include <bsd.port.mk>
