# ex:ts=8
# Ports collection makefile for:	jcalendar
# Date created:			Apr 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jcalendar
PORTVERSION=	1.1.4
CATEGORIES=	java
MASTER_SITES=	http://www.toedter.com/download/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Date Chooser

USE_ZIP=	yes
USE_JAVA=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	${JAVAJARDIR:S,^${PREFIX}/,,}/jcalendar.jar \
		${JAVAJARDIR:S,^${PREFIX}/,,}/kunststoff.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
.for file in jcalendar.jar kunststoff.jar
	${INSTALL_DATA} ${WRKSRC}/lib/${file} ${JAVAJARDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
