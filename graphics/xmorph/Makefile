# New ports collection makefile for:    xmorph
# Version required:     02oct96
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.3 1996/11/15 13:27:55 erich Exp $
#

DISTNAME=	xmorph-02oct96
PKGNAME=	xmorph-96.10.02
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	graphics

MAINTAINER=	erich@FreeBSD.org

USE_X11=	yes

post-patch:
	(cd ${WRKSRC}; makedepend)

.include <bsd.port.mk>
