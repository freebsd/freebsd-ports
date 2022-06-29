# Created by: rfarmer@predatorlabs.net

PORTNAME=	jrosetta
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://maven.artenum.com/content/groups/public/com/artenum/${PORTNAME}/${PORTNAME}-api/${PORTVERSION}/:api \
		http://maven.artenum.com/content/groups/public/com/artenum/${PORTNAME}/${PORTNAME}-engine/${PORTVERSION}/:engine
DISTFILES=	${PORTNAME}-api-${PORTVERSION}.jar:api \
		${PORTNAME}-engine-${PORTVERSION}.jar:engine
EXTRACT_ONLY=	#

MAINTAINER=	makc@FreeBSD.org
COMMENT=	API for building a graphical console in Swing

USES=		zip
USE_JAVA=	yes
JAVA_RUN=	yes
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/jrosetta-api.jar \
		%%JAVAJARDIR%%/jrosetta-engine.jar

do-install:
	${INSTALL_DATA} ${DISTDIR}/jrosetta-api-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/jrosetta-api.jar
	${INSTALL_DATA} ${DISTDIR}/jrosetta-engine-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/jrosetta-engine.jar

.include <bsd.port.mk>
