# New ports collection makefile for:    xcoral
# Version required:	2.5
# Date created:         
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.3 1996/11/11 05:07:39 obrien Exp $
#

DISTNAME=	xcoral-2.5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors

MAINTAINER=	erich@FreeBSD.ORG

USE_IMAKE=	yes

post-extract:
	@mv ${WRKSRC}/config.h ${WRKSRC}/config.h.in
	@sed 's,@PREFIX@,${PREFIX},' ${WRKSRC}/config.h.in >${WRKSRC}/config.h

.include <bsd.port.mk>
