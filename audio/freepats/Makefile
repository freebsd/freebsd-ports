PORTNAME=	freepats
PORTVERSION=	20060219
CATEGORIES=	audio
MASTER_SITES=	http://freepats.zenvoid.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free and open set of instrument patches

USES=		tar:bzip2

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
