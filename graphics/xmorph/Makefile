# New ports collection makefile for:    xmorph
# Version required:     11sep97
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	xmorph-11sep97
PKGNAME=	xmorph-97.09.11
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	graphics

MAINTAINER=	erich@FreeBSD.org

MAN1=		xmorph.1
MANCOMPRESSED=	yes

USE_X_PREFIX=	yes

post-patch:
	(cd ${WRKSRC}; makedepend)

.include <bsd.port.mk>
