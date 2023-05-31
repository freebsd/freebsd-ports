PORTNAME=	goland
PORTVERSION=	2023.1.2
CATEGORIES=	devel java
MASTER_SITES=	https://download-cdn.jetbrains.com/go/
PKGNAMEPREFIX=	jetbrains-
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	JetBrains GoLand IDE
WWW=		https://www.jetbrains.com/go/

LICENSE=	IntelliJ-GoLand
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		jetbrains-pty4j>=0.12.10:devel/jetbrains-pty4j \
		lsof:sysutils/lsof

USES=		cpe python:run shebangfix

CPE_VENDOR=	jetbrains
USE_JAVA=	yes
JAVA_VERSION=	17+

SHEBANG_FILES=	bin/restart.py

NO_ARCH=	yes
NO_ARCH_IGNORE=	libjnidispatch.so
NO_BUILD=	yes
SUB_FILES=	${PORTNAME} ${PORTNAME}.desktop pkg-message
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/GoLand-${PORTVERSION}

OPTIONS_DEFINE_amd64=	DELVE
OPTIONS_DEFAULT_amd64=	DELVE

DELVE_DESC=	Debugger for the Go programming language

DELVE_RUN_DEPENDS=	delve>0:devel/delve

do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r \
		${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/remote-dev-server.sh \
		${WRKSRC}/bin/repair \
		${WRKSRC}/jbr \
		${WRKSRC}/lib/native \
		${WRKSRC}/lib/pty4j \
		${WRKSRC}/plugins/cwm-plugin \
		${WRKSRC}/plugins/gateway-plugin/lib/remote-dev-workers \
		${WRKSRC}/plugins/go-plugin/lib/dlv \
		${WRKSRC}/plugins/performanceTesting \
		${WRKSRC}/plugins/performanceTesting-async \
		${WRKSRC}/plugins/performanceTesting-yourkit \
		${WRKSRC}/plugins/remote-dev-server
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -name *\.bak ! -name *\.so ! -name *\.dll ! -name *\.dylib ! -name *\.pdb ! -name *\.sh ! -name *\.exe")
	@(cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}/bin/ \
		"-name *\.sh -o -name *\.py")
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/intellij/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Install FreeBSD native lib provided by devel/jna
	@${MKDIR} ${WRKDIR}/jna
	@(cd ${WRKDIR}/jna && ${JAR} xf ${JAVAJARDIR}/jna.jar com/sun/jna/freebsd-x86-64/libjnidispatch.so)
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/jna/amd64
	${INSTALL_LIB} ${WRKDIR}/jna/com/sun/jna/freebsd-x86-64/libjnidispatch.so ${STAGEDIR}${DATADIR}/lib/jna/amd64/
# Use pty4j replacement provided by devel/jetbrains-pty4j
	${LN} -sf ../../../lib/pty4j ${STAGEDIR}${DATADIR}/lib/pty4j

do-install-DELVE-on:
	${ECHO} "dlv.path=${PREFIX}/bin/dlv" >> ${STAGEDIR}${DATADIR}/bin/idea.properties

.include <bsd.port.mk>
