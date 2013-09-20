# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	jgnash
PORTVERSION=	2.10.0
CATEGORIES=	finance java
MASTER_SITES=	SF/jgnash/Active%20Stable%202.x
DISTNAME=	jgnash-${PORTVERSION}-bin

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A free personal finance manager

WRKSRC=		${WRKDIR}/jgnash-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	jgnash.desktop
SUB_LIST=	JAVA="${JAVA}"
PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_VENDOR=	openjdk

NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	@${MKDIR} ${DATADIR}
	@${CP} ${WRKSRC}/jgnash2.jar ${DATADIR}
	@${CP} -R ${WRKSRC}/lib ${DATADIR}
	@${MKDIR} ${DESKTOPDIR}
	@${CP} ${WRKDIR}/jgnash.desktop ${DESKTOPDIR}

.include <bsd.port.mk>
