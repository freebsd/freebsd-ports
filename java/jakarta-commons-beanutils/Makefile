# New ports collection makefile for:	Jakarta Commons Beanutils
# Date created:				November 14, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-beanutils
PORTVERSION=	1.0
CATEGORIES=	java
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-commons/release/${PORTNAME}/v${PORTVERSION}/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/jakarta-ant \
		${LOCALBASE}/share/java/classes/commons-collections.jar:${PORTSDIR}/java/jakarta-commons-collections

USE_JAVA=	1.2+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/beanutils

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
	@${CP} ${FILESDIR}/LICENSE ${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/

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
