# New ports collection makefile for:    tksol
# Version required:     1.0
# Date created:         26 June 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.2 1995/11/28 07:54:57 tg Exp $
#

DISTNAME=       tksol-1.0
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/misc_software/tksol/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

RUN_DEPENDS=	wish4.0:${PORTSDIR}/x11/tk4

PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/release

post-install:
	gzip -9nf ${PREFIX}/man/man1/tksol.1

.include <bsd.port.mk>
