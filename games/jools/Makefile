# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jools
PORTVERSION=	0.20
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://pessimization.com/software/jools/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-musicpack-1.0${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Addictive jewel-swapping puzzle game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYGAME}

USES=		python
USE_PYTHON=	distutils

PORTDOCS=	POINTS manual.html manual.pdf manual.tex
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Jools" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-extract:
.for d in timed title untimed
	@(cd ${WRKDIR} && ${COPYTREE_SHARE} ${d} ${WRKSRC}/jools/music/)
.endfor

post-patch:
	@${FIND} ${WRKSRC} -name ".arch-ids" | ${XARGS} ${RM} -fr
	@${FIND} ${WRKSRC} -name ".arch-ids" -delete \
		-or -name ".placeholder" -delete

.for f in setup.py jools/__init__.py jools/jools
	@${REINPLACE_CMD} -e 's|^.*#!.*python.*$$|#!${PYTHON_CMD}|' \
		${WRKSRC}/${f}
.endfor
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-install:
	${LN} -sf ${DATADIR}/images/jools-logo-small.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
