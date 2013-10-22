# Created by: arved
# $FreeBSD$

PORTNAME=	qnetwalk
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://qt.osdn.org.ua/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Qt-version of the NetWalk game

LICENSE=	GPLv2

USE_QT4=	corelib gui qmake_build moc_build rcc_build
USE_SDL=	mixer

MAN6=		qnetwalk.6

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "pics sounds translations" ${DATADIR})
	@${LN} -sf ${DATADIR}/pics/computer2.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/menu/qnetwalk.desktop ${PREFIX}/share/applications

	${INSTALL_MAN} ${MAN6:S|^|${WRKSRC}/|} ${MAN6PREFIX}/man/man6
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
