# Created by: Dusan Vejnovic <freebsd@dussan.org>
# $FreeBSD$

PORTNAME=	sonarqube-ant-task
PORTVERSION=	2.7.0.1612
CATEGORIES=	devel java
MASTER_SITES=	https://binaries.sonarsource.com/Distribution/sonarqube-ant-task/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	SonarQube Plugin for analysis projects with an Apache Ant

LICENSE=	LGPL3

USES=		cpe
USE_JAVA=	yes
CPE_VENDOR=	sonarsource

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RUN_DEPENDS+=	ant:devel/apache-ant \
		sonar-scanner:devel/sonar-scanner-cli

SUB_FILES=	pkg-message
PLIST_FILES=	${DATADIR_REL}/${PORTNAME}${EXTRACT_SUFX}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} \
		${STAGEDIR}${DATADIR}/${PORTNAME}${EXTRACT_SUFX}

.include <bsd.port.mk>
