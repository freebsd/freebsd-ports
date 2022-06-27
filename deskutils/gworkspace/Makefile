PORTNAME=	gworkspace
PORTVERSION=	1.0.0
CATEGORIES=	deskutils gnustep
MASTER_SITES=	GNUSTEP/usr-apps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep workspace manager

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

GNU_CONFIGURE=	yes

pre-configure:
	${RM} -r ${WRKSRC}/GWMetadata

.include <bsd.port.mk>
