# Created by: Pedro Giffuni <pfg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phpstorm
PORTVERSION=	2019.3.1
CATEGORIES=	devel java
MASTER_SITES=	https://download-cf.jetbrains.com/webide/
PKGNAMEPREFIX=	jetbrains-
DISTNAME=	PhpStorm-${PORTVERSION}
DIST_SUBDIR=	jetbrains

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	JetBrains PhpStorm IDE

LICENSE=	IntelliJ-PhpStorm
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier

USES=		python:run shebangfix

USE_JAVA=	yes
JAVA_VERSION=	8+

SHEBANG_FILES=	bin/printenv.py bin/restart.py

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/PhpStorm-193.5662.63

SUB_FILES=	phpstorm phpstorm.desktop pkg-message

do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r ${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/fsnotifier-arm \
		${WRKSRC}/bin/fsnotifier64 \
		${WRKSRC}/jbr \
		${WRKSRC}/lib/pty4j-native \
		${WRKSRC}/plugins/performanceTesting/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -name *\.so ! -name *\.dll ! -name *\.dylib ! -name *\.pdb ! -name *\.sh")
	@(cd ${WRKSRC} && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR} "-name *\.sh")
	${INSTALL_SCRIPT} ${WRKDIR}/phpstorm ${STAGEDIR}${PREFIX}/bin/phpstorm
	${INSTALL_MAN} ${FILESDIR}/phpstorm.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/phpstorm.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/intellij/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Fix slow render
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/phpstorm.vmoptions
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/phpstorm64.vmoptions

.include <bsd.port.mk>
