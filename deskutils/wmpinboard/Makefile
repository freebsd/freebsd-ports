# New ports collection makefile for:	wmpinboard
# Date created:			17 January 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmpinboard
PORTVERSION=	0.10
CATEGORIES=	deskutils afterstep windowmaker
MASTER_SITES=	http://www.tu-ilmenau.de/~gomar/stuff/wmpinboard/ \
		http://soupnazi.org/FreeBSD/ports/distfiles/

MAINTAINER=	jim@FreeBSD.org

WRKSRC=		${WRKDIR}/wmpinboard.app

USE_BZIP2=	yes
USE_IMAKE=	yes
USE_XPM=	yes

MAN1=		wmpinboard.1

post-extract:
	(cd ${WRKSRC}; ${CP} -p wmpinboard.1 wmpinboard.man)

.include <bsd.port.mk>
