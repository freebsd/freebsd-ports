# New ports collection makefile for:	openmsx
# Date created:			2010-11-04
# Whom:				Ilya A. Arhipov
#
# $FreeBSD$
#

PORTNAME=	openmsx
PORTVERSION=	0.3.1
CATEGORIES=	games
MASTER_SITES=	http://ftp.snt.utwente.nl/pub/games/openttd/binaries/extra/openmsx/${PORTVERSION}/ \
		http://gb.binaries.openttd.org/binaries/extra/openmsx/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	micro@heavennet.ru
COMMENT=	Free alternative music for OpenTTD game engine

USE_ZIP=	yes
NO_BUILD=	yes

post-extract:
	@${FIND} ${WRKDIR}/openmsx-${PORTVERSION} -type f -name "*.txt" -exec ${MV} {} {}-msx \;

do-install:
	${MKDIR} ${PREFIX}/share/openttd/gm
	${INSTALL_DATA} ${WRKDIR}/openmsx-${PORTVERSION}/* \
		${PREFIX}/share/openttd/gm

.include <bsd.port.mk>
