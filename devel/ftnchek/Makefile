# New ports collection makefile for:	ftnchek
# Version required:	2.10.0
# Date created:		4 May 1998
# Whom:			kargl@apl.washington.edu
#
# $Id: Makefile,v 1.1.1.1 1998/05/05 05:07:48 mph Exp $

DISTNAME=	ftnchek
PKGNAME=	ftnchek-2.10.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netlib.org/fortran/

MAINTAINER=     kargl@apl.washington.edu

WRKSRC=		${WRKDIR}/${PKGNAME}

MAN1=		dcl2inc.1 ftnchek.1

GNU_CONFIGURE=	yes

post-install:
	strip ${PREFIX}/bin/ftnchek

.include <bsd.port.mk>
