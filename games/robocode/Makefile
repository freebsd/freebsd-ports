# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	robocode
PORTVERSION=	1.8.3.0
CATEGORIES=	games java
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-setup.jar \
		${PORTNAME}.png:icons
DIST_SUBDIR=	java
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-setup.jar

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game for learning Java[tm] programming language

LICENSE=	EPL

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_DOS2UNIX=	*.html *.MF *.battle *.java *.txt *.properties *.tpt

PORTDOCS=	ReadMe.html ReadMe.txt versions.md
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

SUB_FILES=	${PORTNAME}-sh pkg-message

DESKTOP_ENTRIES="Robocode" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;StrategyGame;" false

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.for d in battles compilers javadoc libs license roborumble robots templates
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

.for d in *.ico *.sh versions.md
	@(${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@${MKDIR} ${STAGEDIR}${DATADIR}/config
	@(cd ${STAGEDIR}${DATADIR} && ${CHMOD} -R 775 config roborumble robots)
	@${CHMOD} +x ${STAGEDIR}${DATADIR}/*.sh

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
