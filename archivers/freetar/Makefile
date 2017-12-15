# $FreeBSD$

PORTNAME=	freetar
PORTVERSION=	0.9
PORTREVISION=	7
CATEGORIES=	archivers gnustep
MASTER_SITES=	http://download.gna.org/freetar/
DISTNAME=	FreeTar-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TAR archiver for GNUstep

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/FreeTar_1_1_1_Source

post-install:
	@${STRIP_CMD} ${STAGEDIR}${GNUSTEP_PREFIX}/System/Applications/FreeTar.app/FreeTar

.include <bsd.port.mk>
