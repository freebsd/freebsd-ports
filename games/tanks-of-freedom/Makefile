# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tanks-of-freedom
PORTVERSION=	git20150306
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Indie Turn Based Strategy in Isometric Pixel Art

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	godot:${PORTSDIR}/devel/godot

USE_GITHUB=	yes
GH_ACCOUNT=	w84death
GH_PROJECT=	Tanks-of-Freedom
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	56699f4

DESKTOP_ENTRIES="Tanks of Freedom" \
		"" \
		"${DATADIR}/icon.png" \
		"${PORTNAME}" \
		"Game;StrategyGame;" \
		""

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

do-build:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/${PORTNAME}
	@${ECHO_CMD} "exec ${PREFIX}/bin/godot -path ${DATADIR}" >> ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
