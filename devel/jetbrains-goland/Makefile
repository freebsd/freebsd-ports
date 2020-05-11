# $FreeBSD$

PORTNAME=	goland
PORTVERSION=	2020.1.2
CATEGORIES=	devel java
MASTER_SITES=	https://download-cf.jetbrains.com/go/
PKGNAMEPREFIX=	jetbrains-
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	JetBrains GoLand IDE

LICENSE=	IntelliJ-GoLand
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		lsof:sysutils/lsof

USES=		python:run shebangfix

USE_JAVA=	yes
JAVA_VERSION=	8+

SHEBANG_FILES=	bin/printenv.py bin/restart.py

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/GoLand-${PORTVERSION}

SUB_FILES=	goland goland.desktop pkg-message

OPTIONS_DEFINE_amd64=	DELVE
OPTIONS_DEFAULT_amd64=	DELVE

DELVE_DESC=	Debugger for the Go programming language

DELVE_RUN_DEPENDS=	delve>0:devel/delve

do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r ${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/fsnotifier-arm \
		${WRKSRC}/bin/fsnotifier64 \
		${WRKSRC}/lib/pty4j-native \
		${WRKSRC}/plugins/performanceTesting/bin
# Remove bundled linux JetBrains Runtime and OpenJDK
	@${RM} -r ${WRKSRC}/jbr ${WRKSRC}/jre64
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -name *\.so ! -name *\.dll ! -name *\.dylib ! -name *\.pdb ! -name *\.sh")
	@(cd ${WRKSRC} && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR} "-name *\.sh")
	${INSTALL_SCRIPT} ${WRKDIR}/goland ${STAGEDIR}${PREFIX}/bin/goland
	${INSTALL_MAN} ${FILESDIR}/goland.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/goland.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/intellij/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Fix slow render
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/goland.vmoptions
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/goland64.vmoptions

do-install-DELVE-on:
	@${LN} -sf ${PREFIX}/bin/dlv ${STAGEDIR}${DATADIR}/plugins/go/lib/dlv/linux/dlv

.include <bsd.port.mk>
