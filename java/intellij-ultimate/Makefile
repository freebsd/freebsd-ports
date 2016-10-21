# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

# Based on the java/intellij port

PORTNAME=	intellij-ultimate
PORTVERSION=	2016.2.5
CATEGORIES=	java devel
MASTER_SITES=	https://download.jetbrains.com/idea/ \
		http://download.jetbrains.com/idea/
DISTNAME=	ideaIU-${PORTVERSION}

MAINTAINER=	andoriyu@gmail.com
COMMENT=	IntelliJ IDEA Ultimate Edition

LICENSE=	IntelliJ-Ultimate
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		intellij-pty4j>0:java/intellij-pty4j

USE_JAVA=	yes
JAVA_VERSION=	1.8+

NO_ARCH=	yes
NO_BUILD=	yes
USE_LDCONFIG=	${IDEA_HOME}/plugins/tfsIntegration/lib/native/freebsd/x86_64/
USE_LDCONFIG32=	${IDEA_HOME}/plugins/tfsIntegration/lib/native/freebsd/x86/

WRKDIST=	${WRKDIR}/idea-IU-162.2228.15

.include "${.CURDIR}/../intellij/common.mk"

PLIST_SUB+=	IDEA_HOME=${IDEA_HOME}
SUB_FILES+=	idea idea.desktop pkg-message
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}
CONFLICTS=	intellij-2016*
do-install:
	${MKDIR} ${STAGEDIR}${IDEA_HOME}
	@${TAR} -czf - -C ${WRKDIST} . | ${TAR} xzf - -C ${STAGEDIR}${IDEA_HOME}
# Linux/Windows/OS X only so remove them
	@${RM} ${STAGEDIR}${IDEA_HOME}/bin/fsnotifier \
		${STAGEDIR}${IDEA_HOME}/bin/fsnotifier-arm \
		${STAGEDIR}${IDEA_HOME}/bin/fsnotifier64 \
		${STAGEDIR}${IDEA_HOME}/bin/libbreakgen.so \
		${STAGEDIR}${IDEA_HOME}/bin/libbreakgen64.so \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-linux-amd64-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-linux-i386-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-osx-amd64-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-osx-i386-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-windows-amd64-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-windows-i386-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/bin/libyjpagent-linux.so \
		${STAGEDIR}${IDEA_HOME}/bin/libyjpagent-linux64.so
	@${RM} -r ${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/hpux/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/linux/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/macosx/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/solaris/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/win32/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/aix/
#	${STRIP_CMD} ${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/freebsd/x86/*.so
#	${STRIP_CMD} ${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/freebsd/x86_64/*.so
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${STAGEDIR}${IDEA_HOME}/lib/libpty
	@${RM} -r ${STAGEDIR}${IDEA_HOME}/jre/jre
	@${RM} ${STAGEDIR}${IDEA_HOME}/lib/pty4j-0.7.1.jar
	${INSTALL_SCRIPT} ${WRKDIR}/idea ${STAGEDIR}${PREFIX}/bin/idea
	${INSTALL_MAN} ${FILESDIR}/idea.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/idea.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKDIST}/lib && ${JAVA_HOME}/bin/jar xf icons.jar
	${INSTALL_DATA} ${WRKDIST}/lib/icon.png ${STAGEDIR}${IDEA_HOME}/idea.png
# TODO: Remove and enable fsnotifier when devel/libinotify is fixed
# Disable filewatcher warning message on IDEA startup
	${ECHO} "idea.filewatcher.disabled=true" >> ${STAGEDIR}${IDEA_HOME}/bin/idea.properties
# Use fsnotifier replacement provided by java/intellij-fsnotifier
#	${ECHO} "idea.filewatcher.executable.path=${IDEA_HOME}/bin/fsnotifier" >> ${STAGEDIR}${IDEA_HOME}/bin/idea.properties

.include <bsd.port.mk>
