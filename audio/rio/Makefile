# New ports collection makefile for:   rio
# Version required:    1.05
# Date created:        6 February 1999
# Whom:                Dermot McNally <derm@ibm.net>
#
# $Id$
#

DISTNAME=	rio005
PKGNAME=	rio-1.05
CATEGORIES=	audio
MASTER_SITES=	http://www.world.co.uk/sba/
EXTRACT_SUFX=	.tgz

MAINTAINER=	derm@ibm.net

WRKSRC=		${WRKDIR}/rio
MAKEFILE=	makefile

BINOWN=		root
BINMODE=	4755

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rio ${PREFIX}/bin

.include <bsd.port.mk>
