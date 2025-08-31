PORTNAME=	voadi
DISTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Vegan on a Desert Island, 2D top-down adventure game
WWW=		https://www.voadi.com/

LICENSE=	GPLv3 CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE

RUN_DEPENDS=	solarus-run:games/solarus

USE_GITLAB=	yes
GL_TAGNAME=	228b8ebf61afbd4f1c609224466d4fb10c11218a

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
