# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	gradle
PORTVERSION=	2.1
CATEGORIES=	devel java
MASTER_SITES=	https://services.gradle.org/distributions/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Project automation tool

LICENSE=	APACHE20

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-bin$$//}
SUB_LIST=	PORTVERSION=${PORTVERSION} \
		JAVA=${JAVA}
SUB_FILES=	gradle

do-install:
	@${ECHO_MSG} -n ">> Installing scripts..."
	${INSTALL_SCRIPT} ${WRKDIR}/gradle ${STAGEDIR}${PREFIX}/bin/gradle
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing data directory 'lib'..."
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
