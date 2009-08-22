# New ports collection makefile for:	spicetrade
# Date created:				2005-09-09
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	spicetrade
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Spice%20Trade%20v${PORTVERSION}
DISTNAME=	Spicetrade-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	daniel@roe.ch
COMMENT=	Colourful 14th century Arab spice trading game

NO_PACKAGE=	Package will be 186MB, set FORCE_PACKAGE if you really want to build it

USE_JAVA=	yes
JAVA_VERSION=	1.4+
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
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
