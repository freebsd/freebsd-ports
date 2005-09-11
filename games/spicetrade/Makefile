# New ports collection makefile for:	spicetrade
# Date created:				2005-09-09
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	spicetrade
PORTVERSION=	1.2
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Spicetrade-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	daniel@roe.ch
COMMENT=	Colourful 14th century Arab spice trading game

USE_JAVA=	1.4+
USE_X_PREFIX=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	JARFILE="${DATADIR}/${DISTFILES}"

PLIST_FILES=	bin/spicetrade %%DATADIR%%/${DISTFILES}
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${DATADIR}

.include <bsd.port.mk>
