# New ports collection makefile for:    SWIG
# Version required:     1.1b5p1
# Date created:         19 April 1996
# Whom:                 jkh
#
# $Id: Makefile,v 1.6 1997/03/27 23:48:18 erich Exp $
#

DISTNAME=	swig1.1
PKGNAME=	swig-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.utah.edu/pub/beazley/SWIG/

MAINTAINER=	erich@FreeBSD.org

WRKSRC=		${WRKDIR}/SWIG1.1
GNU_CONFIGURE=	yes

post-build:
	@cd ${WRKSRC}; make runtime

.include <bsd.port.mk>
