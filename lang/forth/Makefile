# New ports collection makefile for:    pfe
# Version required:     0.9.9
# Date created:         23 November 1994
# Whom:                 mr
#
# $Id: Makefile,v 1.7 1995/11/22 13:12:39 asami Exp $
#

DISTNAME=	pfe099
PKGNAME=	pfe-0.9.9
CATEGORIES=	lang
MASTER_SITES=	ftp://sunsite.unc.edu/pub/languages/forth/
DISTFILES=	pfe-0.9.9.tar.gz

pre-install:
	@${CP} ${WRKSRC}/pfe.1 ${PREFIX}/man/man1/pfe.1
	@gzip -9nf ${PREFIX}/man/man1/pfe.1

.include <bsd.port.mk>

