# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twitch
PORTVERSION=	1.0
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Twitch/${PORTVERSION}/ \
                SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
                ${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Overhead 2-d shooter, reminiscent of games like Robotron

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYGAME}

USES=		python

PORTDOCS=	AUTHORS BUGS README
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME} pkg-message

DESKTOP_ENTRIES="Twitch" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ActionGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|^.*#!.*python.*$$|#!${PYTHON_CMD}|; \
		s|whrandom|random|' \
		${WRKSRC}/${PORTNAME}.py
	@(cd ${WRKSRC} && ${RM} *.py.bak)

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images levels sound" \
		${STAGEDIR}${DATADIR})
.for f in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
