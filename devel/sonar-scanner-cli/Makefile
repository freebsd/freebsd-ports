# Created by: Dusan Vejnovic <freebsd@dussan.org>
# $FreeBSD$

PORTNAME=	sonar-scanner-cli
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	https://sonarsource.bintray.com/Distribution/${PORTNAME}/
DISTNAME=	sonar-scanner-${PORTVERSION}

MAINTAINER=	freebsd@dussan.org
COMMENT=	Launcher for analyzing projects with SonarQube

BROKEN=		unfetchable

LICENSE=	LGPL3

NO_ARCH=	yes
NO_BUILD=	yes

USES=		cpe zip
CPE_VENDOR=	sonarsource

USE_JAVA=	yes
JAVA_VERSION=	1.7+

SR=		sonar-runner
SQ_CLI=		sonar-scanner
SQ_ARCH=	x86-${ARCH:S/i386/32/:S/amd64/64/}
SQ=		${PREFIX}/sonarqube/bin/freebsd-${SQ_ARCH}

SUB_FILES=	pkg-message
PLIST_SUB=	SR_HOME=${PREFIX}/${PORTNAME}

OPTIONS_DEFINE=	SQ
SQ_DESC=	SonarQube server support
SQ_RUN_DEPENDS=	${SQ}/sonar.sh.sample:devel/sonarqube

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PORTNAME})
	@${MV} -f ${STAGEDIR}${PREFIX}/${PORTNAME}/conf/${SQ_CLI}.properties \
	 ${STAGEDIR}${PREFIX}/${PORTNAME}/conf/${SQ_CLI}.properties.sample

post-install:
	@${LN} -f ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/${SR} \
	 ${STAGEDIR}${PREFIX}/bin/${SR}
	@${LN} -f ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/${SQ_CLI} \
	 ${STAGEDIR}${PREFIX}/bin/${SQ_CLI}

.include <bsd.port.mk>
