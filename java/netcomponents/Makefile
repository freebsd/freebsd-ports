# New ports collection makefile for:	NetComponents
# Date created:				November 9, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netcomponents
PORTVERSION=	1.3.8
CATEGORIES=	java net
MASTER_SITES=	http://www.savarese.org/oro/downloads/download/
DISTNAME=	NetComponents-${PORTVERSION}

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java library with common network protocol implementations

PLIST_FILES=	share/java/classes/NetComponents.jar
USE_JAVA=	1.1+
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/NetComponents-1.3.8a
NO_BUILD=	yes

JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILE=	NetComponents.jar

do-install:
	@${ECHO} -n ">> Installing JAR as ${JARDIR}/${JARFILE}..."
	@${CP} ${WRKSRC}/${JARFILE} ${JARDIR}/
	@${ECHO} " [ DONE ]"

	@${ECHO} -n ">> Fixing permissions..."
	@${CHMOD} 644 ${JARDIR}/${JARFILE}
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
