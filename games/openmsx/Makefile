PORTNAME=	openmsx
PORTVERSION=	0.4.2
CATEGORIES=	games
MASTER_SITES=   https://cdn.openttd.org/${PORTNAME}-releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all
PKGNAMEPREFIX=	openttd-

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Free alternative music for OpenTTD game engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/openmsx-${PORTVERSION}

post-extract:
	@cd ${WRKDIR} && tar -xf ${PORTNAME}-${PORTVERSION}.tar

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/openttd/baseset/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.mid \
		${STAGEDIR}${PREFIX}/share/openttd/baseset/${PORTNAME}

.include <bsd.port.mk>
