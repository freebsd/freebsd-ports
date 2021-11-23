PORTNAME=	datagrip
PORTVERSION=	2021.3.1
CATEGORIES=	databases java
MASTER_SITES=	https://download-cf.jetbrains.com/datagrip/
PKGNAMEPREFIX=	jetbrains-
DIST_SUBDIR=	jetbrains

MAINTAINER=	dch@FreeBSD.org
COMMENT=	JetBrains DataGrip IDE for your Databases

LICENSE=	IntelliJ-datagrip
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		lsof:sysutils/lsof

USES=		python:run shebangfix

USE_JAVA=	yes
JAVA_VERSION=	11+

USE_LDCONFIG=	yes

SHEBANG_FILES=	bin/printenv.py bin/restart.py

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	${PORTNAME} ${PORTNAME}.desktop pkg-message

WRKSRC=		${WRKDIR}/DataGrip-${PORTVERSION}

do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r \
		${WRKSRC}/bin/clang \
		${WRKSRC}/bin/cmake \
		${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/fsnotifier-arm \
		${WRKSRC}/bin/fsnotifier64 \
		${WRKSRC}/bin/gdb/linux \
		${WRKSRC}/bin/lldb/linux \
		${WRKSRC}/jbr \
		${WRKSRC}/jre64 \
		${WRKSRC}/lib/pty4j-native \
		${WRKSRC}/plugins/cwm-plugin/quiche-native \
		${WRKSRC}/plugins/performanceTesting/bin
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
