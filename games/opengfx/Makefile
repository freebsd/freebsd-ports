# Created by: Ilya A. Arkhipov <rum1cro@yandex.ru>

PORTNAME=	opengfx
PORTVERSION=	7.1
CATEGORIES=	games
MASTER_SITES=	https://cdn.openttd.org/${PORTNAME}-releases/${PORTVERSION}/
PKGNAMEPREFIX=	openttd-
DISTFILES=	${PORTNAME}-${PORTVERSION}-all.zip

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Free alternative graphics for OpenTTD game engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

NO_ARCH=	yes
NO_BUILD=	yes

post-extract:
	@cd ${WRKDIR} && tar -xf ${PORTNAME}-${PORTVERSION}.tar

do-install:
	@${MKDIR} \
		${STAGEDIR}${PREFIX}/share/openttd/baseset/${PORTNAME}
	${INSTALL_DATA} \
		${WRKSRC}/* \
		${STAGEDIR}${PREFIX}/share/openttd/baseset/${PORTNAME}

.include <bsd.port.mk>
