# New ports collection makefile for:   ici
# Version required:    2.0.3
# Date created:        18 December 1997
# Whom:                andy
#
# $Id$
#

DISTNAME=	ici-2.0.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.research.canon.com.au/pub/misc/ici/

MAINTAINER=	andy@research.canon.com.au

MAKEFILE=	${WRKSRC}/Makefile.bsd
MAKE_ENV=	MANDIR=${PREFIX}/man/man
MAN1=		ici.1
MANCOMPRESSED=	yes

post-install:
	${MV} ${PREFIX}/bin/ici.bsd ${PREFIX}/bin/ici

.include <bsd.port.mk>
