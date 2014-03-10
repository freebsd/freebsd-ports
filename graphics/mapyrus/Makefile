# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	mapyrus
PORTVERSION=	1.302
PORTREVISION=	0
CATEGORIES=	graphics print java
MASTER_SITES=	SF

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A software for creating plots of points, lines, etc

LICENSE=	LGPL21

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USES=		zip

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	${PORTNAME} pkg-message
SUB_LIST=	JAVA_VERSION=${JAVA_VERSION} \
		MAPYRUSJAR=${MAPYRUSJAR}

MAPYRUSJAR=	${PORTNAME}.jar
MAPYRUSDOCS=	${PORTNAME}.pdf

FIND_DATA=	-type f -not \( -iname "copying" -or -iname "*.tex" \)
FIND_HERE=	userdoc

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${MAPYRUSJAR} ${DATADIR}/${MAPYRUSJAR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${MAPYRUSDOCS} ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKDIR} && ${FIND} ${FIND_HERE} ${FIND_DATA} -exec ${INSTALL_DATA} {} ${EXAMPLESDIR} \;
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
