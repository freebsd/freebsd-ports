# New ports collection makefile for:	xalan-j
# Date created:		21 February 2001
# Whom:			znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xalan-j
PORTVERSION=	2.4.0
CATEGORIES=	java textproc
MASTER_SITES=	http://xml.apache.org/dist/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}-src

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/jakarta-ant

USE_JAVA=	1.2+

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/./_/g}
ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	jar
.else
ANT_TARGET=	jar javadocs
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILE=	xalan.jar

do-configure:
	${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/xalan.sh >${WRKDIR}/xalan

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JARDIR}/${JARFILE}..."
	@${CP} ${WRKSRC}/build/${JARFILE} ${JARDIR}/
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/build/docs/apidocs/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
