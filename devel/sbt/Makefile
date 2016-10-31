# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sbt
PORTVERSION=	0.13.13
CATEGORIES=	devel java
MASTER_SITES=	http://dl.bintray.com/sbt/native-packages/sbt/${PORTVERSION}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Build tool for Scala projects

LICENSE=	APACHE20

OPTIONS_DEFINE=	ADVANCED
OPTIONS_DEFAULT=ADVANCED
ADVANCED_DESC=	Install advanced bash shell-script

USES=		tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-launcher-packaging-${PORTVERSION}

PLIST_FILES=	bin/sbt \
		%%DATADIR%%/sbt-launch.jar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MADVANCED}
RUN_DEPENDS=	bash:shells/bash

PLIST_FILES+=	%%DATADIR%%/sbt \
		%%DATADIR%%/sbt-launch-lib.bash
.else
SUB_FILES=	sbt.sh
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/sbt-launch.jar ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MADVANCED}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sbt ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sbt-launch-lib.bash ${STAGEDIR}${DATADIR}
	${LN} -s ${DATADIR}/sbt ${STAGEDIR}${PREFIX}/bin/
.else
	${INSTALL_SCRIPT} ${WRKDIR}/sbt.sh ${STAGEDIR}${PREFIX}/bin/sbt
.endif

.include <bsd.port.mk>
