# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	connectagram
PORTVERSION=	1.1.1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Word unscrambling game

LICENSE=	GPLv3

USE_BZIP2=	yes
USES=		desktop-file-utils qmake
USE_QT4=	moc_build rcc_build gui network iconengines_run \
		imageformats_run
INSTALLS_ICONS=	yes

PORTDOCS=	CREDITS ChangeLog

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	@(cd ${WRKSRC}/icons && ${COPYTREE_SHARE} patterns ${DATADIR})
	@(cd ${WRKSRC}/icons && ${COPYTREE_SHARE} hicolor ${PREFIX}/share/icons/)
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
