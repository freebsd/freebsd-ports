# New ports collection makefile for:	opengfx
# Date created:			2010-11-04
# Whom:				Ilya A. Arhipov
#
# $FreeBSD$
#

PORTNAME=	opengfx
PORTVERSION=	0.3.7
CATEGORIES=	games
MASTER_SITES=	http://gb.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://de.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://cz.binaries.openttd.org/openttd/binaries/extra/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	micro@heavennet.ru
COMMENT=	Free alternative graphics for OpenTTD game engine

USE_ZIP=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/openttd/data/opengfx/
	${INSTALL_DATA} ${WRKDIR}/opengfx-${PORTVERSION}/* \
		${PREFIX}/share/openttd/data/opengfx/

.include <bsd.port.mk>
