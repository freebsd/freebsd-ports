# New ports collection makefile for:	fortran-utils
# Version required:	1.1
# Date created:		19 Dec 1999
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	fortran-utils-1.1
CATEGORIES=	devel
MASTER_SITES=	http://people.FreeBSD.org/~kris/distfiles/

MAINTAINER=	kris@FreeBSD.org

WRKSRC=		${WRKDIR}/fortran-utils

MAN1=		fpr.1 fsplit.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fpr/fpr ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fsplit/fsplit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fpr/fpr.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/fsplit/fsplit.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
