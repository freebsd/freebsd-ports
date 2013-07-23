# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	robocode
PORTVERSION=	1.8.2.0
CATEGORIES=	games java
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-setup.jar \
		${PORTNAME}.png:icons
DIST_SUBDIR=	java
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-setup.jar

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Game for learning Java[tm] programming language

LICENSE=	EPL

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PORTDOCS=	ReadMe.html ReadMe.txt versions.md
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

SUB_FILES=	${PORTNAME}.sh pkg-message

DESKTOP_ENTRIES="Robocode" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;StrategyGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.for d in battles compilers javadoc libs license roborumble robots templates
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

.for d in *.ico *.sh versions.md
	@(${INSTALL_DATA} ${WRKSRC}/${d} ${DATADIR})
.endfor

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps
	${MKDIR} -m a+rwx ${DATADIR}/config

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
