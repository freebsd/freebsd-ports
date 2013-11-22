# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	gottet
PORTVERSION=	1.0.5
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Tetris clone

LICENSE=	GPLv3

USES=		qmake
USE_BZIP2=	yes
USE_QT4=	moc_build rcc_build iconengines_run imageformats_run
INSTALLS_ICONS=	yes

PORTDOCS=	CREDITS ChangeLog

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
