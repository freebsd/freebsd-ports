# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pycharm-ce
PORTVERSION=	2018.3.5
CATEGORIES=	devel java python
MASTER_SITES=	https://download.jetbrains.com/python/ \
		http://download.jetbrains.com/python/
DISTNAME=	pycharm-community-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	JetBrains PyCharm Community Edition IDE

LICENSE=	APACHE20

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		intellij-pty4j>0:java/intellij-pty4j

USES=		python:run shebangfix
SHEBANG_FILES=	bin/printenv.py bin/restart.py
USE_JAVA=	yes
JAVA_VERSION=	1.7+

NO_ARCH=	yes
NO_BUILD=	yes

.include "${.CURDIR}/../../java/intellij/common.mk"

SUB_FILES+=	pkg-message pycharm ${PORTNAME}.desktop
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${TAR} -czf - -C ${WRKSRC} . | ${TAR} xzf - -C ${STAGEDIR}${DATADIR}
# Linux/Windows/OS X only so remove them
	@${RM} ${STAGEDIR}${DATADIR}/bin/*fsnotifier*
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${STAGEDIR}${DATADIR}/lib/pty4j-native
# Remove bundled linux-only JRE
	@${RM} -r ${STAGEDIR}${DATADIR}/jre64
	@${RM} -r ${STAGEDIR}${DATADIR}/helpers/pydev/pydevd_attach_to_process
	@${RM} ${STAGEDIR}${DATADIR}/lib/pty4j-0.5.jar
	${INSTALL_SCRIPT} ${WRKDIR}/pycharm ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	#cd ${WRKSRC}/lib && ${JAVA_HOME}/bin/jar xf icons.jar
# TODO: Remove and enable fsnotifier when devel/libinotify is fixed
# Disable filewatcher warning message on IDEA startup
	${ECHO} "idea.filewatcher.disabled=true" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${IDEA_HOME}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties

.include <bsd.port.mk>
