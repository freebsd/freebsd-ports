# New ports collection makefile for:	xbill
# Version required:	1.1
# Date created:		12 September 1995
# Whom:			asami
#
# $Id: Makefile,v 1.5 1997/12/25 22:29:18 asami Exp $
#

DISTNAME=	xbill-2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

post-install:
	${CP} ${WRKSRC}/README ${PREFIX}/share/xbill

.include <bsd.port.mk>
