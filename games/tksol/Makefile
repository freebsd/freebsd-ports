# New ports collection makefile for:    tksol
# Version required:     1.0
# Date created:         26 June 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.12 1998/08/07 23:56:21 asami Exp $
#

DISTNAME=       tksol-1.0
CATEGORIES=	games tk80
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/misc_software/tksol/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@FreeBSD.ORG

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/release
MAN6=		tksol.6

.include <bsd.port.mk>
