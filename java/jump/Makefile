# New ports collection makefile for:	JUMP Ultimate Math Package
# Date created:				June 13, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jump
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	java math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.metaverse.nl/~ernst/
MASTER_SITE_SUBDIR=	jump-math

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/jakarta-ant

USE_JAVA=	1.2+

PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
TARGET_DIR?=	${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}
ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	jar
.else
ANT_TARGET=	jar apidocs
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JARDIR}/${PORTNAME}.jar..."
	@${CP} ${WRKSRC}/build/${PORTNAME}.jar ${JARDIR}/
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/build/apidocs/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
