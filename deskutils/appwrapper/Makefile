# $FreeBSD$

PORTNAME=	appwrapper
PORTVERSION=	0.1
PORTREVISION=	8
CATEGORIES=	deskutils gnustep
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/AppWrapper%20${PORTVERSION}
DISTNAME=	AppWrapper.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep application wrapper

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/AppWrapper

post-patch:
	${RMDIR} ${WRKSRC}/AppWrapper.app/ix86/linux-gnu
	${RMDIR} ${WRKSRC}/AppWrapper.app/ix86
	${REINPLACE_CMD} 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/AppWrapper.app/AppWrapper

.include <bsd.port.mk>
