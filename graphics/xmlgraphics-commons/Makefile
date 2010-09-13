# New ports collection makefile for:	xmlgraphics-commons
# Date created:				11 February 2010
# Whom:					rfarmer@predatorlabs.net
#
# $FreeBSD$
#

PORTNAME=	xmlgraphics-commons
PORTVERSION=	1.4
CATEGORIES=	graphics textproc java
MASTER_SITES=	APACHE/xmlgraphics/commons/source
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Several reusable components used by Apache Batik and FOP

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_BUILD=	yes
JAVA_RUN=	yes
USE_ANT=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
