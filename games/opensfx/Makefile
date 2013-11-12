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

LICENSE=	CCPL
LICENSE_NAME=	Creative Commons Public License
LICENSE_FILE=	${WRKDIR}/opensfx-${PORTVERSION}/license.txt
LICENSE_PERMS=	auto-accept

USE_ZIP=	yes
NO_BUILD=	yes
LATEST_LINK=	openttd-${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/openttd/baseset/opensfx
	${INSTALL_DATA} ${WRKDIR}/opensfx-${PORTVERSION}/* \
		${STAGEDIR}${PREFIX}/share/openttd/baseset/opensfx

.include <bsd.port.mk>
