# New ports collection makefile for:	xmpeg3
# Version required:	1.0
# Date created:		7 July 1997
# Whom:			doconnor@ist.flinders.edu.au
#
# $Id: Makefile,v 1.4 1998/02/21 22:38:11 fenner Exp $
#

DISTNAME=	xmp3_1.0.0
PKGNAME=	xmpeg3-1.0
CATEGORIES=	audio tk81
MASTER_SITES=	ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.ORG

RUN_DEPENDS=	amp:${PORTSDIR}/audio/amp \
		wish8.1:${PORTSDIR}/x11/tk81

WRKSRC=		${WRKDIR}/xmpeg3
NO_BUILD=	yes

post-patch:
	@/usr/bin/perl -pi -e "s|@@PREFIX@@|${PREFIX}|;" ${WRKSRC}/xmpeg3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmpeg3 ${PREFIX}/bin

.include <bsd.port.mk>
