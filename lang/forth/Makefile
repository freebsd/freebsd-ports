# New ports collection makefile for:    pfe
# Version required:     0.9.9
# Date created:         23 November 1994
# Whom:                 mr
#
# $Id: Makefile,v 1.10 1998/06/11 02:39:02 mph Exp $
#

DISTNAME=	pfe-0.9.9
CATEGORIES=	lang
MASTER_SITES=	ftp://sunsite.unc.edu/pub/multimedia/.languages/forth/ \
		ftp://ftp.lysator.liu.se/pub/languages/forth/ \
		ftp://ftp.uni-potsdam.de/pub/lang/forth/

MAINTAINER=	ports@FreeBSD.org

MAN1=		pfe.1
WRKSRC=		${WRKDIR}/pfe099

pre-install:
	@${CP} ${WRKSRC}/pfe.1 ${PREFIX}/man/man1/pfe.1

.include <bsd.port.mk>
