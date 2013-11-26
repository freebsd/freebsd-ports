# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	connectagram
PORTVERSION=	1.1.1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Word unscrambling game

LICENSE=	GPLv3

USE_BZIP2=	yes
USES=		desktop-file-utils qmake
USE_QT4=	moc_build rcc_build gui network iconengines_run \
		imageformats_run
INSTALLS_ICONS=	yes

PORTDOCS=	CREDITS ChangeLog

.include <bsd.port.options.mk>

post-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC}/icons && ${COPYTREE_SHARE} patterns ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC}/icons && ${COPYTREE_SHARE} hicolor ${STAGEDIR}${PREFIX}/share/icons/)
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png
			${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
