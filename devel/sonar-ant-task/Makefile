# Created by: Dusan Vejnovic <freebsd@dussan.org>
# $FreeBSD$

PORTNAME=	sonar-ant-task
PORTVERSION=	2.5
CATEGORIES=	devel java
MASTER_SITES=	https://sonarsource.bintray.com/Distribution/sonarqube-ant-task/ \
			LOCAL/ler/sonar-ant-task
DISTNAME=	sonarqube-ant-task-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	freebsd@dussan.org
COMMENT=	SonarQube Plugin for analysis projects with an Apache Ant

LICENSE=	LGPL3

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RUN_DEPENDS+=	ant:devel/apache-ant

USES=		cpe
CPE_VENDOR=	sonarsource

USE_JAVA=	yes

SUB_FILES=	pkg-message
PLIST_FILES=	${DATADIR_REL}/sonar-ant-task.jar

OPTIONS_DEFINE=	SQ
SQ_DESC=	SonarQube server support
SQ_RUN_DEPENDS=	sonarqube>=0:devel/sonarqube

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} \
		${STAGEDIR}${DATADIR}/${PORTNAME}${EXTRACT_SUFX}

.include <bsd.port.mk>
