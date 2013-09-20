# Created by: Ilya A. Arhipov <admin@gorodkirov.ru>
# $FreeBSD$

PORTNAME=	opensfx
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://hu.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://us.binaries.openttd.org/binaries/extra/${PORTNAME}/${PORTVERSION}/ \
		http://cz.binaries.openttd.org/openttd/binaries/extra/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Free alternative sounds for OpenTTD game engine

USE_ZIP=	yes
NO_BUILD=	yes
LATEST_LINK=	openttd-${PORTNAME}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/share/openttd/baseset/opensfx
	${INSTALL_DATA} ${WRKDIR}/opensfx-${PORTVERSION}/* \
		${PREFIX}/share/openttd/baseset/opensfx

.include <bsd.port.mk>
