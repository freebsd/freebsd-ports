# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	jrosetta
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://maven.artenum.com/content/groups/public/com/artenum/${PORTNAME}/${PORTVERSION}/:source \
		http://maven.artenum.com/content/groups/public/com/artenum/${PORTNAME}/${PORTNAME}-api/${PORTVERSION}/:api \
		http://maven.artenum.com/content/groups/public/com/artenum/${PORTNAME}/${PORTNAME}-engine/${PORTVERSION}/:engine

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for building a graphical console in Swing

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes

PLIST_FILES=	%%JAVAJARDIR%%/jrosetta-api.jar \
		%%JAVAJARDIR%%/jrosetta-engine.jar

OPTIONS_DEFINE=	COMPILE
COMPILE_DESC=	Download and compile source instead of binaries

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPILE}
DISTFILES=	${PORTNAME}-${PORTVERSION}-sources.jar:source

BUILD_DEPENDS=	mvn:${PORTSDIR}/devel/maven3
JAVA_BUILD=	yes

MANUAL_PACKAGE_BUILD=	maven fetches files during build target

OUTPUT=		${WRKDIR}/m2/com/artenum/jrosetta
.else
DISTFILES=	${PORTNAME}-api-${PORTVERSION}.jar:api \
		${PORTNAME}-engine-${PORTVERSION}.jar:engine
EXTRACT_ONLY=

NO_BUILD=	yes
.endif

.if ${PORT_OPTIONS:MCOMPILE}
post-patch:
	${MKDIR} ${WRKDIR}/m2
	${CP} ${FILESDIR}/settings.xml ${WRKDIR}
	${REINPLACE_CMD} -e "s|WORK|${WRKDIR}|" ${WRKDIR}/settings.xml

do-build:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/mvn -gs "${WRKDIR}/settings.xml" clean install)
.endif

do-install:
.if ${PORT_OPTIONS:MCOMPILE}
	${INSTALL_DATA} ${OUTPUT}/jrosetta-api/${PORTVERSION}/jrosetta-api-${PORTVERSION}.jar \
		${JAVAJARDIR}/jrosetta-api.jar
	${INSTALL_DATA} ${OUTPUT}/jrosetta-engine/${PORTVERSION}/jrosetta-engine-${PORTVERSION}.jar \
		${JAVAJARDIR}/jrosetta-engine.jar
.else
	${INSTALL_DATA} ${DISTDIR}/jrosetta-api-${PORTVERSION}.jar \
		${JAVAJARDIR}/jrosetta-api.jar
	${INSTALL_DATA} ${DISTDIR}/jrosetta-engine-${PORTVERSION}.jar \
		${JAVAJARDIR}/jrosetta-engine.jar
.endif

.include <bsd.port.mk>
