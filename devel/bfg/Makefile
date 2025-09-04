PORTNAME=	bfg
PORTVERSION=	1.15.0
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/madgag/${PORTNAME}/${DISTVERSION}/
EXTRACT_SUFX=	.jar

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Removes large or troublesome blobs like git-filter-branch does
WWW=		https://rtyley.github.io/bfg-repo-cleaner/

LICENSE=	GPLv3

USES=		java
JAVA_VERSION=	11+

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
