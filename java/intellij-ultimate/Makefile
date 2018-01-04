# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

# Based on the java/intellij port

PORTNAME=	intellij-ultimate
PORTVERSION=	2017.3.1
CATEGORIES=	java devel
MASTER_SITES=	https://download.jetbrains.com/idea/ \
		http://download.jetbrains.com/idea/
DISTNAME=	ideaIU-${PORTVERSION}-no-jdk

MAINTAINER=	andoriyu@gmail.com
COMMENT=	IntelliJ IDEA Ultimate Edition

LICENSE=	IntelliJ-Ultimate
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		intellij-pty4j>0:java/intellij-pty4j

USES=	python:run shebangfix
USE_JAVA=	yes
JAVA_VERSION=	1.8+
SHEBANG_FILES=	bin/printenv.py bin/restart.py

NO_ARCH=	yes
NO_ARCH_IGNORE=	libnative_auth.so libnative_console.so libnative_filesystem.so \
		libnative_misc.so libnative_synchronization.so \
		native-platform-freebsd-amd64-libcpp-0.14.jar native-platform-freebsd-amd64-libstdcpp-0.14.jar \
		native-platform-freebsd-i386-libcpp-0.14.jar native-platform-freebsd-i386-libstdcpp-0.14.jar
NO_BUILD=	yes
USE_LDCONFIG=	${IDEA_HOME}/plugins/tfsIntegration/lib/native/freebsd/x86_64/
USE_LDCONFIG32=	${IDEA_HOME}/plugins/tfsIntegration/lib/native/freebsd/x86/

WRKSRC=	${WRKDIR}/idea-IU-173.3942.27

.include "${.CURDIR}/../intellij/common.mk"

PLIST_SUB+=	IDEA_HOME=${IDEA_HOME}
SUB_FILES+=	idea idea.desktop pkg-message
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}
CONFLICTS=	intellij-20*
do-install:
	${MKDIR} ${STAGEDIR}${IDEA_HOME}
	@${TAR} -czf - -C ${WRKSRC} . | ${TAR} xzf - -C ${STAGEDIR}${IDEA_HOME}
# Linux/Windows/OS X only so remove them
	@${RM} ${STAGEDIR}${IDEA_HOME}/bin/fsnotifier \
		${STAGEDIR}${IDEA_HOME}/bin/fsnotifier-arm \
		${STAGEDIR}${IDEA_HOME}/bin/fsnotifier64 \
		${STAGEDIR}${IDEA_HOME}/bin/libbreakgen.so \
		${STAGEDIR}${IDEA_HOME}/bin/libbreakgen64.so \
		${STAGEDIR}${IDEA_HOME}/bin/libyjpagent-linux.so \
		${STAGEDIR}${IDEA_HOME}/plugins/android/lib/gluegen-rt-natives-linux-*.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/android/lib/gluegen-rt-natives-macosx-universal.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/android/lib/gluegen-rt-natives-windows-*.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/android/lib/jogl-all-natives-linux-*.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/android/lib/jogl-all-natives-macosx-universal.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/android/lib/jogl-all-natives-windows-*.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-linux-*.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-osx-*.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-windows-*.jar \
		${STAGEDIR}${IDEA_HOME}/bin/libyjpagent-linux64.so
	@${RM} -r ${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/hpux/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/linux/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/macosx/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/solaris/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/win32/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/aix/
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${STAGEDIR}${IDEA_HOME}/lib/libpty
	@${RM} -r ${STAGEDIR}${IDEA_HOME}/jre/jre
	@${RM} ${STAGEDIR}${IDEA_HOME}/lib/pty4j-0.7.1.jar
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
