# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fidocadj
PORTVERSION=	0.24.4
#PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	SF:src,docs
MASTER_SITE_SUBDIR=	${PORTNAME}/:src ${PORTNAME}/manuals/:docs
DISTFILES=	${PORTNAME}.jar:src
EXTRACT_ONLY=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Easy to use graphical editor for electronics

LICENSE=	GPLv3

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh

JAVA_VERSION=	1.6+
USE_JAVA=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

FDCJ_MANUAL=	${PORTNAME}_manual_en.pdf

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}; \
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.jar ${STAGEDIR}${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${DISTDIR}/${FDCJ_MANUAL} ${STAGEDIR}${DOCSDIR}/
.endif

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${PORTNAME}_manual_en.pdf:docs
.endif

.include <bsd.port.mk>
