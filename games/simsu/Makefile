# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	simsu
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Basic Sudoku game

LICENSE=	GPLv3

USES=		qmake
USE_BZIP2=	yes
USE_QT4=	moc_build rcc_build uic_build iconengines_run imageformats_run
INSTALLS_ICONS=	yes

PORTDOCS=	CREDITS ChangeLog

OPTIONS_DEFINE=	DOCS

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
