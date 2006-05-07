# New ports collection makefile for:	NetComponents
# Date created:				November 9, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netcomponents
PORTVERSION=	1.3.8
CATEGORIES=	java net
MASTER_SITES=	http://www.savarese.org/oro/
DISTNAME=	NetComponents-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java library with common network protocol implementations

RESTRICTED=	May not redistribute except as part of a new software product

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
USE_JAVA=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/NetComponents-1.3.8a
NO_BUILD=	yes

JARFILE=	NetComponents.jar

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=		must be manually fetched from ${MASTER_SITES}.  Download\
		${DISTFILES}, place it in ${DISTDIR} and restart this build
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
