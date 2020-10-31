# Created by: jjuanino@gmail.com
# $FreeBSD$

PORTNAME=	sqldeveloper
DISTVERSION=	20.2.0.175.1842
PORTREVISION=	1
DISTVERSIONSUFFIX=	-no-jre
CATEGORIES=	databases java
# https://www.oracle.com/tools/downloads/sqldev-downloads.html
MASTER_SITES=
DIST_SUBDIR=	oracle

MAINTAINER=	vvd@unislabs.com
COMMENT=	Graphical tool for database development

RUN_DEPENDS=	bash:shells/bash

USES=		gnome zip

# https://www.oracle.com/downloads/licenses/sqldev-license.html
LICENSE_NAME=	OTN
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror

USE_JAVA=	yes
INSTALLS_ICONS=	yes

JAVA_VERSION=	11+

NO_BUILD=	yes

OPTIONS_DEFINE=		OPENJFX14
OPTIONS_DEFAULT=	OPENJFX14
OPENJFX14_DESC=		Use JavaFX 14 (can work without it with some limitations)
OPENJFX14_RUN_DEPENDS=	openjfx14>=0:java/openjfx14

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	${PORTNAME}.desktop ${PORTNAME}.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		PORTNAME=${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENJFX14}
OPENJFX14_JVM_OPTIONS=	-J--module-path=${LOCALBASE}/openjfx14/lib \
			-J--add-modules=javafx.swing,javafx.web
.endif
SUB_LIST+=	OPENJFX14_JVM_OPTIONS="${OPENJFX14_JVM_OPTIONS}"

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	due to Oracle license restrictions, you must fetch the source \
distribution manually. Please access \
https://www.oracle.com/tools/downloads/sqldev-downloads.html \
with a web browser and follow the link for the ${DISTFILES}. You will be \
required to register and log in, but you can create an account on that \
page. After registration and accepting the Oracle License, download the \
distribution file, ${DISTFILES}, into ${DISTDIR}/${DIST_SUBDIR}/ and then \
restart this installation
.endif

do-install:
	${ECHO_MSG} -n ">> Installing scripts..."
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${ECHO_MSG} " [ DONE ]"

.for d in configuration dataminer dropins equinox \
    external ide javavm jdbc jdev jlib jviews module modules \
    netbeans orakafka rdbms sleepycat sqldeveloper sqlj svnkit
	${ECHO_MSG} -n ">> Installing data directory '${d}'..."
	cd ${WRKSRC} && ${FIND} ${d} -type d \
		-exec ${MKDIR} ${STAGEDIR}/${DATADIR}/\{} \;
	cd ${WRKSRC} && ${FIND} ${d} -type f \
		-not -name "*.exe" \
		-not -name "*.dll" \
		-not -name "*.so" \
		-not -name "*.jnilib" \
		-exec ${INSTALL_DATA} \{} ${STAGEDIR}/${DATADIR}/\{} \;
	${ECHO_MSG} " [ DONE ]"
.endfor

	@${ECHO_MSG} ">> Installing icon and desktop file ..."
	@${MKDIR} ${STAGEDIR}/${PREFIX}/share/applications/ \
	    ${STAGEDIR}/${PREFIX}/share/icons/hicolor/32x32/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}/${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/icon.png ${STAGEDIR}/${PREFIX}/share/icons/hicolor/32x32/apps/${PORTNAME}.png

	${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
