# Created by: Stefan Wendler <stefan.wendler@tngtech.com>
# $FreeBSD$

PORTNAME=	rubymine
PORTVERSION=	2020.3.2
CATEGORIES=	java devel
MASTER_SITES=	https://download.jetbrains.com/ruby/ \
		http://download.jetbrains.com/ruby/
PKGNAMEPREFIX=	intellij-
DISTNAME=	RubyMine-${PORTVERSION}

MAINTAINER=	rene@freeBSD.org
COMMENT=	Ruby on Rails IDE by JetBrains

LICENSE=	IntelliJ-Rubymine
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier

USES=		python:run shebangfix

USE_JAVA=	yes
JAVA_VERSION=	11+

SHEBANG_FILES=	bin/printenv.py bin/restart.py

NO_ARCH=	yes
NO_BUILD=	yes

WRKDIST=	${WRKDIR}/RubyMine-${PORTVERSION}

.include "${.CURDIR}/../intellij/common.mk"

PLIST_SUB+=	DATADIR=${DATADIR}
SUB_FILES+=	rubymine rubymine.desktop pkg-message
SUB_LIST+=	DATADIR=${DATADIR}
do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r ${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/bin/fsnotifier-arm \
		${WRKSRC}/bin/fsnotifier64 \
		${WRKSRC}/lib/pty4j-native/ \
		${WRKSRC}/bin/lib*.so \
		${WRKSRC}/bin/libyjpagent-linux*.so \
		${WRKSRC}/jbr
	@${RM} ${WRKSRC}/plugins/performanceTesting/lib/lib*.so
	${MKDIR} ${STAGEDIR}${DATADIR}
	@${TAR} -czf - -C ${WRKDIST} . | ${TAR} xzf - -C ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/rubymine ${STAGEDIR}${PREFIX}/bin/rubymine
	${INSTALL_MAN} ${FILESDIR}/rubymine.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/rubymine.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKDIST}/lib && ${JAVA_HOME}/bin/jar xf icons.jar
	${INSTALL_DATA} ${WRKDIST}/lib/icon.png ${STAGEDIR}${DATADIR}/rubymine.png
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${DATADIR}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties
# Fix "Typeahead timeout is exceeded" error
	${ECHO} "action.aware.typeAhead=false" >> ${STAGEDIR}${DATADIR}/bin/rubymine.properties
# Fix slow render
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/rubymine.vmoptions
	${ECHO} "-Dsun.java2d.xrender=false" >> ${STAGEDIR}${DATADIR}/bin/rubymine64.vmoptions

.include <bsd.port.mk>
