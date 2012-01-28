# Ports collection makefile for:  games/nlarn
# Date created:			  2011-11-08
# Whom:				  Martin Tournoij <martin@arp242.net>
#
# $FreeBSD$
#

PORTNAME=	nlarn
PORTVERSION=	0.7
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	martin@arp242.net
COMMENT=	Roguelike game and as such a remake of the classic game Larn

LICENSE=	GPLv3

BUILD_DEPENDS=	premake4:${PORTSDIR}/devel/premake4

WRKSRC=		${WRKDIR}/jaydg-nlarn-NLarn-${PORTVERSION}.0
USE_LUA=	5.1
USE_GNOME=	glib20
USE_GMAKE=	yes

do-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/premake4 --os=bsd gmake

post-configure:
	@${REINPLACE_CMD} 's|$$(ARCH)||g; \
		s|-I${LOCALBASE}|-I${LUA_INCDIR} -I${LOCALBASE}|g; \
		s|-lz|-lz -llua-5.1 -lncurses -lpanel|g;' \
	${WRKSRC}/nlarn.make

	@${REINPLACE_CMD} 's|/usr/share/games/nlarn|${DATADIR}|' \
		${WRKSRC}/src/game.c

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/nlarn ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README.txt ${WRKSRC}/nlarn.ini-sample ${WRKSRC}/lib/* ${DATADIR}/

.include <bsd.port.mk>
