# New ports collection makefile for:    pfe
# Version required:     0.9.9
# Date created:         23 November 1994
# Whom:                 mr
#
# $Id: Makefile,v 1.5 1995/04/22 12:12:26 jkh Exp $
#

#This is pfe Version 0.9.9
#By mr
DISTNAME=	pfe099
PKGNAME=	pfe-0.9.9
DISTFILES=	pfe-0.9.9.tar.gz
CATEGORIES+=	languages
MASTER_SITES=	ftp://sunsite.unc.edu/pub/languages/forth/

pre-install:
	@cp ${WRKSRC}/pfe.1 ${PREFIX}/man/man1/pfe.1
	@gzip -9nf ${PREFIX}/man/man1/pfe.1

.include <bsd.port.mk>

