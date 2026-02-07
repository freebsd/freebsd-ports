PORTNAME=	gworkspace
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	deskutils gnustep
MASTER_SITES=	GNUSTEP/usr-apps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep workspace manager
WWW=		https://www.gnustep.org/experience/GWorkspace.html

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

GNU_CONFIGURE=	yes

pre-configure:
	${RM} -r ${WRKSRC}/GWMetadata

.include <bsd.port.mk>
