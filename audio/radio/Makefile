# New ports collection makefile for:	radio
# Version required:	2.0.4
# Date created:		5 July 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $Id: Makefile,v 1.3 1996/10/18 07:47:10 max Exp $
#

DISTNAME=	radio2.0.4
PKGNAME=	radio-2.0.4
CATEGORIES+=	audio net
MASTER_SITES=	ftp://ftp.cwi.nl/pub/audio/

NO_WRKSUBDIR=	yes
MAKE_FLAGS=	FreeBSD -f

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/radio.1
	gzip -9nf ${PREFIX}/man/man1/broadcast.1
.endif

.include <bsd.port.mk>
