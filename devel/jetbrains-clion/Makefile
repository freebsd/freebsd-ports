PORTNAME=	clion
DISTVERSION=	2025.1.4
CATEGORIES=	devel
MASTER_SITES=	https://download-cdn.jetbrains.com/cpp/ \
		https://packages.jetbrains.team/files/p/clion/ports/2025.1.4/freebsd/clang/:clang
PKGNAMEPREFIX=	jetbrains-
DISTFILES=	CLion-${PORTVERSION}.tar.gz
DISTFILES_aarch64=	clang-clion2025.1.4-freebsd-aarch64.tar.gz:clang
DISTFILES_amd64=	clang-clion2025.1.4-freebsd-x86_64.tar.gz:clang
DIST_SUBDIR=	jetbrains

.if make(makesum)
DISTFILES+=	${DISTFILES_aarch64} \
		${DISTFILES_amd64}
.else
DISTFILES+=	${DISTFILES_${ARCH}}
.endif

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	JetBrains CLion IDE
WWW=		https://www.jetbrains.com/clion/

LICENSE=	IntelliJ-CLion
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
		lsof:sysutils/lsof \
		ninja:devel/ninja

USES=		cpe java python:run shebangfix

CPE_VENDOR=	jetbrains
JAVA_VERSION=	21+

SHEBANG_FILES=	plugins/python-ce/helpers/typeshed/scripts/generate_proto_stubs.sh

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}

EXTRACT_AFTER_ARGS+=	--exclude clion-*/jbr

NO_BUILD=	yes
SUB_FILES=	${PORTNAME} ${PORTNAME}.desktop pkg-message
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/clion-${PORTVERSION}

_CLANG_ARCH=	linux/${ARCH:S/amd64/x64/}
_PTY4J_ARCH=	freebsd/${ARCH:S/amd64/x86-64/}
_SQLITE_ARCH=	linux-${ARCH:S/amd64/x86_64/}

PLIST_SUB+=	ARCH=${ARCH} \
		CLANG_ARCH=${_CLANG_ARCH} \
		PTY4J_ARCH=${_PTY4J_ARCH} \
		SQLITE_ARCH=${_SQLITE_ARCH}

do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r \
		${WRKSRC}/bin/clang/linux \
		${WRKSRC}/bin/clion \
		${WRKSRC}/bin/cmake/linux \
		${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/gdb/linux \
		${WRKSRC}/bin/lldb/linux \
		${WRKSRC}/bin/ninja \
		${WRKSRC}/bin/remote-dev-server \
		${WRKSRC}/bin/remote-dev-server.sh \
		${WRKSRC}/bin/repair \
		${WRKSRC}/bin/restarter \
		${WRKSRC}/lib/async-profiler \
		${WRKSRC}/lib/jna \
		${WRKSRC}/lib/native \
		${WRKSRC}/lib/pty4j \
		${WRKSRC}/lib/skiko-awt-runtime-all \
		${WRKSRC}/plugins/cidr-completionMlRanking-plugin \
		${WRKSRC}/plugins/clion-cwm-plugin \
		${WRKSRC}/plugins/clion-radler \
		${WRKSRC}/plugins/gateway-plugin/lib/remote-dev-workers \
		${WRKSRC}/plugins/python-ce/helpers/testResources/data/generator3 \
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
# Install FreeBSD native clang
	${MKDIR} ${STAGEDIR}${DATADIR}/bin/clang/${_CLANG_ARCH}/bin
	${INSTALL_PROGRAM} \
			${WRKDIR}/bin/clang-format \
			${WRKDIR}/bin/clang-tidy \
			${WRKDIR}/bin/clangd \
			${WRKDIR}/bin/clazy-standalone \
			${WRKDIR}/bin/llvm-symbolizer \
		${STAGEDIR}${DATADIR}/bin/clang/${_CLANG_ARCH}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}/bin/clang/${_CLANG_ARCH}/lib
	${INSTALL_LIB} ${WRKDIR}/lib/libclazyPlugin.so ${STAGEDIR}${DATADIR}/bin/clang/${_CLANG_ARCH}/lib/

.include <bsd.port.mk>
