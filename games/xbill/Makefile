# New ports collection makefile for:	xbill
# Version required:	1.1
# Date created:		12 September 1995
# Whom:			asami
#
# $Id: Makefile,v 1.4 1997/02/12 10:25:56 obrien Exp $
#

DISTNAME=	xbill-2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

post-install:
	${CP} ${WRKSRC}/README ${PREFIX}/share/xbill

.include <bsd.port.mk>
