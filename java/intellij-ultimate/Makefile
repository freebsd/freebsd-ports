# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

# Based on the java/intellij port

PORTNAME=	intellij-ultimate
PORTVERSION=	2018.3.2
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

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier

USES=	python:run shebangfix

USE_JAVA=	yes
JAVA_VERSION=	1.8+
SHEBANG_FILES=	bin/printenv.py bin/restart.py

NO_ARCH=	yes
NO_ARCH_IGNORE=	libnative_auth.so libnative_console.so libnative_filesystem.so \
		libnative_misc.so libnative_synchronization.so
NO_BUILD=	yes
USE_LDCONFIG=	${IDEA_HOME}/plugins/tfsIntegration/lib/native/freebsd/x86_64/
USE_LDCONFIG32=	${IDEA_HOME}/plugins/tfsIntegration/lib/native/freebsd/x86/

WRKSRC=	${WRKDIR}/idea-IU-183.4886.37

.include "${.CURDIR}/../intellij/common.mk"

PLIST_SUB+=	IDEA_HOME=${IDEA_HOME}
SUB_FILES+=	idea idea.desktop pkg-message
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}
CONFLICTS=	intellij-20*

do-install:
	${MKDIR} ${STAGEDIR}${IDEA_HOME}
	@${TAR} -czf - -C ${WRKSRC} . | ${TAR} xzf - -C ${STAGEDIR}${IDEA_HOME}
# Linux/Windows/OS X only so remove them
	@${RM} -f ${STAGEDIR}${IDEA_HOME}/bin/fsnotifier \
		${STAGEDIR}${IDEA_HOME}/bin/fsnotifier-arm \
		${STAGEDIR}${IDEA_HOME}/bin/fsnotifier64 \
		${STAGEDIR}${IDEA_HOME}/bin/libdbm64.so \
		${STAGEDIR}${IDEA_HOME}/bin/libyjpagent-linux.so \
		${STAGEDIR}${IDEA_HOME}/bin/libyjpagent-linux64.so \
		${STAGEDIR}${IDEA_HOME}/plugins/performanceTesting/lib/libasyncProfiler-linux.so \
		${STAGEDIR}${IDEA_HOME}/plugins/performanceTesting/lib/libasyncProfiler-macos.so
	@${RM} -rf ${STAGEDIR}${IDEA_HOME}/jre/jre/ \
		${STAGEDIR}${IDEA_HOME}/plugins/android/lib/libwebp/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/aix/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/hpux/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/linux/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/macosx/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/solaris/ \
		${STAGEDIR}${IDEA_HOME}/plugins/tfsIntegration/lib/native/win32/
	${INSTALL_SCRIPT} ${WRKDIR}/idea ${STAGEDIR}${PREFIX}/bin/idea
	${INSTALL_MAN} ${FILESDIR}/idea.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/idea.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${IDEA_HOME}/bin/fsnotifier" >> ${STAGEDIR}${IDEA_HOME}/bin/idea.properties

.include <bsd.port.mk>
