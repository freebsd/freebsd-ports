# New ports collection makefile for:    xblackjack
# Version required:     2.2
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.5 1998/09/28 02:16:36 steve Exp $
#

DISTNAME=	xblackjack-2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	erich@FreeBSD.org

BROKEN_ELF=	lesstif does not work for this one

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
MAN1=		xblackjack.1

.include <bsd.port.mk>
