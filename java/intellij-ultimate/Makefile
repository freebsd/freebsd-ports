# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

# Based on the java/intellij port

PORTNAME=	intellij-ultimate
PORTVERSION=	2019.1.1
CATEGORIES=	java devel
MASTER_SITES=	https://download.jetbrains.com/idea/ \
		http://download.jetbrains.com/idea/
DISTNAME=	ideaIU-${PORTVERSION}-no-jbr

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
NO_BUILD=	yes

WRKSRC=	${WRKDIR}/idea-IU-191.6707.61

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
		${STAGEDIR}${IDEA_HOME}/bin/libyjpagent-linux64.so
	@${RM} -rf ${STAGEDIR}${IDEA_HOME}/jre/jre/ \
		${STAGEDIR}${IDEA_HOME}/lib/pty4j-native/ \
		${STAGEDIR}${IDEA_HOME}/plugins/android/lib/libwebp/
	${INSTALL_SCRIPT} ${WRKDIR}/idea ${STAGEDIR}${PREFIX}/bin/idea
	${INSTALL_MAN} ${FILESDIR}/idea.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/idea.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${IDEA_HOME}/bin/fsnotifier" >> ${STAGEDIR}${IDEA_HOME}/bin/idea.properties

.include <bsd.port.mk>
