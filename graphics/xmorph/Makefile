# New ports collection makefile for:    xmorph
# Version required:     11sep97
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.6 1997/03/28 15:11:10 erich Exp $
#

DISTNAME=	xmorph-11sep97
PKGNAME=	xmorph-97.09.11
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	graphics

MAINTAINER=	erich@FreeBSD.org

USE_X11=	yes

post-patch:
	(cd ${WRKSRC}; makedepend)

.include <bsd.port.mk>
