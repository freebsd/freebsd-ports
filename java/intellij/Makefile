# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

# Based on the devel/intellij port from OpenBSD by
# Vadim Zhukov <zhuk@openbsd.org>

PORTNAME=	intellij
PORTVERSION=	15.0.1
CATEGORIES=	java devel
MASTER_SITES=	https://download.jetbrains.com/idea/ \
		http://download.jetbrains.com/idea/
DISTNAME=	ideaIC-${PORTVERSION}

MAINTAINER=	t@tobik.me
COMMENT=	IntelliJ IDEA Java IDE

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	1.7+

NO_BUILD=	yes

WRKDIST=	${WRKDIR}/idea-IC-143.382.35

IDEA_HOME=	${PREFIX}/lib/intellij

PLIST_SUB+=	IDEA_HOME=${IDEA_HOME}
SUB_FILES+=	idea idea.desktop
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}

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
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-windows-i386-0.10.jar
	@${RM} -r ${STAGEDIR}${IDEA_HOME}/lib/libpty
	${INSTALL_SCRIPT} ${WRKDIR}/idea ${STAGEDIR}${PREFIX}/bin/idea
	${INSTALL_MAN} ${FILESDIR}/idea.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/idea.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKDIST}/lib && ${JAVA_HOME}/bin/jar xf icons.jar
	${INSTALL_DATA} ${WRKDIST}/lib/icon.png ${STAGEDIR}${IDEA_HOME}/idea.png

.include <bsd.port.mk>
