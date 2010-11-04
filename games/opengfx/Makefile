# New ports collection makefile for:	opengfx
# Date created:			2010-11-04
# Whom:				Ilya A. Arhipov
#
# $FreeBSD$
#

PORTNAME=	opengfx
PORTVERSION=	0.3.1
CATEGORIES=	games
MASTER_SITES=	http://ftp.snt.utwente.nl/pub/games/openttd/binaries/extra/opengfx/${PORTVERSION}/ \
		http://gb.binaries.openttd.org/binaries/extra/opengfx/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	micro@heavennet.ru
COMMENT=	Free alternative graphics for OpenTTD game engine

USE_ZIP=	yes
NO_BUILD=	yes

post-extract:
	@${FIND} ${WRKDIR}/opengfx-${PORTVERSION} -type f -name "*.txt" -exec ${MV} {} {}-gfx \;

do-install:
	${MKDIR} ${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKDIR}/opengfx-${PORTVERSION}/* \
		${PREFIX}/share/openttd/data

.include <bsd.port.mk>
