# Created by: Stefan Wendler <stefan.wendler@tngtech.com>
# $FreeBSD$

PORTNAME=	rubymine
PORTVERSION=	2016.3
CATEGORIES=	java devel
MASTER_SITES=	https://download.jetbrains.com/ruby/ \
		http://download.jetbrains.com/ruby/
PKGNAMEPREFIX=	intellij-
DISTNAME=	RubyMine-${PORTVERSION}

MAINTAINER=	stefan.wendler@tngtech.com
COMMENT=	IntelliJ RubyMine Edition

LICENSE=	IntelliJ-Rubymine
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		intellij-pty4j>0:java/intellij-pty4j

USE_JAVA=	yes
JAVA_VERSION=	1.8+

NO_ARCH=	yes
NO_BUILD=	yes

WRKDIST=	${WRKDIR}/RubyMine-2016.3

.include "${.CURDIR}/../intellij/common.mk"

PLIST_SUB+=	DATADIR=${DATADIR}
SUB_FILES+=	rubymine rubymine.desktop pkg-message
SUB_LIST+=	DATADIR=${DATADIR}
do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@${TAR} -czf - -C ${WRKDIST} . | ${TAR} xzf - -C ${STAGEDIR}${DATADIR}
# Linux/Windows/OS X only so remove them
	@${RM} ${STAGEDIR}${DATADIR}/bin/fsnotifier \
		${STAGEDIR}${DATADIR}/bin/fsnotifier-arm \
		${STAGEDIR}${DATADIR}/bin/fsnotifier64 \
		${STAGEDIR}${DATADIR}/bin/libbreakgen.so \
		${STAGEDIR}${DATADIR}/bin/libbreakgen64.so \
		${STAGEDIR}${DATADIR}/plugins/gradle/lib/native-platform-linux-amd64-0.10.jar \
		${STAGEDIR}${DATADIR}/plugins/gradle/lib/native-platform-linux-i386-0.10.jar \
		${STAGEDIR}${DATADIR}/plugins/gradle/lib/native-platform-osx-amd64-0.10.jar \
		${STAGEDIR}${DATADIR}/plugins/gradle/lib/native-platform-osx-i386-0.10.jar \
		${STAGEDIR}${DATADIR}/plugins/gradle/lib/native-platform-windows-amd64-0.10.jar \
		${STAGEDIR}${DATADIR}/plugins/gradle/lib/native-platform-windows-i386-0.10.jar \
		${STAGEDIR}${DATADIR}/bin/libyjpagent-linux.so \
		${STAGEDIR}${DATADIR}/bin/libyjpagent-linux64.so
	@${RM} -r ${STAGEDIR}${DATADIR}/plugins/tfsIntegration/lib/native/hpux/ \
		${STAGEDIR}${DATADIR}/plugins/tfsIntegration/lib/native/linux/ \
		${STAGEDIR}${DATADIR}/plugins/tfsIntegration/lib/native/macosx/ \
		${STAGEDIR}${DATADIR}/plugins/tfsIntegration/lib/native/solaris/ \
		${STAGEDIR}${DATADIR}/plugins/tfsIntegration/lib/native/win32/ \
		${STAGEDIR}${DATADIR}/plugins/tfsIntegration/lib/native/aix/
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${STAGEDIR}${DATADIR}/lib/libpty
	@${RM} -r ${STAGEDIR}${DATADIR}/jre/jre
	@${RM} ${STAGEDIR}${DATADIR}/lib/pty4j-0.7.1.jar
	${INSTALL_SCRIPT} ${WRKDIR}/rubymine ${STAGEDIR}${PREFIX}/bin/rubymine
	${INSTALL_MAN} ${FILESDIR}/rubymine.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/rubymine.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKDIST}/lib && ${JAVA_HOME}/bin/jar xf icons.jar
	${INSTALL_DATA} ${WRKDIST}/lib/icon.png ${STAGEDIR}${DATADIR}/rubymine.png
# TODO: Remove and enable fsnotifier when devel/libinotify is fixed
# Disable filewatcher warning message on IDEA startup
	${ECHO} "idea.filewatcher.disabled=true" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Use fsnotifier replacement provided by java/intellij-fsnotifier
#	${ECHO} "idea.filewatcher.executable.path=${DATADIR}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties

.include <bsd.port.mk>
