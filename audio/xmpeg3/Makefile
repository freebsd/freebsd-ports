# New ports collection makefile for:	xmpeg3
# Version required:	1.0
# Date created:		7 July 1997
# Whom:			doconnor@ist.flinders.edu.au
#
# $Id$
#

DISTNAME=	xmp3_1.0.0
PKGNAME=	xmpeg3-1.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.ORG

RUN_DEPENDS=	amp:${PORTSDIR}/audio/amp \
		wish4.2:${PORTSDIR}/x11/tk42

WRKSRC=		${WRKDIR}/xmpeg3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmpeg3 ${PREFIX}/bin

.include <bsd.port.mk>
