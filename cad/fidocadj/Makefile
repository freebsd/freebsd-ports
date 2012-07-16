# New ports collection makefile for:	fidocadj
# Date created:		2012-05-02
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fidocadj
PORTVERSION=	0.24
#PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	SF:src,docs
MASTER_SITE_SUBDIR=	${PORTNAME}/:src ${PORTNAME}/manuals/:docs
DISTFILES=	${PORTNAME}.jar:src
EXTRACT_ONLY=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	An easy to use graphical editor for electronics

LICENSE=	GPLv3

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh

JAVA_VERSION=	1.5+
USE_JAVA=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

FDCJ_MANUAL=	${PORTNAME}_manual_en.pdf

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}; \
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.jar ${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR} && \
	${INSTALL_DATA} ${DISTDIR}/${FDCJ_MANUAL} ${DOCSDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${PORTNAME}_manual_en.pdf:docs
.endif

.include <bsd.port.post.mk>
