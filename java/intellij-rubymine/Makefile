# Created by: Stefan Wendler <stefan.wendler@tngtech.com>
# $FreeBSD$

PORTNAME=	rubymine
PORTVERSION=	2019.1.2
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

USES=		python:run shebangfix
SHEBANG_FILES=	bin/printenv.py bin/restart.py

NO_ARCH=	yes
NO_BUILD=	yes

WRKDIST=	${WRKDIR}/RubyMine-${PORTVERSION}

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
		${STAGEDIR}${DATADIR}/bin/lib*.so \
		${STAGEDIR}${DATADIR}/bin/libyjpagent-linux.so \
		${STAGEDIR}${DATADIR}/bin/libyjpagent-linux64.so
	@${RM} ${STAGEDIR}${DATADIR}/plugins/performanceTesting/lib/lib*.so
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${STAGEDIR}${DATADIR}/lib/pty4j-native
	@${RM} ${STAGEDIR}${DATADIR}/lib/pty4j-0.7.10.jar
# Remove bundled linux OpenJDK and DroidSerif fonts
	@${RM} -r ${STAGEDIR}${DATADIR}/jre/jre64
	${INSTALL_SCRIPT} ${WRKDIR}/rubymine ${STAGEDIR}${PREFIX}/bin/rubymine
	${INSTALL_MAN} ${FILESDIR}/rubymine.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/rubymine.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKDIST}/lib && ${JAVA_HOME}/bin/jar xf icons.jar
	${INSTALL_DATA} ${WRKDIST}/lib/icon.png ${STAGEDIR}${DATADIR}/rubymine.png
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${DATADIR}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties

.include <bsd.port.mk>
