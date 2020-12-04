# Created by: Ilya A. Arhipov <admin@gorodkirov.ru>
# $FreeBSD$

PORTNAME=	opensfx
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://cdn.openttd.org/opensfx-releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Free alternative sounds for OpenTTD game engine

LICENSE=	CC-Sampling+-1.0
LICENSE_NAME=	Creative Commons Sampling Plus 1.0
LICENSE_FILE=	${WRKDIR}/opensfx-${PORTVERSION}/license.txt
LICENSE_PERMS=	auto-accept

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/openttd/baseset/opensfx
	${INSTALL_DATA} ${WRKDIR}/opensfx-${PORTVERSION}/* \
		${STAGEDIR}${PREFIX}/share/openttd/baseset/opensfx

.include <bsd.port.mk>
