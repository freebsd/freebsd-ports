# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asylum
PORTVERSION=	0.3.2
CATEGORIES=	games
MASTER_SITES=	SF/sdl-${PORTNAME}/Asylum/${PORTVERSION}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Surreal platform shooting game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_SDL=	sdl mixer
ALL_TARGET=	build
USE_GL=		gl glu

PORTDOCS=	Instruct README
PORTDATA=	*

MAKE_ARGS=	INSTALLRESOURCEPATH="${DATADIR}" \
		INSTALLHISCORES="/var/games/${PORTNAME}"

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/${PORTNAME}
	@cd ${WRKSRC} && for f in *.c; do \
		${MV} $${f} $${f}pp; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}/var/games/${PORTNAME}
.for f in Ego Psyche Id Extended
	${TOUCH} ${STAGEDIR}/var/games/${PORTNAME}/${f}HighScores.sample
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
