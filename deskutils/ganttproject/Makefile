# ex:ts=8
# Ports collection makefile for:	ganttproject
# Date created:			Jul 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ganttproject
PORTVERSION=	1.10.1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	-src.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plan projects using a Gantt chart

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
JAVA_RUN=	yes

PLIST_FILES=	bin/ganttproject %%JAVAJARDIR%%/ganttproject.jar

post-patch:
	@${SED} 's,%%JAVAJARDIR%%,${JAVAJARDIR},; \
		 s,%%JAVA%%,${JAVA},' ${FILESDIR}/${PORTNAME} > ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
