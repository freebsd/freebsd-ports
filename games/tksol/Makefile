# New ports collection makefile for:    tksol
# Version required:     1.0
# Date created:         26 June 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id$
#

DISTNAME=       tksol-1.0
CATEGORIES+=	games
KEYWORDS+=	games x11 tk solitaire
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/misc_software/tksol/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

LIB_DEPENDS=	tk\\.3\\.:${PORTSDIR}/x11/tk

PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/release

post-install:
	gzip -9nf ${PREFIX}/man/man1/tksol.1

.include <bsd.port.mk>
