# New ports collection makefile for:    nulib
# Version required:     3.25
# Date created:         Thu May  8 00:14:31 PDT 1997
# Whom:                 Steven Wallace <swallace@freebsd.org>
#
# $Id: Makefile,v 1.9 1996/12/07 09:28:40 max Exp $
#

DISTNAME=       nulib-3.25
CATEGORIES=	archivers
MASTER_SITES=	ftp://apple2.caltech.edu//Zocalo/pub/apple2/ARCHIVERS/
DISTFILES=	nulib325.tar.Z
WRKSRC=		${WRKDIR}/nulib

MAINTAINER=     swallace@freebsd.org

MAN1=		nulib.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nulib ${PREFIX}/bin/nulib
	${INSTALL_MAN} ${WRKSRC}/nulib.1 ${PREFIX}/man/man1/nulib.1

.include <bsd.port.mk>
