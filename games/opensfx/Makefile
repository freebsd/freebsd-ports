PORTNAME=	opensfx
PORTVERSION=	1.0.3
CATEGORIES=	games
MASTER_SITES=	https://cdn.openttd.org/${PORTNAME}-releases/${PORTVERSION}/
PKGNAMEPREFIX=	openttd-
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Free alternative sounds for OpenTTD game engine

LICENSE=	CC-BY-SA-3.0 CDDL GPLv2
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKDIR}/opensfx-${PORTVERSION}/license.txt

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes

post-extract:
	@cd ${WRKDIR} && tar -xf ${PORTNAME}-${PORTVERSION}.tar

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/openttd/baseset/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/* \
		${STAGEDIR}${PREFIX}/share/openttd/baseset/${PORTNAME}

.include <bsd.port.mk>
