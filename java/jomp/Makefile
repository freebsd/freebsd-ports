# New ports collection makefile for:	jomp
# Date created:			Wed Jul 14 14:02:25 CEST 2004
# Whom:				Christian Brueffer <brueffer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jomp
PORTVERSION=	1.0b
CATEGORIES=	java parallel
MASTER_SITES=	http://www.epcc.ed.ac.uk/research/jomp/download/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	brueffer@FreeBSD.org
COMMENT=	Prototype OpenMP implementation for Java

USE_JAVA=	yes
JAVA_VERSION=	1.2+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

JARFILE=	${DISTNAME}${EXTRACT_SUFX}

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${CP} ${DISTDIR}/${JARFILE} ${JAVAJARDIR}/${JARFILE}
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${JAVAJARDIR}/${JARFILE}
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
