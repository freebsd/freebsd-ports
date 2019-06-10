# $FreeBSD$

PORTNAME=	goland
PORTVERSION=	2019.1.3
CATEGORIES=	devel java
MASTER_SITES=	https://download-cf.jetbrains.com/go/
PKGNAMEPREFIX=	jetbrains-
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	JetBrains GoLand IDE

LICENSE=	IntelliJ-GoLand
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		intellij-pty4j>0:java/intellij-pty4j

USES=		python:run shebangfix

USE_JAVA=	yes
JAVA_VERSION=	1.8+

SHEBANG_FILES=	bin/printenv.py bin/restart.py

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/GoLand-${PORTVERSION}

SUB_FILES=	goland goland.desktop pkg-message
SUB_LIST=	DATADIR=${DATADIR}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@${TAR} -czf - -C ${WRKSRC} . | ${TAR} xzf - -C ${STAGEDIR}${DATADIR}
# Linux/Windows/OS X only so remove them
	@${RM}  ${STAGEDIR}${DATADIR}/bin/fsnotifier \
		${STAGEDIR}${DATADIR}/bin/fsnotifier-arm \
		${STAGEDIR}${DATADIR}/bin/fsnotifier64 \
		${STAGEDIR}${DATADIR}/bin/lib*.so
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${STAGEDIR}${DATADIR}/lib/pty4j-native
# Remove bundled linux OpenJDK and DroidSerif fonts
	@${RM} -r ${STAGEDIR}${DATADIR}/jre64
	${INSTALL_SCRIPT} ${WRKDIR}/goland ${STAGEDIR}${PREFIX}/bin/goland
	${INSTALL_MAN} ${FILESDIR}/goland.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/goland.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKSRC}/lib && ${JAVA_HOME}/bin/jar xf icons.jar
	${INSTALL_DATA} ${WRKSRC}/lib/icon.png ${STAGEDIR}${DATADIR}/goland.png
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/intellij/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Fix slow render
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/goland.vmoptions
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/goland64.vmoptions

.include <bsd.port.mk>
