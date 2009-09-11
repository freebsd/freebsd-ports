# New ports collection makefile for:	biloba
# Date created:		02 Oct 2005
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	biloba
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Biloba/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A strategy board game for 2 to 4 players

USE_SDL=	image mixer sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="Biloba" \
		"A strategy board game for 2 to 4 players" \
		"${DATADIR}/biloba_icon.png" \
		"biloba" \
		"Game;LogicGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
	    ${WRKSRC}/src/Makefile.server

post-install:
	${INSTALL_DATA} ${WRKSRC}/biloba_icon.png ${DATADIR}/

.include <bsd.port.mk>
