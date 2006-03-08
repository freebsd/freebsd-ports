# New ports collection makefile for:   xteddy
# Date created:        3 June 1998
# Whom:                Eckart "Isegrim" Hofmann
#
# $FreeBSD$
#

PORTNAME=	xteddy
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://staffwww.itn.liu.se/~stegu/xteddy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cuddlesome teddy for the X desktop

NO_CDROM=	Can only be distributed for free

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"
USE_GNOME=	imlib

MAN6=		xteddy.6

post-patch:
.for f in xteddy.c Makefile.in xteddy_test
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},g' ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
