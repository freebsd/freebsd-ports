# New ports collection makefile for:	fidocadj
# Date created:		2012-05-02
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fidocadj
PORTVERSION=	0.23.7
#PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}.jar
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}_manual_en.pdf
.endif
EXTRACT_ONLY=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	An easy to use graphical editor for electronics

LICENSE=	GPLv3

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh

JAVA_VERSION=	1.5+
USE_JAVA=	yes

FDCJ_MANUAL=	${PORTNAME}_manual_en.pdf

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}; \
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.jar ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && \
	${INSTALL_DATA} ${DISTDIR}/${FDCJ_MANUAL} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
