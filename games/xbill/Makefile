# New ports collection makefile for:	xbill
# Version required:	1.1
# Date created:		12 September 1995
# Whom:			asami
#
# $Id: Makefile,v 1.5 1995/04/11 00:20:20 asami Exp $
#

DISTNAME=	xbill-1.1
CATEGORIES+=	games
MASTER_SITES=	ftp://crl.dec.com/pub/X11/contrib/games/
EXTRACT_SUFX=	.tgz

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xbill
NO_INSTALL_MANPAGES=	yes

post-install:
	cp ${WRKSRC}/README ${PREFIX}/lib/xbill

.include <bsd.port.mk>
