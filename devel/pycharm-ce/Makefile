PORTNAME=	pycharm-ce
DISTVERSION=	2022.2
CATEGORIES=	devel java python
MASTER_SITES=	https://download.jetbrains.com/python/ \
		http://download.jetbrains.com/python/
DISTNAME=	pycharm-community-${PORTVERSION}

MAINTAINER=	jonc@chen.org.nz
COMMENT=	JetBrains PyCharm Community Edition IDE

LICENSE=	APACHE20

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		intellij-pty4j>0:java/intellij-pty4j

USES=		python:run shebangfix
USE_JAVA=	yes
JAVA_VERSION=	11+
SHEBANG_FILES=	bin/restart.py

NO_ARCH=	yes
NO_BUILD=	yes

.include "${.CURDIR}/../../java/intellij/common.mk"

SUB_FILES+=	pkg-message pycharm ${PORTNAME}.desktop
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}

# Remove non-native binaries
post-extract:
	@${RM} ${WRKSRC}/bin/*fsnotifier* ${WRKSRC}/bin/*.so ${WRKSRC}/bin/repair
	@${FIND} ${WRKSRC}/plugins -name '*.so' -delete
	@${RM} -r ${WRKSRC}/plugins/cwm-plugin/quiche-native
	@${RM} -r ${WRKSRC}/plugins/python-ce/helpers/pydev/pydevd_attach_to_process
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${WRKSRC}/lib/pty4j-native
	@${RM} ${WRKSRC}/lib/pty4j-0.5.jar
# Remove bundled linux-only JRE
	@${RM} -r ${WRKSRC}/jbr
# TODO: Remove and enable fsnotifier when devel/libinotify is fixed
# Disable filewatcher warning message on IDEA startup
	${ECHO} "idea.filewatcher.disabled=true" >> ${WRKSRC}/bin/idea.properties
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${IDEA_HOME}/bin/fsnotifier" >> ${WRKSRC}/bin/idea.properties

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd "${WRKSRC}" && ${FIND} . | ${CPIO} -pdum -R root:wheel ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/pycharm ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
