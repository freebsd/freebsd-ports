# New ports collection makefile for:	flick
# Version required:	1.1
# Date created:		21 Mar 1998
# Whom:			giffunip@asme.org
#
# $Id$
#

DISTNAME=	flick-src-1.1
PKGNAME=	flick-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://flux.cs.utah.edu/flux/flick/

MAINTAINER=     ports@FreeBSD.ORG

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

WRKSRC=	${WRKDIR}/${PKGNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/flick
	${INSTALL_DATA}	${WRKSRC}/doc/*.ps ${PREFIX}/share/doc/flick
	${INSTALL_DATA}	${WRKSRC}/doc/usersguide/*.ps ${PREFIX}/share/doc/flick
.endif

.include <bsd.port.mk>
