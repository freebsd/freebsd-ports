# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	voadi
PORTVERSION=	0.3
CATEGORIES=	games
MASTER_SITES=	https://gitlab.com/${PORTNAME}/${PORTNAME}/-/archive/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Vegan on a Desert Island, 2D top-down adventure game

LICENSE=	GPLv3 CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE

RUN_DEPENDS=	solarus-run:games/solarus

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh

PORTDOCS=	README.md
PORTDATA=	*
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Vegan on a Desert Island" \
		"" \
		"${DATADIR}/data/logos/icon_64.png" \
		"${PORTNAME}" \
		"Game;AdventureGame;" \
		""

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
