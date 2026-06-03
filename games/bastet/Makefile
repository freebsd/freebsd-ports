PORTNAME=	bastet
PORTVERSION=	0.43.2
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://fph.altervista.org/prog/files/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Ncurses Tetris clone which is harder than every other Tetris
WWW=		https://fph.altervista.org/prog/bastet.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES=		compiler:c++11-lang gmake localbase:ldflags ncurses tar:tgz
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	fph

PORTDOCS=	AUTHORS README NEWS

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bastet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bastet.6 ${STAGEDIR}${PREFIX}/share/man/man6/
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
