# New ports collection makefile for:	xmbase-grok
# Version required:	1.3.2
# Date created:		Sat Aug 30 13:29:42 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.3 1998/01/27 00:44:49 fenner Exp $
#

DISTNAME=	xmbase-grok-1.3.2.sbin
PKGNAME=	xmbase-grok-1.3.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/database/flatfile

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=      Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/${PKGNAME}
REQUIRES_MOTIF=	yes
USE_IMAKE=	yes

.include <bsd.port.mk>
