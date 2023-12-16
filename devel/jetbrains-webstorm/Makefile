PORTNAME=	webstorm
DISTVERSION=	2023.2.5
CATEGORIES=	devel java
MASTER_SITES=	https://download-cdn.jetbrains.com/webstorm/
PKGNAMEPREFIX=	jetbrains-
DISTNAME=	WebStorm-${PORTVERSION}
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	JetBrains JavaScript IDE
WWW=		https://www.jetbrains.com/webstorm/

LICENSE=	IntelliJ-WebStorm
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		jetbrains-pty4j>=0.12.13:devel/jetbrains-pty4j \
		jetbrains-sqlite>=232.8660.185:devel/jetbrains-sqlite \
		lsof:sysutils/lsof

USES=		cpe python:run shebangfix

CPE_VENDOR=	jetbrains
USE_JAVA=	yes
JAVA_VERSION=	17+

SHEBANG_FILES=	bin/restart.py

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}
NO_ARCH=	yes
NO_ARCH_IGNORE=	libjnidispatch.so
NO_BUILD=	yes
SUB_FILES=	${PORTNAME} ${PORTNAME}.desktop pkg-message
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/WebStorm-232.10227.9

do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r \
		${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/remote-dev-server.sh \
		${WRKSRC}/bin/repair \
		${WRKSRC}/jbr \
		${WRKSRC}/lib/jna \
		${WRKSRC}/lib/native \
		${WRKSRC}/lib/pty4j \
		${WRKSRC}/plugins/cwm-plugin \
		${WRKSRC}/plugins/cwm-plugin-projector \
		${WRKSRC}/plugins/gateway-plugin/lib/remote-dev-workers \
		${WRKSRC}/plugins/remote-dev-server \
		${WRKSRC}/plugins/webp/lib/libwebp
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -name *\.bak ! -name *\.so ! -name *\.dll ! -name *\.dylib ! -name *\.pdb ! -name *\.sh ! -name *\.exe")
	@(cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}/bin/ \
		"-name *\.sh -o -name *\.py")
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
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
# Use sqlite replacement provided by devel/jetbrains-sqlite
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/native/linux-x86_64
	${LN} -sf ../../../../sqlite/amd64/libsqliteij.so ${STAGEDIR}${DATADIR}/lib/native/linux-x86_64/libsqliteij.so

.include <bsd.port.mk>
