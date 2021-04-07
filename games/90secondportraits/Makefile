PORTNAME=	90secondportraits
PORTVERSION=	1.01b
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Silly speed painting game

LICENSE=	ZLIB MIT CC-BY-SA-4.0 CC-BY-3.0
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	love10:devel/love10

USE_GITHUB=	yes
GH_ACCOUNT=	SimonLarsen
GH_PROJECT=	90-Second-Portraits
GH_TUPLE=	vrld:hump:537ca76:hump/hump \
		kikito:middleclass:f670920:middleclass/middleclass

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png
PORTDOCS=	*
PORTDATA=	*

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="${PORTNAME}" \
		"" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" \
		"Game;Art;" \
		""

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/android-icons/drawable-xhdpi/ic_launcher.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
