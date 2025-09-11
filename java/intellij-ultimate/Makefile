PORTNAME=	intellij-ultimate
DISTVERSION=	2025.2.1
CATEGORIES=	java devel
MASTER_SITES=	https://download-cdn.jetbrains.com/idea/
DISTNAME=	ideaIU-${DISTVERSION}
DIST_SUBDIR=	jetbrains

MAINTAINER=	andoriyu@gmail.com
COMMENT=	IntelliJ IDEA Ultimate Edition
WWW=		https://www.jetbrains.com/idea/

LICENSE=	IntelliJ-Ultimate
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		jetbrains-pty4j>=0.12.26:devel/jetbrains-pty4j \
		jetbrains-sqlite>=241.15989.150:devel/jetbrains-sqlite \
		lsof:sysutils/lsof

USES=		java
JAVA_VERSION=	17+

CONFLICTS=	idea intellij

NO_BUILD=	yes
SUB_FILES=	idea idea.desktop pkg-message

BUILD_TYPE=	IU
BUILD_VERSION=	252.25557.131
BUILD_MARKER=	${BUILD_TYPE}-${BUILD_VERSION}
PLIST_SUB=	BUILD_MARKER=${BUILD_MARKER}
WRKSRC=		${WRKDIR}/idea-${BUILD_MARKER}

post-patch:
# Linux/Windows/OS X only so remove them
	@${RM} -r \
		${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/idea \
		${WRKSRC}/bin/remote-dev-server \
		${WRKSRC}/bin/remote-dev-server.sh \
		${WRKSRC}/bin/restarter \
		${WRKSRC}/help/plugin-resources \
		${WRKSRC}/jbr/ \
		${WRKSRC}/lib/async-profiler/ \
		${WRKSRC}/lib/jna/ \
		${WRKSRC}/lib/native/ \
		${WRKSRC}/lib/pty4j/ \
		${WRKSRC}/lib/skiko-awt-runtime-all \
		${WRKSRC}/plugins/clouds-docker-gateway \
		${WRKSRC}/plugins/clouds-docker-impl \
		${WRKSRC}/plugins/cwm-plugin \
		${WRKSRC}/plugins/gateway-plugin \
		${WRKSRC}/plugins/gateway-terminal \
		${WRKSRC}/plugins/llmInstaller/video/Idea/.DS_Store \
		${WRKSRC}/plugins/maven/lib/maven3/lib/jansi-native/ \
		${WRKSRC}/plugins/maven/lib/maven4-server-lib \
		${WRKSRC}/plugins/remote-dev-server/ \
		${WRKSRC}/plugins/station-plugin/toolbox/ \
		${WRKSRC}/plugins/webp/lib/libwebp/

	@${SED} -i '' 's,/amd64,,' ${WRKSRC}/bin/idea.sh ${WRKSRC}/product-info.json
	@${SED} -i '' 's/amd64/${ARCH}/' ${WRKSRC}/product-info.json

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
JNI_ARCH=	x86-64
.elif ${ARCH} == "powerpc64le"
JNI_ARCH=	ppc64le
.else
JNI_ARCH=	${ARCH}
.endif
PLIST_SUB+=	JNI_ARCH=${JNI_ARCH}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -name *\.orig ! -name *\.bak ! -name *\.so ! -name *\.dll ! -name *\.dylib ! -name *\.pdb ! -name *\.sh")
	@(cd ${WRKSRC} && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR} "-name *\.sh")
	${INSTALL_SCRIPT} ${WRKDIR}/idea ${STAGEDIR}${PREFIX}/bin/idea
	${INSTALL_MAN} ${FILESDIR}/idea.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKDIR}/idea.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Install FreeBSD native lib provided by devel/jna
	@${MKDIR} ${WRKDIR}/jna
	@(cd ${WRKDIR}/jna && ${JAR} xf ${JAVAJARDIR}/jna.jar com/sun/jna/freebsd-${JNI_ARCH}/libjnidispatch.so)
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/jna
	${INSTALL_LIB} ${WRKDIR}/jna/com/sun/jna/freebsd-${JNI_ARCH}/libjnidispatch.so ${STAGEDIR}${DATADIR}/lib/jna/
# Use pty4j replacement provided by java/intellij-pty4j
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/pty4j/freebsd/${JNI_ARCH}
	${LN} -sf ../../../../../jetbrains/pty4j/${ARCH}/libpty.so ${STAGEDIR}${DATADIR}/lib/pty4j/freebsd/${JNI_ARCH}/
# Use sqlite replacement provided by devel/jetbrains-sqlite
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/native/linux-${JNI_ARCH}
	${LN} -sf ../../../../jetbrains/sqlite/${ARCH}/libsqliteij.so ${STAGEDIR}${DATADIR}/lib/native/linux-${JNI_ARCH}/libsqliteij.so
# Fix "Cannot create SvgCacheManager" error
	${ECHO} "idea.ui.icons.svg.disk.cache=false" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Disable IDE auto updates
	${ECHO} "ide.no.platform.update=FreeBSD Ports" >> ${STAGEDIR}${DATADIR}/bin/idea.properties

.include <bsd.port.post.mk>
