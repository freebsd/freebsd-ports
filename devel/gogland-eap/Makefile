# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gogland-eap
PORTVERSION=	172.3757.46
CATEGORIES=	devel java
MASTER_SITES=	https://download.jetbrains.com/go/ \
		http://download.jetbrains.com/go/
DISTNAME=	gogland-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	JetBrains Gogland IDE (Preview Edition)

LICENSE=	APACHE20

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier \
		intellij-pty4j>0:java/intellij-pty4j

USES=		python:run shebangfix
SHEBANG_FILES=	bin/printenv.py bin/restart.py
USE_JAVA=	yes
JAVA_VERSION=	1.7+

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Gogland-${PORTVERSION}

.include "${.CURDIR}/../../java/intellij/common.mk"

SUB_FILES+=	pkg-message gogland ${PORTNAME}.desktop
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${TAR} -czf - -C ${WRKSRC} . | ${TAR} xzf - -C ${STAGEDIR}${DATADIR}
# Linux/Windows/OS X only so remove them
	@${RM} ${STAGEDIR}${DATADIR}/bin/fsnotifier* \
		${STAGEDIR}${DATADIR}/bin/*-linux*
# Remove the bundled native Pty4J support libraries, they are replaced
# by java/intellij-pty4j
	@${RM} -r ${STAGEDIR}${DATADIR}/lib/libpty
# Remove bundled linux-only JRE
	@${RM} -r ${STAGEDIR}${DATADIR}/jre64
	@${RM} -r ${STAGEDIR}${DATADIR}/helpers/pydev/pydevd_attach_to_process
	@${RM} ${STAGEDIR}${DATADIR}/lib/pty4j-*.jar
	${INSTALL_SCRIPT} ${WRKDIR}/gogland ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
# TODO: Remove and enable fsnotifier when devel/libinotify is fixed
# Disable filewatcher warning message on IDEA startup
	${ECHO} "idea.filewatcher.disabled=true" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${IDEA_HOME}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties

.include <bsd.port.mk>
