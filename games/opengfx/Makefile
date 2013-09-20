# Created by: Ilya A. Arkhipov <rum1cro@yandex.ru>
# $FreeBSD$

PORTNAME=	opengfx
PORTVERSION=	0.4.7
CATEGORIES=	games
MASTER_SITES=	http://hu.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://us.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://cz.binaries.openttd.org/openttd/binaries/extra/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Free alternative graphics for OpenTTD game engine

USE_ZIP=	yes
NO_BUILD=	yes
LATEST_LINK=	openttd-${PORTNAME}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/share/openttd/baseset/opengfx
	${INSTALL_DATA} ${WRKDIR}/opengfx-${PORTVERSION}/* \
		${PREFIX}/share/openttd/baseset/opengfx

.include <bsd.port.mk>
