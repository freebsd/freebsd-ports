# New ports collection makefile for:	fortran-utils
# Date created:		19 Dec 1999
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	fortran-utils
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kris

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for use with Fortran code, from 4.4BSD

WRKSRC=		${WRKDIR}/fortran-utils

MAN1=		fpr.1 fsplit.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fpr/fpr ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fsplit/fsplit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fpr/fpr.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/fsplit/fsplit.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
