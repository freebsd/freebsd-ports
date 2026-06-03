PORTNAME=	plopfolio
PORTVERSION=	0.1.0
PORTREVISION=	13
CATEGORIES=	deskutils gnustep
MASTER_SITES=	GNUSTEP/usr-apps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free clone of KlipFolio for GNUstep
WWW=		http://www.collaboration-world.com/cgi-bin/project/index.cgi?pid=7

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build

post-patch:
	${REINPLACE_CMD} -e 's|Foundation/GSXML.h|GNUstepBase/GSXML.h|' \
		${WRKSRC}/Channel.m ${WRKSRC}/PlopFolio.m \
		${WRKSRC}/PreferencesPanelController.m

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/PlopFolio.app/PlopFolio

.include <bsd.port.mk>
