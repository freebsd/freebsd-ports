# $FreeBSD$

PORTNAME=	plopfolio
PORTVERSION=	0.1.0
PORTREVISION=	4
CATEGORIES=	deskutils gnustep
MASTER_SITES=	GNUSTEP/usr-apps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free clone of KlipFolio for GNUstep

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build

FIXME=	Channel.m PlopFolio.m PreferencesPanelController.m

post-patch:
.for i in ${FIXME}
	${REINPLACE_CMD} -e 's|Foundation/GSXML.h|GNUstepBase/GSXML.h|' \
		${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
