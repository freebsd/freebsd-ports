# New ports collection makefile for:    nulib
# Version required:     3.25
# Date created:         Thu May  8 00:14:31 PDT 1997
# Whom:                 Steven Wallace <swallace@freebsd.org>
#
# $Id: Makefile,v 1.2 1998/01/08 18:51:54 fenner Exp $
#

DISTNAME=	nulib325
PKGNAME=	nulib-3.25
CATEGORIES=	archivers
MASTER_SITES=	ftp://apple2.caltech.edu/%2FZocalo/pub/apple2/ARCHIVERS/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     swallace@freebsd.org

WRKSRC=		${WRKDIR}/nulib
MAN1=		nulib.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nulib ${PREFIX}/bin/nulib
	${INSTALL_MAN} ${WRKSRC}/nulib.1 ${PREFIX}/man/man1/nulib.1

.include <bsd.port.mk>
