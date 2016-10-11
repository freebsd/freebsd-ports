# Created by: Ilya A. Arkhipov <rum1cro@yandex.ru>
# $FreeBSD$

PORTNAME=	opengfx
PORTVERSION=	0.5.4
CATEGORIES=	games
MASTER_SITES=	http://bundles.openttdcoop.org/${PORTNAME}/releases/${PORTVERSION}/ \
		http://m1cro.me/ports/distfiles/${PORTNAME}/releases/${PORTVERSION}/

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Free alternative graphics for OpenTTD game engine

LICENSE=	GPLv2

USES=		zip
NO_BUILD=	yes

# upstream zipped a tar file, unpack it.
post-extract:
	@cd ${WRKDIR} && tar -xf ${PORTNAME}-${PORTVERSION}.tar

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/openttd/baseset/opengfx
	${INSTALL_DATA} ${WRKDIR}/opengfx-${PORTVERSION}/* \
		${STAGEDIR}${PREFIX}/share/openttd/baseset/opengfx

.include <bsd.port.mk>
