# New ports collection Makefile for:	NetSpades
# Date created:				23 July 2002
# Whom:					Frank Laszlo <laszlof@freebsdmatrix.net>
#
# $FreeBSD$
#

PORTNAME=	NetSpades
PORTVERSION=	4.2.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.ece.rice.edu/~brentmh/spades/

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Very popular card game for 1-4 players over a network

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

MAKE_JOBS_SAFE=  yes

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -ltermcap"

MAN6=		gspades.6 slspades.6 spadesd.6

.include <bsd.port.mk>
