# New ports collection makefile for:	wmpinboard
# Version required:		0.9
# Date created:			17 January 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $Id: Makefile,v 1.5 1999/08/07 08:01:04 cpiazza Exp $
#

DISTNAME=	wmpinboard-0.9
CATEGORIES=	deskutils afterstep windowmaker
MASTER_SITES=	http://www.tu-ilmenau.de/~gomar/stuff/wmpinboard/

MAINTAINER=	jim@FreeBSD.org

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
