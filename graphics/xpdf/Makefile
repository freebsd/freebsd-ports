# New ports collection makefile for:	xpdf
# Version required:     0.4
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $Id: Makefile,v 1.4 1996/05/04 01:42:19 asami Exp $
#

DISTNAME=       xpdf-0.5
CATEGORIES+=	graphics
MASTER_SITES=   ftp://ftp.andrew.cmu.edu/pub/xpdf/

MAINTAINER=	chuckr@glue.umd.edu

USE_X11=	yes

post-install:
	install -c -m 444 ${WRKSRC}/xpdf.1 ${PREFIX}/man/man1
	install -c -m 444 ${WRKSRC}/pdftops.1 ${PREFIX}/man/man1
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/xpdf.1 ${PREFIX}/man/man1/pdftops.1
.endif

.include <bsd.port.mk>
