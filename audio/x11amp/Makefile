# New ports collection makefile for:    x11amp
# Version required:     0.7
# Date created:         13 Jul 1998
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/07/13 22:55:43 dburr Exp $
#

DISTNAME=	x11amp-0.7-FreeBSD
PKGNAME=	x11amp-0.7
CATEGORIES=	audio
MASTER_SITES=	http://x11amp.ml.org/files/0.7/ \
		ftp://x11amp.bz.nu/x11amp/0.7/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dburr@FreeBSD.ORG

WRKSRC=		${WRKDIR}/x11amp

USE_X_PREFIX=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x11amp ${PREFIX}/bin/x11amp

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
