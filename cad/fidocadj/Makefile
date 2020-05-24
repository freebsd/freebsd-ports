# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fidocadj
PORTVERSION=	0.24.7
PORTREVISION=	0
CATEGORIES=	cad java
# No USE_GITHUB here because GITHUB_EXTRACT_SUFX is hardcoded to .tar.gz
MASTER_SITES=	https://github.com/DarwinNE/FidoCadJ/releases/download/v${PORTVERSION}/
DISTFILES=	${PORTNAME}.jar
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Easy to use graphical editor for electronics

LICENSE=	GPLv3

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh

USE_JAVA=	yes

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	manual_en.pdf

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}; \
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}.jar ${STAGEDIR}${DATADIR}/
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DOCS_DISTFILES} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
