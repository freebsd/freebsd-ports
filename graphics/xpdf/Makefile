# New ports collection makefile for:	xpdf
# Version required:     0.5
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $Id: Makefile,v 1.6 1996/06/03 00:13:01 asami Exp $
#

DISTNAME=       xpdf-0.5
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.andrew.cmu.edu/pub/xpdf/

MAINTAINER=	chuckr@glue.umd.edu

USE_X11=	yes
MAN1=		xpdf.1 pdftops.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/xpdf.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pdftops.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
