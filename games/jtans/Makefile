# Created by: ijliao
# $FreeBSD$

PORTNAME=	jtans
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_appli-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ancient puzzle

LICENSE=	GPLv2+ # got from website

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
SUB_FILES=	jtans.sh
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jtans.sh ${STAGEDIR}${PREFIX}/bin/jtans
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jtans_appli-1.0.jar ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
