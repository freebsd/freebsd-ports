# New ports collection makefile for:    tksol
# Version required:     1.0
# Date created:         26 June 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.9 1997/11/22 20:48:34 jseger Exp $
#

DISTNAME=       tksol-1.0
CATEGORIES=	games tk80
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/misc_software/tksol/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@freebsd.org

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/release
MAN6=		tksol.6

.include <bsd.port.mk>
