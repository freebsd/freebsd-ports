# New ports collection makefile for:    tksol
# Version required:     1.0
# Date created:         26 June 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.5 1996/11/18 11:25:09 asami Exp $
#

DISTNAME=       tksol-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/misc_software/tksol/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@freebsd.org

RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41

PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/release
MAN6=		tksol.6

.include <bsd.port.mk>
