# New ports collection makefile for:	freeciv
# Version required:	1.0j
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $Id: Makefile,v 1.1.1.1 1997/07/09 09:39:07 max Exp $
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
