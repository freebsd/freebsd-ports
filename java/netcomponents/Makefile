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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java library with common network protocol implementations

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
USE_JAVA=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/NetComponents-1.3.8a
NO_BUILD=	yes

JARFILE=	NetComponents.jar

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
