# New ports collection makefile for:	radio
# Version required:	2.0.4
# Date created:		5 July 1995
# Whom:			janek@gaja.ipan.lublin.pl
#

DISTNAME=	radio2.0.4
PKGNAME=	radio-2.0.4
CATEGORIES+=	audio networking
MASTER_SITES=	ftp://ftp.cwi.nl/pub/audio/

NO_WRKSUBDIR=	yes
MAKE_FLAGS=	FreeBSD -f

post-install:
	gzip -9nf ${PREFIX}/man/man1/radio.1
	gzip -9nf ${PREFIX}/man/man1/broadcast.1

.include <bsd.port.mk>
