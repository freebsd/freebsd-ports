# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	xmlgraphics-commons
PORTVERSION=	1.5
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics textproc java
MASTER_SITES=	APACHE/xmlgraphics/commons/source

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Several reusable components used by Apache Batik and FOP

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
