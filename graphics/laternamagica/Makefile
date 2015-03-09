# $FreeBSD$

PORTNAME=	laternamagica
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	graphics gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	LaternaMagica-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image viewer and slideshow application

LICENSE=	GPLv2 # or later

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/LaternaMagica.app/LaternaMagica

.include <bsd.port.mk>
