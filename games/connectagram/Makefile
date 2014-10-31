# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	connectagram
PORTVERSION=	1.1.2
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Word unscrambling game

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake tar:bzip2
USE_QT4=	moc_build rcc_build gui network iconengines_run \
		imageformats_run
INSTALLS_ICONS=	yes

PORTDOCS=	CREDITS ChangeLog

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' '/qm.files/,/qm.path/s/^/#/' \
		${WRKSRC}/${PORTNAME}.pro
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC}/icons && ${COPYTREE_SHARE} patterns ${STAGEDIR}${DATADIR})

	@(cd ${WRKSRC}/icons && ${COPYTREE_SHARE} hicolor \
		${STAGEDIR}${PREFIX}/share/icons/)
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
			${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
