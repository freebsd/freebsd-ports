# New ports collection makefile for:	Jakarta Commons CLI
# Date created:				November 14, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-cli
PORTVERSION=	1.0
CATEGORIES=	java
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-commons/release/${PORTNAME}/v${PORTVERSION}/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/jakarta-ant \
		${LOCALBASE}/share/java/classes/commons-lang.jar:${PORTSDIR}/java/jakarta-commons-lang

USE_JAVA=	1.2+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	jar -Dnoget
.else
ANT_TARGET=	jar javadoc -Dnoget -verbose
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILE=	${PORTNAME}-${PORTVERSION}-beta-2-dev.jar
DESTJARFILE=	${PORTNAME}.jar

do-build:
	@${MKDIR} ${WRKSRC}/lib
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JARDIR}/${DESTJARFILE}..."
	@${CP} ${WRKSRC}/target/${JARFILE} ${JARDIR}/${DESTJARFILE}
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/target/docs/apidocs/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
