# New ports collection makefile for:	xbill
# Version required:	1.1
# Date created:		12 September 1995
# Whom:			asami
#
# $Id: Makefile,v 1.2 1995/10/06 07:53:05 asami Exp $
#

DISTNAME=	xbill-1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tgz

MAINTAINER=	asami@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xbill
NO_INSTALL_MANPAGES=	yes

post-install:
	cp ${WRKSRC}/README ${PREFIX}/lib/xbill

.include <bsd.port.mk>
