# New ports collection makefile for:    xmorph
# Version required:     17jan97
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.5 1996/11/26 15:58:34 erich Exp $
#

DISTNAME=	xmorph-17jan97
PKGNAME=	xmorph-97.01.17
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	graphics

MAINTAINER=	erich@FreeBSD.org

USE_X11=	yes

post-patch:
	(cd ${WRKSRC}; makedepend)

.include <bsd.port.mk>
