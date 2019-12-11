# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bastet
PORTVERSION=	0.43.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://fph.altervista.org/prog/files/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Ncurses Tetris clone which is harder than every other Tetris

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	does not build

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	fph

USES=		gmake localbase:ldflags ncurses tar:tgz

PORTDOCS=	AUTHORS README NEWS

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bastet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bastet.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/
	@${MKDIR} ${STAGEDIR}/var/games
	${TOUCH} ${STAGEDIR}/var/games/bastet.scores2.sample
	${INSTALL_DATA} ${WRKSRC}/bastet.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/bastet.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata/
	${INSTALL_DATA} ${WRKSRC}/bastet.appdata.xml ${STAGEDIR}${PREFIX}/share/appdata/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
