# New ports collection makefile for:	freeciv
# Version required:	1.7.0
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $Id: Makefile,v 1.11 1998/09/15 11:13:08 asami Exp $
#

DISTNAME=	freeciv-1.7.0
CATEGORIES=	games
MASTER_SITES=	ftp://www.freeciv.org/pub/freeciv/

MAINTAINER=	ada@bsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=      	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	${MKDIR} ${PREFIX}/share/freeciv
	${INSTALL_DATA} $(WRKSRC)/data/helpdata.txt $(WRKSRC)/data/Freeciv \
		$(WRKSRC)/data/*.xpm ${PREFIX}/share/freeciv

.include <bsd.port.mk>
