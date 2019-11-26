# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	spicetrade
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Spice%20Trade%20v${PORTVERSION}
DISTNAME=	Spicetrade-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Colourful 14th century Arab spice trading game

USE_JAVA=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	JARFILE="${DATADIR}/${DISTFILES}"

PLIST_FILES=	bin/spicetrade \
		%%DATADIR%%/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
