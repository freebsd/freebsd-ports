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
COMMENT=	Java library for arbitrary precision computations

BROKEN=		Checksum mismatch

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.2+

ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	jar
.else
ANT_TARGET=	jar apidocs
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILE=	${PORTNAME}.jar

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JARDIR}/${JARFILE}..."
	@${CP} ${WRKSRC}/build/${JARFILE} ${JARDIR}/
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/build/apidocs/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
