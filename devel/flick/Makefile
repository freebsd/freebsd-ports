# New ports collection makefile for:	flick
# Version required:	2.0
# Date created:		21 Mar 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

DISTNAME=	flick-2.0-src
PKGNAME=	flick-2.0
CATEGORIES=	devel
MASTER_SITES=	ftp://flux.cs.utah.edu/flux/flick/2.0/

MAINTAINER=     ports@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

WRKSRC=	${WRKDIR}/${PKGNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/flick
	${INSTALL_DATA}	${WRKSRC}/doc/guts/*.ps ${PREFIX}/share/doc/flick
	${INSTALL_DATA}	${WRKSRC}/doc/usersguide/*.ps ${PREFIX}/share/doc/flick
.endif

.include <bsd.port.mk>
