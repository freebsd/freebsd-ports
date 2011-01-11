# New ports collection makefile for:	openmsx
# Date created:			2010-11-04
# Whom:				Ilya A. Arhipov
#
# $FreeBSD$
#

PORTNAME=	openmsx
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://gb.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://de.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://cz.binaries.openttd.org/openttd/binaries/extra/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	micro@heavennet.ru
COMMENT=	Free alternative music for OpenTTD game engine

USE_ZIP=	yes
NO_BUILD=	yes
LATEST_LINK=	openttd-${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/share/openttd/gm/openmsx
	${INSTALL_DATA} ${WRKDIR}/openmsx-${PORTVERSION}/* \
		${PREFIX}/share/openttd/gm/openmsx

.include <bsd.port.mk>
