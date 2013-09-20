# Created by: Christian Brueffer <brueffer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jomp
PORTVERSION=	1.0b
PORTREVISION=	2
CATEGORIES=	java parallel
MASTER_SITES=	http://www2.epcc.ed.ac.uk/computing/research_activities/jomp/download/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	brueffer@FreeBSD.org
COMMENT=	Prototype OpenMP implementation for Java

USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

JARFILE=	${DISTNAME}${EXTRACT_SUFX}

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

NO_STAGE=	yes
do-install:
	@${ECHO} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${CP} ${DISTDIR}/${JARFILE} ${JAVAJARDIR}/${JARFILE}
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${JAVAJARDIR}/${JARFILE}
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
