# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	charmap
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	deskutils gnustep
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Character map for GNUstep

BROKEN=		unfetchable

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Charmap.app/Charmap

.include <bsd.port.mk>
