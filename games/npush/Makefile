# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	npush
PORTVERSION=	0.7
CATEGORIES=	games
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Curses-based logic game similar to Sokoban and Boulder Dash

USES=		ncurses
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|"levels|"${DATADIR}/levels|' \
		${WRKSRC}/npush.cpp

do-build:
	cd ${WRKSRC} && \
		${CXX} ${CXXFLAGS} -o npush npush.cpp ${LDFLAGS} -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/npush ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/levels
	${INSTALL_DATA} ${WRKSRC}/levels/* ${STAGEDIR}${DATADIR}/levels
	${INSTALL_DATA} ${WRKSRC}/npush.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/npush.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${WRKSRC}/readme.txt \
		${WRKSRC}/screenshot?.png ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
