PORTNAME=	rustrover
DISTVERSION=	2025.1.5
CATEGORIES=	devel
MASTER_SITES=	https://download-cdn.jetbrains.com/rustrover/
PKGNAMEPREFIX=	jetbrains-
DISTNAME=	RustRover-${PORTVERSION}
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	JetBrains Rust IDE
WWW=		https://www.jetbrains.com/rust/

LICENSE=	IntelliJ-RustRover
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	cmake:devel/cmake-core \
		intellij-fsnotifier>0:java/intellij-fsnotifier \
		jetbrains-pty4j>=0.13.2:devel/jetbrains-pty4j \
		jetbrains-restarter>=241.15989.150:devel/jetbrains-restarter \
		jetbrains-sqlite>=241.15989.150:devel/jetbrains-sqlite \
		lsof:sysutils/lsof

USES=		cpe java python:run

CPE_VENDOR=	jetbrains
JAVA_VERSION=	21+

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}

EXTRACT_AFTER_ARGS+=	--exclude RustRover-*/jbr

NO_BUILD=	yes
SUB_FILES=	${PORTNAME} ${PORTNAME}.desktop pkg-message
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/RustRover-${PORTVERSION}

_PTY4J_ARCH=	freebsd/${ARCH:S/amd64/x86-64/}
_SQLITE_ARCH=	linux-${ARCH:S/amd64/x86_64/}

PLIST_SUB+=	ARCH=${ARCH} \
		PTY4J_ARCH=${_PTY4J_ARCH} \
		SQLITE_ARCH=${_SQLITE_ARCH}

do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r \
		${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/gdb \
		${WRKSRC}/bin/lldb \
		${WRKSRC}/bin/native-helper \
		${WRKSRC}/bin/remote-dev-server \
		${WRKSRC}/bin/remote-dev-server.sh \
		${WRKSRC}/bin/repair \
		${WRKSRC}/bin/restarter \
		${WRKSRC}/bin/rustrover \
		${WRKSRC}/lib/async-profiler \
		${WRKSRC}/lib/jna \
		${WRKSRC}/lib/native \
		${WRKSRC}/lib/pty4j \
		${WRKSRC}/plugins/cwm-plugin \
		${WRKSRC}/plugins/gateway-plugin/lib/remote-dev-workers \
		${WRKSRC}/plugins/intellij-rust/bin \
		${WRKSRC}/plugins/remote-dev-server
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -name *\.bak ! -name *\.so ! -name *\.dll ! -name *\.dylib ! -name *\.pdb ! -name *\.sh ! -name *\.exe")
	@(cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}/bin/ \
		"-name *\.sh -o -name *\.py")
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Install FreeBSD native lib provided by devel/jna
	@${MKDIR} ${WRKDIR}/jna
	@(cd ${WRKDIR}/jna && ${JAR} xf ${JAVAJARDIR}/jna-platform.jar libjnidispatch.so)
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/jna/${ARCH}
	${INSTALL_LIB} ${WRKDIR}/jna/libjnidispatch.so ${STAGEDIR}${DATADIR}/lib/jna/${ARCH}/
# Use pty4j replacement provided by devel/jetbrains-pty4j
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/pty4j/${_PTY4J_ARCH}
	${LN} -sf ../../../../../pty4j/${ARCH}/libpty.so ${STAGEDIR}${DATADIR}/lib/pty4j/${_PTY4J_ARCH}/libpty.so
# Use restarter provided by devel/jetbrains-restarter
	${LN} -sf ../../restarter/restarter ${STAGEDIR}${DATADIR}/bin/restarter
# Use sqlite replacement provided by devel/jetbrains-sqlite
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/native/${_SQLITE_ARCH}
	${LN} -sf ../../../../sqlite/${ARCH}/libsqliteij.so ${STAGEDIR}${DATADIR}/lib/native/${_SQLITE_ARCH}/libsqliteij.so
# Disable automatic updates
	${ECHO} "ide.no.platform.update=FreeBSD Ports" >> ${STAGEDIR}${DATADIR}/bin/idea.properties

.include <bsd.port.mk>
