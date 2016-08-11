# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fidocadj
PORTVERSION=	0.24.6
#PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/:src SF/${PORTNAME}/manuals/:docs
DISTFILES=	${PORTNAME}.jar:src
EXTRACT_ONLY=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Easy to use graphical editor for electronics

LICENSE=	GPLv3

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh

JAVA_VERSION=	1.6+
USE_JAVA=	yes

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	${PORTNAME}_manual_en.pdf:docs

FDCJ_MANUAL=	${PORTNAME}_manual_en.pdf

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}; \
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.jar ${STAGEDIR}${DATADIR}/
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${DISTDIR}/${FDCJ_MANUAL} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
