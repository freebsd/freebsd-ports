# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	proj-data
PORTVERSION=	1.10
CATEGORIES=	graphics geography
MASTER_SITES=	https://download.osgeo.org/proj/ \
		https://github.com/OSGeo/PROJ-data/releases/download/${PORTVERSION}.0/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datum grid package for PROJ

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/proj

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
