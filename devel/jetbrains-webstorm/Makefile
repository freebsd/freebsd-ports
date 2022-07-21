PORTNAME=	webstorm
PORTVERSION=	2022.1.3
CATEGORIES=	devel java
MASTER_SITES=	https://download-cdn.jetbrains.com/webstorm/
PKGNAMEPREFIX=	jetbrains-
DISTNAME=	WebStorm-${PORTVERSION}
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	JetBrains JavaScript IDE

LICENSE=	IntelliJ-WebStorm
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		lsof:sysutils/lsof

USES=		cpe python:run shebangfix

USE_JAVA=	yes
JAVA_VERSION=	11+

CPE_VENDOR=	jetbrains

SHEBANG_FILES=	bin/restart.py \
		plugins/spy-js/server/node_modules/node-uuid/benchmark/bench.sh \
		plugins/spy-js/server/proxy-nix.sh \
		plugins/spy-js/server/proxy-osx.sh

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	${PORTNAME} ${PORTNAME}.desktop pkg-message

WRKSRC=		${WRKDIR}/WebStorm-221.5921.27

do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r \
		${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/fsnotifier-arm \
		${WRKSRC}/bin/fsnotifier64 \
		${WRKSRC}/bin/remote-dev-server.sh \
		${WRKSRC}/bin/repair \
		${WRKSRC}/jbr \
		${WRKSRC}/jre64 \
		${WRKSRC}/lib/pty4j-native \
		${WRKSRC}/plugins/cwm-plugin \
		${WRKSRC}/plugins/performanceTesting \
		${WRKSRC}/plugins/remote-dev-server \
		${WRKSRC}/plugins/webp/lib/libwebp
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -name *\.bak ! -name *\.so ! -name *\.dll ! -name *\.dylib ! -name *\.pdb ! -name *\.sh")
	@(cd ${WRKSRC} && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR} "-name *\.sh")
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/intellij/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties

.include <bsd.port.mk>
