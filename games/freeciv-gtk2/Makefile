# New ports collection makefile for:	freeciv
# Version required:	1.54
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $Id: Makefile,v 1.7 1998/03/12 01:43:49 vanilla Exp $
#

DISTNAME=	freeciv154
PKGNAME=	freeciv-1.54
CATEGORIES=	games
MASTER_SITES=	ftp://freeciv.ultraviolet.org/pub/freeciv/

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
