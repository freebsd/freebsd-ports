# New ports collection makefile for:	jgnash
# Date created:		2009-12-27
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	jgnash
PORTVERSION=	2.8.0
CATEGORIES=	finance java
MASTER_SITES=	SF/jgnash/Active%20Stable%202.x/2.8.x%20Releases
DISTNAME=	jgnash2-${PORTVERSION}-bin

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A free personal finance manager

WRKSRC=		${WRKDIR}/jgnash2-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	jgnash2.desktop
SUB_LIST=	JAVA="${JAVA}"
PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_VENDOR=	openjdk

NO_BUILD=	yes

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} ${WRKSRC}/jgnash2.jar ${DATADIR}
	@${CP} -R ${WRKSRC}/lib ${DATADIR}
	@${MKDIR} ${DESKTOPDIR}
	@${CP} ${WRKDIR}/jgnash2.desktop ${DESKTOPDIR}

.include <bsd.port.mk>
