# New ports collection makefile for:	xbill
# Version required:	1.1
# Date created:		12 September 1995
# Whom:			asami
#
# $Id: Makefile,v 1.1.1.1 1995/09/12 10:29:41 asami Exp $
#

DISTNAME=	xbill-1.1
CATEGORIES+=	games
MASTER_SITES=	ftp://crl.dec.com/pub/X11/contrib/games/
EXTRACT_SUFX=	.tgz

MAINTAINER=	asami@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xbill
NO_INSTALL_MANPAGES=	yes

post-install:
	cp ${WRKSRC}/README ${PREFIX}/lib/xbill

.include <bsd.port.mk>
