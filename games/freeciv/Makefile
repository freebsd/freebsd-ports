# New ports collection makefile for:	freeciv
# Version required:	1.46
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $Id: Makefile,v 1.4 1998/02/06 15:55:03 tg Exp $
#

DISTNAME=	freeciv-150
PKGNAME=	freeciv-1.50
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.daimi.aau.dk/pub/stud/pjunold/freeciv/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ada@bsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/freeciv
USE_IMAKE=      	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	${MKDIR} ${PREFIX}/share/freeciv
	${INSTALL_DATA} $(WRKSRC)/data/helpdata.txt $(WRKSRC)/data/Freeciv \
		$(WRKSRC)/data/*.xpm ${PREFIX}/share/freeciv

.include <bsd.port.mk>
