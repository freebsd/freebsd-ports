PORTNAME=	bfg
PORTVERSION=	1.14.0
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/madgag/${PORTNAME}/${DISTVERSION}/
EXTRACT_SUFX=	.jar

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Removes large or troublesome blobs like git-filter-branch does

LICENSE=	GPLv3

USE_JAVA=	yes
JAVA_RUN=	jre

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	bfg
SUB_LIST=	JAVA=${JAVA} \
		DATADIR=${DATADIR} \
		DISTNAME=${DISTNAME}

PLIST_FILES=	bin/bfg \
		${DATADIR}/${DISTNAME}.jar

do-extract:
	@${DO_NADA}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/bfg ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
