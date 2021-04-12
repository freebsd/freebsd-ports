PORTNAME=	minilens
PORTVERSION=	1.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle platformer for gravity-oblivious aliens

LICENSE=	GPLv3+ CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	godot2:devel/godot2

USE_GITHUB=	yes
GH_ACCOUNT=	KOBUGE-Games

NO_ARCH=	yes

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/${PORTNAME}

DESKTOP_ENTRIES="Minilens" \
		"" \
		"${DATADIR}/icon.png" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		""

OPTIONS_DEFINE=	DOCS

do-build:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/${PORTNAME}
	@${ECHO_CMD} "exec \"${LOCALBASE}/bin/godot2\" -path \"${DATADIR}\"" >> ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS.txt ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
