# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	CaribbeanStud
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	CS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Caribbean Stud gambling game for X Window System

MAKEFILE=	Xmakefile
USES=		motif
CFLAGS+=	-Wno-deprecated

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|iostream\.h|iostream|g' \
		${WRKSRC}/Card.cpp ${WRKSRC}/Card.h ${WRKSRC}/CaribbeanStud.cpp \
		${WRKSRC}/Dealer.cpp ${WRKSRC}/Deck.cpp ${WRKSRC}/Player.cpp \
		${WRKSRC}/Seat.cpp ${WRKSRC}/Table.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CaribbeanStud ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/CaribbeanStud.res ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/CaribbeanStud
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/CaribbeanStud
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/CaribbeanStud
	${INSTALL_DATA} ${WRKSRC}/class.ps ${STAGEDIR}${PREFIX}/share/doc/CaribbeanStud

.include <bsd.port.mk>
