# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sbt
PORTVERSION=	1.0.1
CATEGORIES=	devel java
MASTER_SITES=	https://cocl.us/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Build tool for Scala projects

LICENSE=	APACHE20

OPTIONS_DEFINE=	ADVANCED PRELOADED
OPTIONS_DEFAULT=ADVANCED
ADVANCED_DESC=	Install advanced bash shell-script
PRELOADED_DESC=	Install preloaded jars for offline usage

USES=		tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

ADVANCED_RUN_DEPENDS+=	bash:shells/bash
PRELOADED_RUN_DEPENDS+=	rsync:net/rsync

ADVANCED_SUB_FILES_OFF=	sbt.sh

PLIST_FILES=	bin/sbt

PORTDATA=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/bin/sbt

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/sbt-launch.jar ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MADVANCED}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sbt ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sbt-launch-lib.bash ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MPRELOADED}
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} local-preloaded ${STAGEDIR}${DATADIR}
.endif
	${LN} -s ../${DATADIR_REL}/sbt ${STAGEDIR}${PREFIX}/bin/
.else
	${INSTALL_DATA} ${WRKSRC}/bin/sbt-launch.jar ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/sbt.sh ${STAGEDIR}${PREFIX}/bin/sbt
.endif

.include <bsd.port.mk>
