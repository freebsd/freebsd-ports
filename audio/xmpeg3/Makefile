# New ports collection makefile for:	xmpeg3
# Version required:	1.0
# Date created:		7 July 1997
# Whom:			doconnor@ist.flinders.edu.au
#
# $Id: Makefile,v 1.8 1998/07/14 23:39:38 jseger Exp $
#

DISTNAME=	xmp3_1.0.0
PKGNAME=	xmpeg3-1.0
CATEGORIES=	audio tk80
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/audio/mpeg/amp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.ORG

RUN_DEPENDS=	amp:${PORTSDIR}/audio/amp \
		wish8.0:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/xmpeg3
NO_BUILD=	yes

post-patch:
	@/usr/bin/perl -pi -e "s|@@PREFIX@@|${PREFIX}|;" ${WRKSRC}/xmpeg3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmpeg3 ${PREFIX}/bin

.include <bsd.port.mk>
