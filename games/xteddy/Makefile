# New ports collection makefile for:   xteddy
# Date created:        3 June 1998
# Whom:                Eckart "Isegrim" Hofmann
#
# $FreeBSD$
#

PORTNAME=	xteddy
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://www.itn.liu.se/~stegu/xteddy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cuddlesome teddy for the X desktop

NO_CDROM=	"Can only be distributed for free"

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

MAN1=		xteddy.1

post-patch:
.for file in configure Makefile.in xteddy.1
	@${REINPLACE_CMD} -e 's|include/X11|share/xteddy|g' ${WRKSRC}/${file}
.endfor

pre-install:
	@${MKDIR} ${DATADIR}/pixmaps

.include <bsd.port.mk>
