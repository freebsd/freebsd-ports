# $FreeBSD$

PORTNAME=	jigsaw
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	Jigsaw-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulates a jigsaw puzzle and illustrates the use of clipping paths

LICENSE=	GPLv2 # or later

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/Jigsaw.app/Jigsaw

.include <bsd.port.mk>
