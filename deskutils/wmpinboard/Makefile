# New ports collection makefile for:	wmpinboard
# Version required:		0.9
# Date created:			17 January 1999
# Whom:				Jim Mock <jim@blues.ghis.net>
#
# $Id: Makefile,v 1.4 1999/06/10 08:51:56 tg Exp $
#

DISTNAME=	wmpinboard-0.9
CATEGORIES=	deskutils afterstep windowmaker
MASTER_SITES=	http://www.tu-ilmenau.de/~gomar/stuff/wmpinboard/

MAINTAINER=	jim@blues.ghis.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wmpinboard.app

USE_BZIP2=	yes
USE_IMAKE=	yes

MAN1=		wmpinboard.1
MANCOMPRESSED=	no

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmpinboard ${X11BASE}/bin

post-install:
	@${INSTALL_MAN} ${WRKSRC}/wmpinboard.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
