# New ports collection makefile for:   rio
# Version required:    1.06
# Date created:        29 April 1999
# Whom:                Nick Sayer <nsayer@freebsd.org>
#
# $Id: Makefile,v 1.1.1.1 1999/03/02 00:07:02 fenner Exp $
#

DISTNAME=	rio006
PKGNAME=	rio-1.06
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
