# New ports collection makefile for:    xcoral
# Version required:	2.5
# Date created:         
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.1.1.1 1995/10/02 16:14:41 erich Exp $
#

DISTNAME=	xcoral-2.5
CATEGORIES+=	editors
MASTER_SITES=	ftp://public.x.org/contrib/editors/

MAINTAINER=	erich@FreeBSD.ORG

USE_IMAKE=	yes

post-extract:
	@mv ${WRKSRC}/config.h ${WRKSRC}/config.h.in
	@sed 's,@PREFIX@,${PREFIX},' ${WRKSRC}/config.h.in >${WRKSRC}/config.h

.include <bsd.port.mk>
