# New ports collection makefile for:    xlife
# Version required:     3.0
# Date created:         15 March 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.9 1998/09/28 02:28:45 steve Exp $
#

DISTNAME=       xlife
PKGNAME=	xlife-3.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	../R5contrib
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.ORG

USE_IMAKE=      yes
MAN1=		xlife.1

pre-install:
	@(cd ${WRKSRC}; make install.patterns)

.include <bsd.port.mk>
