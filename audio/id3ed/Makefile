# New ports collection makefile for:	id3ed
# Version required:	1.6
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=	id3ed-1.6
CATEGORIES=	audio
MASTER_SITES=	http://www.treefort.org/~donut/id3ed/

MAINTAINER=	cpiazza@home.net

WRKSRC=		${WRKDIR}/id3ed
USE_GMAKE=	yes
MAKE_ENV=	CXXFLAGS="${CXXFLAGS}" CXX="${CXX}"

MAN1=		id3ed.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/id3ed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/id3ed.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
