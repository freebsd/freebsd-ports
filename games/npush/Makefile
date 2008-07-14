# New ports collection makefile for:	npush
# Date created:		05 Jul 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	npush
PORTVERSION=	0.7
CATEGORIES=	games
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A curses-based logic game similar to Sokoban and Boulder Dash

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|"levels|"${DATADIR}/levels|' \
		${WRKSRC}/npush.cpp

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o npush npush.cpp -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/npush ${PREFIX}/bin
	${MKDIR} ${DATADIR}/levels
	${INSTALL_DATA} ${WRKSRC}/levels/* ${DATADIR}/levels
#	${MKDIR} ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/npush.png ${PREFIX}/share/pixmaps/
	${MKDIR} ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/npush.desktop ${PREFIX}/share/applications/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${WRKSRC}/readme.txt \
		${WRKSRC}/screenshot?.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
