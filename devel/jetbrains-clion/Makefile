PORTNAME=	clion
PORTVERSION=	2023.3.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://download-cdn.jetbrains.com/cpp/ \
		https://packages.jetbrains.team/files/p/clion/ports/2023.3/freebsd/clang/:clang
PKGNAMEPREFIX=	jetbrains-
DISTFILES=	CLion-${PORTVERSION}.tar.gz
DISTFILES_aarch64=	clang-clion2023.3-freebsd-aarch64.tar.gz:clang
DISTFILES_amd64=	clang-clion2023.3-freebsd-x86_64.tar.gz:clang
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
		jetbrains-pty4j>=0.12.25:devel/jetbrains-pty4j \
		jetbrains-restarter>=233.14015.106:devel/jetbrains-restarter \
		jetbrains-sqlite>=233.14015.106:devel/jetbrains-sqlite \
		lsof:sysutils/lsof \
		ninja:devel/ninja

USES=		cpe python:run shebangfix

CPE_VENDOR=	jetbrains
USE_JAVA=	yes
JAVA_VERSION=	17+

SHEBANG_FILES=	plugins/python-ce/helpers/typeshed/scripts/generate_proto_stubs.sh

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	${PORTNAME} ${PORTNAME}.desktop pkg-message
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/clion-${PORTVERSION}

CLANG_ARCH=	${ARCH:S/amd64/x64/}
PLIST_SUB+=	CLANG_ARCH=${CLANG_ARCH}

do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r \
		${WRKSRC}/bin/clang/linux \
		${WRKSRC}/bin/cmake/linux \
		${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/gdb/linux \
		${WRKSRC}/bin/lldb/linux \
		${WRKSRC}/bin/ninja \
		${WRKSRC}/bin/remote-dev-server.sh \
		${WRKSRC}/bin/repair \
		${WRKSRC}/bin/restarter \
		${WRKSRC}/jbr \
		${WRKSRC}/lib/async-profiler \
		${WRKSRC}/lib/jna \
		${WRKSRC}/lib/native \
		${WRKSRC}/lib/pty4j \
		${WRKSRC}/plugins/cwm-plugin \
		${WRKSRC}/plugins/gateway-plugin \
		${WRKSRC}/plugins/remote-dev-server
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -name *\.bak ! -name *\.so ! -name *\.dll ! -name *\.dylib ! -name *\.pdb ! -name *\.sh ! -name *\.exe")
	@(cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}/bin/ \
		"-name *\.sh -o -name *\.py")
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
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
# Install FreeBSD native clang
	${MKDIR} ${STAGEDIR}${DATADIR}/bin/clang/linux/${CLANG_ARCH}/
	${INSTALL_PROGRAM} \
		${WRKDIR}/clang-tidy \
		${WRKDIR}/clangd \
		${WRKDIR}/clazy-standalone \
		${WRKDIR}/llvm-symbolizer \
	${STAGEDIR}${DATADIR}/bin/clang/linux/${CLANG_ARCH}/
	${INSTALL_LIB} ${WRKDIR}/libclazyPlugin.so ${STAGEDIR}${DATADIR}/bin/clang/linux/${CLANG_ARCH}/
	${CP} -Rp ${WRKDIR}/include ${STAGEDIR}${DATADIR}/bin/clang/linux/${CLANG_ARCH}/

.include <bsd.port.mk>
