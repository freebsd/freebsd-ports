# New ports collection makefile for:	xscavenger
# Version required:	1.3
# Date created:		19 Feb 1998
# Whom:			eivind
#
# $Id: Makefile,v 1.7 1998/05/07 21:55:42 eivind Exp $
#

DISTNAME=	xscavenger-135
PKGNAME=	xscavenger-1.3.5
CATEGORIES=	games
MASTER_SITES=	http://www.xdr.com/dash/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eivind@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=yes
MAN6=		scavenger.6

post-install:
	@${INSTALL_MAN} ${WRKSRC}/scavenger.6 ${PREFIX}/man/man6/scavenger.6

.include <bsd.port.mk>
