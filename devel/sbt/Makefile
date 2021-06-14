# Created by: Alex Dupre <ale@FreeBSD.org>

PORTNAME=	sbt
PORTVERSION=	1.5.4
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/sbt/sbt/releases/download/v${PORTVERSION}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Build tool for Scala projects

LICENSE=	APACHE20

USES=		tar:tgz

OPTIONS_DEFINE=	ADVANCED # PRELOADED
OPTIONS_DEFAULT=ADVANCED
ADVANCED_DESC=	Install advanced bash shell-script (required for Java 11+)
#PRELOADED_DESC=	Install preloaded jars for offline usage

NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

ADVANCED_RUN_DEPENDS+=	bash:shells/bash
#PRELOADED_RUN_DEPENDS+=	rsync:net/rsync

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
	${MKDIR} ${STAGEDIR}${DATADIR}/conf
	${INSTALL_DATA} ${FILESDIR}/sbtopts ${STAGEDIR}${DATADIR}/conf
#.if ${PORT_OPTIONS:MPRELOADED}
#	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} local-preloaded ${STAGEDIR}${DATADIR}
#.endif
	${LN} -s ../${DATADIR_REL}/sbt ${STAGEDIR}${PREFIX}/bin/
.else
	${INSTALL_SCRIPT} ${WRKDIR}/sbt.sh ${STAGEDIR}${PREFIX}/bin/sbt
.endif

.include <bsd.port.mk>
