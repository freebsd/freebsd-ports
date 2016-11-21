# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tanks-of-freedom
PORTVERSION=	0.6.0
DISTVERSIONSUFFIX=-beta
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Indie Turn Based Strategy in Isometric Pixel Art

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	godot:devel/godot

USE_GITHUB=	yes
GH_ACCOUNT=	w84death
GH_PROJECT=	Tanks-of-Freedom

NO_ARCH=	yes

DESKTOP_ENTRIES="Tanks of Freedom" \
		"" \
		"${DATADIR}/assets/icons/icon32.png" \
		"${PORTNAME}" \
		"Game;StrategyGame;" \
		""

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

do-build:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/${PORTNAME}
	@${ECHO_CMD} "exec \"${LOCALBASE}/bin/godot\" -path \"${DATADIR}\"" >> ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
