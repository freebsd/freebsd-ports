# New ports collection makefile for:	wmpinboard
# Date created:			17 January 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmpinboard
PORTVERSION=	0.10
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
