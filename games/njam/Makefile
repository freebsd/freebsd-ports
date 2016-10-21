# Created by: <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	njam
PORTVERSION=	1.25
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast paced multiplayer pac-man clone

GNU_CONFIGURE=	yes
USES=		gmake
CPPFLAGS+=	-I${LOCALBASE}/include -D__linux__
USE_SDL=	mixer image net sdl

PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="njam" \
		"${COMMENT}" \
		"${DATADIR}/njamicon.ico" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/src/*.o

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/games|/var/games|' \
		${WRKSRC}/src/njam.cpp

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
