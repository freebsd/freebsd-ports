# Created by: Stefan Wendler <stefan.wendler@tngtech.com>

PORTNAME=	rubymine
PORTVERSION=	2021.3.1
CATEGORIES=	java devel
MASTER_SITES=	https://download.jetbrains.com/ruby/ \
		http://download.jetbrains.com/ruby/
PKGNAMEPREFIX=	intellij-
DISTNAME=	RubyMine-${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Ruby on Rails IDE by JetBrains

LICENSE=	IntelliJ-Rubymine
LICENSE_NAME=	Subscription license agreement for business and organizations
LICENSE_TEXT=	See: https://www.jetbrains.com/store/license.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier

USES=		python:run shebangfix ssl

USE_JAVA=	yes
JAVA_VERSION=	11+

SHEBANG_FILES=	bin/printenv.py bin/restart.py

NO_BUILD=	yes

WRKDIST=	${WRKDIR}/RubyMine-${PORTVERSION}

.include "${.CURDIR}/../intellij/common.mk"

PLIST_SUB+=	DATADIR=${DATADIR}
SUB_FILES+=	rubymine rubymine.desktop pkg-message
SUB_LIST+=	DATADIR=${DATADIR}
do-install:
# Linux/Windows/OS X only so remove them
	@${RM} -r ${WRKSRC}/bin/fsnotifier \
		${WRKSRC}/lib/pty4j-native/ \
		${WRKSRC}/bin/lib*.so
	${MKDIR} ${STAGEDIR}${DATADIR}
	@${TAR} -czf - -C ${WRKDIST} . | ${TAR} xzf - -C ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/rubymine ${STAGEDIR}${PREFIX}/bin/rubymine
	${INSTALL_MAN} ${FILESDIR}/rubymine.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/rubymine.desktop ${STAGEDIR}${PREFIX}/share/applications/
# Use fsnotifier replacement provided by java/intellij-fsnotifier
	${ECHO} "idea.filewatcher.executable.path=${DATADIR}/bin/fsnotifier" >> ${STAGEDIR}${DATADIR}/bin/idea.properties

.include <bsd.port.mk>
