PORTNAME=	gshisen
PORTVERSION=	1.3.0
PORTREVISION=	10
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	GShisen-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shisen-sho puzzle game for GNUstep
WWW=		https://gap.nongnu.org/gshisen/index.html

LICENSE=	GPLv2+

USES=		gnustep
USE_GNUSTEP=	back build

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GShisen.app/GShisen

.include <bsd.port.mk>
