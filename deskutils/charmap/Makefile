# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	charmap
PORTVERSION=	0.2
PORTREVISION=	7
CATEGORIES=	deskutils gnustep
MASTER_SITES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Character map for GNUstep

LICENSE=	GPLv2

DEPRECATED=	Mastersite disappeared
EXPIRATION_DATE=	2018-03-01

USES=		gnustep
USE_GNUSTEP=	back base build gui

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Charmap.app/Charmap

.include <bsd.port.mk>
