# New ports collection makefile for:	opensfx
# Date created:			2010-11-04
# Whom:				Ilya A. Arhipov
#
# $FreeBSD$
#

PORTNAME=	opensfx
PORTVERSION=	0.2.3
CATEGORIES=	games
MASTER_SITES=	http://ftp.snt.utwente.nl/pub/games/openttd/binaries/extra/opensfx/${PORTVERSION}/ \
		http://gb.binaries.openttd.org/binaries/extra/opensfx/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	micro@heavennet.ru
COMMENT=	Free alternative sounds for OpenTTD game engine

USE_ZIP=	yes
NO_BUILD=	yes

post-extract:
	@${FIND} ${WRKDIR}/opensfx-${PORTVERSION} -type f -name "*.txt" -exec ${MV} {} {}-sfx \;

do-install:
	${MKDIR} ${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKDIR}/opensfx-${PORTVERSION}/* \
		${PREFIX}/share/openttd/data

.include <bsd.port.mk>
