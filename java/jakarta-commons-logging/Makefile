# New ports collection makefile for:	Jakarta Commons Logging
# Date created:				November 14, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-logging
PORTVERSION=	1.0.3
CATEGORIES=	java
MASTER_SITES=	http://apache.cs.uu.nl/dist/jakarta/commons/logging/source/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Generic logging wrapper library

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant \
		${LOCALBASE}/share/java/classes/log4j.jar:${PORTSDIR}/java/jakarta-log4j

USE_JAVA=	1.2+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	dist
.else
ANT_TARGET=	dist
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILE=	${PORTNAME}.jar
DESTJARFILE=	${PORTNAME}.jar

post-extract:
	@${CP} ${PORTSDIR}/java/jakarta-commons-beanutils/files/LICENSE ${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JARDIR}/${DESTJARFILE}..."
	@${CP} ${WRKSRC}/dist/${JARFILE} ${JARDIR}/${DESTJARFILE}
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/dist/docs/api/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
