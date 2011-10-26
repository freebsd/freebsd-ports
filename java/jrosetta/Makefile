# New ports collection makefile for:	jrosetta
# Date created:				11 February 2010
# Whom:					rfarmer@predatorlabs.net
#
# $FreeBSD$
#

PORTNAME=	jrosetta
PORTVERSION=	1.0.4
CATEGORIES=	java devel
MASTER_SITES=	http://maven.artenum.com/content/groups/public/com/artenum/${PORTNAME}/${PORTVERSION}/ \
		http://www.predatorlabs.net/dl/
EXTRACT_SUFX=	-sources.jar

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	API for building a graphical console in Swing

BUILD_DEPENDS=	mvn:${PORTSDIR}/devel/maven3

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_BUILD=	yes
JAVA_RUN=	yes

PLIST_FILES=	%%JAVAJARDIR%%/jrosetta-api.jar \
		%%JAVAJARDIR%%/jrosetta-engine.jar

OUTPUT=		${WRKDIR}/m2/com/artenum/jrosetta

post-patch:
	${MKDIR} ${WRKDIR}/m2
	${CP} ${FILESDIR}/settings.xml ${WRKDIR}
	${REINPLACE_CMD} -e "s|WORK|${WRKDIR}|" ${WRKDIR}/settings.xml

do-build:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/mvn -gs "${WRKDIR}/settings.xml" clean install)

do-install:
	${INSTALL_DATA} ${OUTPUT}/jrosetta-api/${PORTVERSION}/jrosetta-api-${PORTVERSION}.jar \
		${JAVAJARDIR}/jrosetta-api.jar
	${INSTALL_DATA} ${OUTPUT}/jrosetta-engine/${PORTVERSION}/jrosetta-engine-${PORTVERSION}.jar \
		${JAVAJARDIR}/jrosetta-engine.jar

.include <bsd.port.mk>
