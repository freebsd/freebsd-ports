# New ports collection makefile for:	xminehunter
# Version required:	0.3
# Date created:		09 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1997/01/10 12:23:20 asami Exp $
#

DISTNAME=	xminehunter-0.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
WRKSRC=		${WRKDIR}/xminehunter
REQUIRES_MOTIF=	yes
ALL_TARGET=	xminehunter

.include <bsd.port.mk>
