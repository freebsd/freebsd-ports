# New ports collection makefile for:	ftnchek
# Version required:	2.9.5
# Date created:		4 May 1998
# Whom:			kargl@apl.washington.edu
#
# $Id$

DISTNAME=	ftnchek
PKGNAME=	ftnchek-2.9.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netlib.org/fortran/

MAINTAINER=     kargl@apl.washington.edu

WRKSRC=		${WRKDIR}/ftnchek-2.9.5

MAN1=		ftnchek.1

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	strip ${PREFIX}/bin/ftnchek

.include <bsd.port.mk>
