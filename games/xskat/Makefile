# New ports collection makefile for:	xskat
# Version required:	xskat-1.6
# Date created:		27 Apr 1996
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id$
#

DISTNAME=	xskat-1.6
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.germany.eu.net/pub/X11/misc/

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

WRKSRC=		${WRKDIR}/xskat
USE_IMAKE=	yes

pre-configure:
	cp ${FILESDIR}/Imakefile ${WRKSRC}
	mv ${WRKSRC}/makefile ${WRKSRC}/makefile.dist

.include <bsd.port.mk>
