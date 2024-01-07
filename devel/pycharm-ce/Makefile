PORTNAME=	pycharm-ce
DISTVERSION=	2023.3.2
CATEGORIES=	devel java python
MASTER_SITES=	https://download.jetbrains.com/python/ \
		http://download.jetbrains.com/python/
DISTNAME=	pycharm-community-${PORTVERSION}

MAINTAINER=	jonc@chen.org.nz
COMMENT=	JetBrains PyCharm Community Edition IDE
WWW=		https://www.jetbrains.com/pycharm/

LICENSE=	APACHE20

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		jetbrains-pty4j>=0.12.13:devel/jetbrains-pty4j \
		jetbrains-sqlite>=232.8660.185:devel/jetbrains-sqlite

USES=		python:run shebangfix
USE_JAVA=	yes
JAVA_VERSION=	17+
SHEBANG_FILES=	plugins/python-ce/helpers/pycodestyle.py \
		plugins/python-ce/helpers/pycodestyle-2.10.0.py \
		plugins/python-ce/helpers/typeshed/scripts/sync_tensorflow_protobuf_stubs.sh

NO_BUILD=	yes

.include "${.CURDIR}/../../java/intellij/common.mk"

SUB_FILES+=	pkg-message pycharm ${PORTNAME}.desktop
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}

# Remove non-native binaries
post-extract:
	@${RM} ${WRKSRC}/bin/*fsnotifier* ${WRKSRC}/bin/*.so ${WRKSRC}/bin/repair ${WRKSRC}/bin/restarter
	@${FIND} ${WRKSRC}/lib ${WRKSRC}/plugins -name '*.so' -delete
	@${FIND} ${WRKSRC}/lib ${WRKSRC}/plugins -type d -empty -delete
	@${RM} -r ${WRKSRC}/plugins/cwm-plugin/quiche-native
	@${RM} -r ${WRKSRC}/plugins/python-ce/helpers/pydev/pydevd_attach_to_process
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${WRKSRC}/lib/pty4j
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
# Install FreeBSD native lib provided by devel/jna
	@${MKDIR} ${WRKDIR}/jna
	@(cd ${WRKDIR}/jna && ${JAR} xf ${JAVAJARDIR}/jna.jar com/sun/jna/freebsd-x86-64/libjnidispatch.so)
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/jna/amd64
	${INSTALL_LIB} ${WRKDIR}/jna/com/sun/jna/freebsd-x86-64/libjnidispatch.so ${STAGEDIR}${DATADIR}/lib/jna/amd64/
# Use pty4j replacement provided by devel/jetbrains-pty4j
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/pty4j/freebsd/x86-64
	${LN} -sf ../../../../../jetbrains/pty4j/amd64/libpty.so ${STAGEDIR}${DATADIR}/lib/pty4j/freebsd/x86-64/libpty.so
# Use sqlite replacement provided by devel/jetbrains-sqlite
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/native/linux-x86_64
	${LN} -sf ../../../../jetbrains/sqlite/amd64/libsqliteij.so ${STAGEDIR}${DATADIR}/lib/native/linux-x86_64/libsqliteij.so

.include <bsd.port.mk>
