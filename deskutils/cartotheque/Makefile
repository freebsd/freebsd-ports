# $FreeBSD$

PORTNAME=	cartotheque
PORTVERSION=	0.1
PORTREVISION=	8
CATEGORIES=	deskutils gnustep
MASTER_SITES=	LOCAL/dinoex
DISTNAME=	Cartotheque-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Managing notes on small cards

LICENSE=	LGPL21

USES=		gnustep
USE_GNUSTEP=	back build

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Cartotheque.app/Cartotheque

.include <bsd.port.mk>
