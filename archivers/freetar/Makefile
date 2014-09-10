# $FreeBSD$

PORTNAME=	freetar
PORTVERSION=	0.9
PORTREVISION=	4
CATEGORIES=	archivers gnustep
MASTER_SITES=	http://download.gna.org/freetar/
DISTNAME=	FreeTar-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TAR archiver for GNUstep

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/FreeTar_1_1_1_Source

post-install:
	@${STRIP_CMD} ${STAGEDIR}${GNUSTEP_PREFIX}/Local/Applications/FreeTar.app/FreeTar

.include <bsd.port.mk>
