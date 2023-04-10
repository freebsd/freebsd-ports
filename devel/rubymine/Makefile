PORTNAME=	rubymine
PORTVERSION=	2023.1
CATEGORIES=	devel java
MASTER_SITES=	https://download.jetbrains.com/ruby/
DISTNAME=	RubyMine-${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Ruby on Rails IDE by JetBrains
WWW=		https://www.jetbrains.com/ruby/

LICENSE=	IntelliJ-Rubymine
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier

USES=		cpe python:run shebangfix
CPE_VENDOR=	jetbrains

USE_JAVA=	yes
JAVA_VERSION=	11+

SHEBANG_FILES=	bin/restart.py

NO_BUILD=	yes

WRKDIST=	${WRKDIR}/RubyMine-${PORTVERSION}

.include "${.CURDIR}/../../java/intellij/common.mk"

PLIST_SUB+=	DATADIR=${DATADIR}
SUB_FILES+=	pkg-message rubymine rubymine.desktop
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}
do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r ${WRKSRC}/bin/*fsnotifier* \
		${WRKSRC}/bin/remote-dev-server.sh \
		${WRKSRC}/bin/repair \
		${WRKSRC}/jbr/ \
		${WRKSRC}/lib/pty4j-native/ \
		${WRKSRC}/lib/async-profiler-windows.jar \
		${WRKSRC}/plugins/cwm-plugin/ \
		${WRKSRC}/plugins/cwm-plugin-projector/ \
		${WRKSRC}/plugins/gateway-plugin/lib/remote-dev-workers/ \
		${WRKSRC}/plugins/remote-dev-server/
	${MKDIR} ${STAGEDIR}${DATADIR}
	@${TAR} -czf - -C ${WRKDIST} . | ${TAR} xzf - -C ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/rubymine ${STAGEDIR}${PREFIX}/bin/rubymine
	${INSTALL_MAN} ${FILESDIR}/rubymine.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/rubymine.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${IDEA_HOME}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties

.include <bsd.port.mk>
