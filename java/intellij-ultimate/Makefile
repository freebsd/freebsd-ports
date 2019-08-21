# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

# Based on the java/intellij port

PORTNAME=	intellij-ultimate
PORTVERSION=	2019.2
CATEGORIES=	java devel
MASTER_SITES=	https://download-cf.jetbrains.com/idea/
DISTNAME=	ideaIU-${PORTVERSION}-no-jbr
DIST_SUBDIR=	jetbrains

MAINTAINER=	andoriyu@gmail.com
COMMENT=	IntelliJ IDEA Ultimate Edition

LICENSE=	IntelliJ-Ultimate
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		intellij-pty4j>0:java/intellij-pty4j

USES=		python:run shebangfix

USE_JAVA=	yes
JAVA_VERSION=	1.8+

SHEBANG_FILES=	bin/printenv.py bin/restart.py \
		plugins/spy-js/server/node_modules/node-uuid/benchmark/bench.sh \
		plugins/spy-js/server/proxy-nix.sh \
		plugins/spy-js/server/proxy-osx.sh

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/idea-IU-192.5728.98

SUB_FILES=	idea idea.desktop pkg-message
SUB_LIST=	DATADIR=${DATADIR}
CONFLICTS=	intellij-20*

do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r ${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/fsnotifier-arm \
		${WRKSRC}/bin/fsnotifier64 \
		${WRKSRC}/plugins/android/lib/libwebp \
		${WRKSRC}/plugins/maven/lib/maven3/lib/jansi-native \
		${WRKSRC}/plugins/performanceTesting/bin
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${WRKSRC}/lib/pty4j-native
# Remove bundled linux JetBrains Runtime and OpenJDK
	@${RM} -r ${WRKSRC}/jbr ${WRKSRC}/jre64
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -name *\.so ! -name *\.dll ! -name *\.dylib ! -name *\.pdb ! -name *\.sh")
	@(cd ${WRKSRC} && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR} "-name *\.sh")
	${INSTALL_SCRIPT} ${WRKDIR}/idea ${STAGEDIR}${PREFIX}/bin/idea
	${INSTALL_MAN} ${FILESDIR}/idea.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/idea.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/intellij/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Fix slow render
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/idea.vmoptions
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/idea64.vmoptions

.include <bsd.port.mk>
