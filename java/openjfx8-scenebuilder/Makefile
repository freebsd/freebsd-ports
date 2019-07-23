# $FreeBSD$

PORTNAME=	openjfx8
DISTVERSION=	8u202-b07
CATEGORIES=	java x11-toolkits devel
MASTER_SITES=	https://github.com/t6/openjfx/releases/download/release/ \
		http://hg.openjdk.java.net/openjfx/8u/rt/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy=/
PKGNAMESUFFIX=	-scenebuilder

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	JavaFX Scene Builder

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	openjfx8-devel>0:java/openjfx8-devel
RUN_DEPENDS=	openjfx8-devel>0:java/openjfx8-devel

USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8+

ALL_TARGET=	jar-sb
DESKTOP_ENTRIES=	"JavaFX Scene Builder" "JavaFX Scene Builder" \
			"" "scenebuilder" "Development;GUIDesigner;" false
NO_ARCH=	yes
PLIST_FILES=	bin/scenebuilder \
		${JAVAJARDIR}/SceneBuilderApp.jar \
		${JAVAJARDIR}/SceneBuilderKit.jar
SUB_FILES=	scenebuilder
WRKSRC=		${WRKDIR}/rt-${DISTVERSION}/apps/scenebuilder

do-install:
	${INSTALL_DATA} ${WRKSRC}/SceneBuilderApp/dist/SceneBuilderApp.jar \
		${WRKSRC}/SceneBuilderKit/dist/SceneBuilderKit.jar \
		${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/scenebuilder ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
