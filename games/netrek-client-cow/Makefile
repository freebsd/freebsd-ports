# New ports collection makefile for:	netrek-client-cow
# Date created:	20 April 2012
# Whom:	Kevin Zheng <kevinz5000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	netrek-client-cow
PORTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.netrek.org/files/COW/ \
		http://quozl.us.netrek.org/netrek/

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	A multi-player battle simulation with a Star Trek theme

LIB_DEPENDS=	Imlib2:${PORTSDIR}/graphics/imlib2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer
CONFIGURE_ARGS+=	NORSA='\#'

post-patch:
	${REINPLACE_CMD} -e 's|ushort  damage|unsigned short damage|' \
		${WRKSRC}/short.c
	${REINPLACE_CMD} -e 's|inline void|void|' \
		${WRKSRC}/local.[ch]
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/x11sprite.c ${WRKSRC}/netrek-client-cow.desktop
	${REINPLACE_CMD} -e 's|games|bin|' \
		${WRKSRC}/netrek-client-cow.desktop

.include <bsd.port.mk>
