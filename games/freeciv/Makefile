# New ports collection makefile for:	freeciv
# Version required:	1.0j
# Whom:			ada@bsd.org
# Date created:		Jun 20 1997
#
# $Id$
#

DISTNAME=	freeciv-1.0j
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.daimi.aau.dk/pub/stud/pjunold/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ada@bsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/freeciv
USE_IMAKE=      	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	${MKDIR} ${PREFIX}/share/freeciv
	${INSTALL_DATA} $(WRKSRC)/data/Freeciv $(WRKSRC)/data/*.xpm \
	  ${PREFIX}/share/freeciv
.include <bsd.port.mk>
