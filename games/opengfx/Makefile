# Created by: Ilya A. Arkhipov <rum1cro@yandex.ru>
# $FreeBSD$

PORTNAME=	opengfx
PORTVERSION=	0.6.0
CATEGORIES=	games
MASTER_SITES=	https://cdn.openttd.org/${PORTNAME}-releases/${PORTVERSION}/
DISTFILES=	${PORTNAME}-${PORTVERSION}-all.zip

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Free alternative graphics for OpenTTD game engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		zip

NO_BUILD=	yes
NO_ARCH=	yes
DATADIR=	${PREFIX}/share/openttd/baseset/opengfx

# upstream zipped a tar file, unpack it.
post-extract:
	@cd ${WRKDIR} && tar -xf ${PORTNAME}-${PORTVERSION}.tar

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
