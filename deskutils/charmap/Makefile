# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	charmap
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	deskutils gnustep
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Character map for GNUstep

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/Charmap.app/Charmap

.include <bsd.port.mk>
