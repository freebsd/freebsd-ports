# $FreeBSD$

PORTNAME=	pycharm-pro
PORTVERSION=	2020.3.4
CATEGORIES=	devel java python
MASTER_SITES=	https://download.jetbrains.com/python/ \
		http://download.jetbrains.com/python/
DISTNAME=	pycharm-professional-${PORTVERSION}

MAINTAINER=	guido@kollerie.com
COMMENT=	JetBrains PyCharm Professional Edition IDE

LICENSE=	PyCharm-Professional
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	no-dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		intellij-pty4j>=0.11.4:java/intellij-pty4j \
		openjfx14>=0:java/openjfx14

USES=		python:run shebangfix

SHEBANG_FILES=	bin/printenv.py bin/restart.py

USE_JAVA=	yes
JAVA_VERSION=	11+

WRKSRC=		${WRKDIR}/pycharm-${PORTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

.include "${.CURDIR}/../../java/intellij/common.mk"

SUB_FILES+=	pkg-message pycharm ${PORTNAME}.desktop
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${TAR} -czf - -C ${WRKSRC} . | ${TAR} xzf - -C ${STAGEDIR}${DATADIR}
# Linux/Windows/OS X only so remove them
	@${RM} ${STAGEDIR}${DATADIR}/bin/*fsnotifier* ${STAGEDIR}${DATADIR}/bin/*.so
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${STAGEDIR}${DATADIR}/lib/pty4j-native
# Remove bundled linux-only JRE
	@${RM} -r ${STAGEDIR}${DATADIR}/jbr
	@${RM} -r ${STAGEDIR}${DATADIR}/helpers/pydev/pydevd_attach_to_process
	${INSTALL_SCRIPT} ${WRKDIR}/pycharm ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use pty4j replacement provided by java/intellij-pty4j
	${LN} -sf ${IDEA_HOME}/lib/libpty ${STAGEDIR}${DATADIR}/lib/pty4j-native
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${IDEA_HOME}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Fix "Typeahead timeout is exceeded" error
	${ECHO} "action.aware.typeAhead=false" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Fix slow render
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/idea.vmoptions
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/idea64.vmoptions

.include <bsd.port.mk>
