# $FreeBSD$

PORTNAME=	nextgo
PORTVERSION=	3.0
PORTREVISION=	6
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	NeXTGo-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic Go game for OPENSTEP/GNUstep

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile
	${REINPLACE_CMD} -e 's|PSWait|myPSWait|' \
		${WRKSRC}/Board.m

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/NeXTGo.app/NeXTGo

.include <bsd.port.mk>
