# New ports collection makefile for:   xteddy
# Date created:        3 June 1998
# Whom:                Eckart "Isegrim" Hofmann
#
# $FreeBSD$
#    $MCom: ports/games/xteddy/Makefile,v 1.1 2006/10/04 13:16:56 ahze Exp $

PORTNAME=	xteddy
PORTVERSION=	2.0.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://staffwww.itn.liu.se/~stegu/xteddy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cuddlesome teddy for the X desktop

NO_CDROM=	Can only be distributed for free

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GNOME=	imlib

MAN6=		xteddy.6

post-patch:
.for f in xteddy.c Makefile.in xteddy_test
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},g' ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
