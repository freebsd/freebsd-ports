# Created by: Ilya A. Arhipov <admin@gorodkirov.ru>
# $FreeBSD$

PORTNAME=	openmsx
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://hu.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://us.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://cz.binaries.openttd.org/openttd/binaries/extra/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Free alternative music for OpenTTD game engine

USE_ZIP=	yes
NO_BUILD=	yes
LATEST_LINK=	openttd-${PORTNAME}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/share/openttd/baseset/openmsx
	${INSTALL_DATA} ${WRKDIR}/openmsx-${PORTVERSION}/* \
		${PREFIX}/share/openttd/baseset/openmsx

.include <bsd.port.mk>
