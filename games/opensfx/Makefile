# New ports collection makefile for:	opensfx
# Date created:			2010-11-04
# Whom:				Ilya A. Arhipov
#
# $FreeBSD$
#

PORTNAME=	opensfx
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://gb.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://de.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://cz.binaries.openttd.org/openttd/binaries/extra/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	micro@heavennet.ru
COMMENT=	Free alternative sounds for OpenTTD game engine

USE_ZIP=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/openttd/data/opensfx/
	${INSTALL_DATA} ${WRKDIR}/opensfx-${PORTVERSION}/* \
		${PREFIX}/share/openttd/data/opensfx/

.include <bsd.port.mk>
