# New ports collection makefile for:	amp
# Version required:	0.7.3
# Date created:		Jun 23 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id$
#

DISTNAME=	amp-0.7.3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	vanilla@MinJe.com.TW

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		amp.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
