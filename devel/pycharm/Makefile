PORTNAME=	pycharm
DISTVERSION=	2025.2.2
CATEGORIES=	devel java python
MASTER_SITES=	https://download.jetbrains.com/python/
DIST_SUBDIR=	jetbrains

MAINTAINER=	rm@FreeBSD.org
COMMENT=	JetBrains PyCharm IDE
WWW=		https://www.jetbrains.com/pycharm/

LICENSE=	PyCharm-Professional
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	no-dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		jetbrains-pty4j>=0.12.13:devel/jetbrains-pty4j \
		jetbrains-restarter>=233.11799.241:devel/jetbrains-restarter \
		jetbrains-sqlite>=232.8660.185:devel/jetbrains-sqlite

USES=		cpe desktop-file-utils java python:run shebangfix
SHEBANG_FILES=	plugins/python-ce/helpers/pycodestyle.py \
		plugins/python-ce/helpers/pycodestyle-2.10.0.py \
		plugins/python-ce/helpers/py3only/docutils/utils/math/math2html.py \
		plugins/python-ce/helpers/py3only/docutils/utils/smartquotes.py \
		plugins/python-ce/helpers/py3only/docutils/writers/odf_odt/prepstyles.py \
		plugins/python-ce/helpers/typeshed/scripts/generate_proto_stubs.sh \
		plugins/python-ce/helpers/typeshed/scripts/sync_s2clientprotocol_protobuf_stubs.sh \
		plugins/python-ce/helpers/typeshed/scripts/sync_tensorflow_protobuf_stubs.sh

ONLY_FOR_ARCH=	amd64
CPE_VENDOR=	jetbrains
JAVA_VERSION=	21+

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}

# Ignore:
# - non-native binaries
# - the bundled native Pty4J support libraries, they are replaced by java/jetbrains-pty4j
# - bundled linux-only JRE
EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/bin/fsnotifier \
			--exclude ${DISTNAME}/bin/restarter \
			--exclude ${DISTNAME}/bin/pycharm \
			--exclude ${DISTNAME}/plugins/cwm-plugin/quiche-native \
			--exclude ${DISTNAME}/plugins/python-ce/helpers/pydev/pydevd_attach_to_process \
			--exclude ${DISTNAME}/lib/pty4j \
			--exclude ${DISTNAME}/lib/skiko-awt-runtime-all \
			--exclude ${DISTNAME}/jbr \
			--no-same-owner --no-same-permissions

NO_BUILD=	yes

.include "${.CURDIR}/../../java/intellij/common.mk"

SUB_FILES+=	pkg-message pycharm ${PORTNAME}.desktop
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}

# Remove non-native binaries
post-extract:
	@${FIND} ${WRKSRC}/lib ${WRKSRC}/plugins -type d -empty -delete
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
	${LN} -sf ../../../../../pty4j/amd64/libpty.so ${STAGEDIR}${DATADIR}/lib/pty4j/freebsd/x86-64/libpty.so
# Use restarter provided by devel/jetbrains-restarter
	${LN} -sf ../../restarter/restarter ${STAGEDIR}${DATADIR}/bin/restarter
# Use sqlite replacement provided by devel/jetbrains-sqlite
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/native/linux-x86_64
	${LN} -sf ../../../../sqlite/amd64/libsqliteij.so ${STAGEDIR}${DATADIR}/lib/native/linux-x86_64/libsqliteij.so
# Fix "Typeahead timeout is exceeded" error
	${ECHO} "action.aware.typeAhead=false" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Fix slow render
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/idea.vmoptions
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/idea64.vmoptions

.include <bsd.port.mk>
