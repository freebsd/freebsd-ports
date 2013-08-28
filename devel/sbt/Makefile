# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sbt
PORTVERSION=	0.13.0
CATEGORIES=	devel java
MASTER_SITES=	http://scalasbt.artifactoryonline.com/scalasbt/sbt-native-packages/org/scala-sbt/sbt/${PORTVERSION}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A build tool for Scala projects

LICENSE=	AL2

OPTIONS_DEFINE=	ADVANCED
ADVANCED_DESC=	Install advanced bash shell-script

NO_BUILD=	yes
USE_JAVA=	yes

PLIST_FILES=	bin/sbt \
		%%DATADIR%%/sbt-launch.jar
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MADVANCED}
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

PLIST_FILES+=	%%DATADIR%%/sbt \
		%%DATADIR%%/sbt-launch-lib.bash
.else
SUB_FILES=	sbt.sh
.endif

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/bin/sbt

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/sbt-launch.jar ${DATADIR}
.if ${PORT_OPTIONS:MADVANCED}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sbt ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sbt-launch-lib.bash ${DATADIR}
	${LN} -s ${DATADIR}/sbt ${PREFIX}/bin/
.else
	${INSTALL_SCRIPT} ${WRKDIR}/sbt.sh ${PREFIX}/bin/sbt
.endif

.include <bsd.port.mk>
