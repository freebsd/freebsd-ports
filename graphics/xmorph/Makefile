# New ports collection makefile for:    xmorph
# Version required:     02oct96
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.2 1996/08/02 07:49:20 asami Exp $
#

DISTNAME=	xmorph-02oct96
PKGNAME=	xmorph-96.10.02
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.x.org/contrib/graphics/

MAINTAINER=	erich@FreeBSD.org

USE_X11=	yes

post-patch:
	(cd ${WRKSRC}; makedepend)

.include <bsd.port.mk>
