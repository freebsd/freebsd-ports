# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freepats
PORTVERSION=	20060219
CATEGORIES=	audio
MASTER_SITES=	http://freepats.zenvoid.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free and open set of instrument patches

USE_BZIP2=	yes
NO_STAGE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}

.include <bsd.port.mk>
