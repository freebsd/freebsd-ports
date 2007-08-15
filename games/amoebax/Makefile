# New ports collection makefile for:	amoebax
# Date created:		15 Aug 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	amoebax
PORTVERSION=	0.2.0
CATEGORIES=	games
MASTER_SITES=	http://www.emma-soft.com/games/amoebax/download/ \
		http://www.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Cute and addictive Puyo Puyo like game

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image

MAN6=		amoebax.6

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|doc||' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC}/ -name Makefile.in|${XARGS}\
		${REINPLACE_CMD} -e '/^pkgdatadir =/s|=.*|= ${DATADIR}|'

.include <bsd.port.mk>
