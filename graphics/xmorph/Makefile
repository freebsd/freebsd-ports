# New ports collection makefile for:    xmorph
# Version required:     13nov96
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.4 1996/11/16 09:15:10 asami Exp $
#

DISTNAME=	xmorph-13nov96
PKGNAME=	xmorph-96.11.13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	graphics

MAINTAINER=	erich@FreeBSD.org

USE_X11=	yes

post-patch:
	(cd ${WRKSRC}; makedepend)

.include <bsd.port.mk>
