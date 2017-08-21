# $FreeBSD$

PORTNAME=	laternamagica
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	graphics gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	LaternaMagica-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image viewer and slideshow application

LICENSE=	GPLv2+

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/LaternaMagica.app/LaternaMagica

.include <bsd.port.mk>
