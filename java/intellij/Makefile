# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

# Based on the devel/intellij port from OpenBSD by
# Vadim Zhukov <zhuk@openbsd.org>

PORTNAME=	intellij
PORTVERSION=	2018.3.5
CATEGORIES=	java devel
MASTER_SITES=	https://download.jetbrains.com/idea/ \
		http://download.jetbrains.com/idea/
DISTNAME=	ideaIC-${PORTVERSION}-no-jdk

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	IntelliJ IDEA Community Edition

LICENSE=	APACHE20

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		intellij-pty4j>0:java/intellij-pty4j

USE_JAVA=	yes
JAVA_VERSION=	1.7+
USES=		python:run shebangfix
SHEBANG_FILES=	bin/printenv.py bin/restart.py

NO_ARCH=	yes
NO_BUILD=	yes
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/idea-IC-183.5912.21

.include "common.mk"

PLIST_SUB+=	IDEA_HOME=${IDEA_HOME}
SUB_FILES+=	idea idea.desktop pkg-message
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}

do-install:
	${MKDIR} ${STAGEDIR}${IDEA_HOME}
	@${TAR} -czf - -C ${WRKSRC} . | ${TAR} xzf - -C ${STAGEDIR}${IDEA_HOME}
# Linux/Windows/OS X only so remove them
	@${RM} ${STAGEDIR}${IDEA_HOME}/bin/fsnotifier \
		${STAGEDIR}${IDEA_HOME}/bin/fsnotifier-arm \
		${STAGEDIR}${IDEA_HOME}/bin/fsnotifier64 \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-linux-*.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-osx-*.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-windows-*.jar
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${STAGEDIR}${IDEA_HOME}/lib/pty4j-native
	${INSTALL_SCRIPT} ${WRKDIR}/idea ${STAGEDIR}${PREFIX}/bin/idea
	${INSTALL_MAN} ${FILESDIR}/idea.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/idea.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKSRC}/lib && ${JAVA_HOME}/bin/jar xf icons.jar
	${INSTALL_DATA} ${WRKSRC}/lib/icon.png ${STAGEDIR}${IDEA_HOME}/idea.png
# TODO: Remove and enable fsnotifier when devel/libinotify is fixed
# Disable filewatcher warning message on IDEA startup
	${ECHO} "idea.filewatcher.disabled=true" >> ${STAGEDIR}${IDEA_HOME}/bin/idea.properties
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${IDEA_HOME}/bin/fsnotifier" >> ${STAGEDIR}${IDEA_HOME}/bin/idea.properties

.include <bsd.port.mk>
