# New ports collection makefile for:	freeciv
# Version required:	1.6.3
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $Id: Makefile,v 1.8 1998/05/05 22:12:42 mph Exp $
#

DISTNAME=	freeciv-1.6.3
CATEGORIES=	games
MASTER_SITES=	ftp://freeciv.ultraviolet.org/pub/freeciv/

MAINTAINER=	ada@bsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=      	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	${MKDIR} ${PREFIX}/share/freeciv
	${INSTALL_DATA} $(WRKSRC)/data/helpdata.txt $(WRKSRC)/data/Freeciv \
		$(WRKSRC)/data/*.xpm ${PREFIX}/share/freeciv

.include <bsd.port.mk>
