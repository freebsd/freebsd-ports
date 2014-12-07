# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gshisen
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	GShisen-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shisen-sho puzzle game for GNUstep

LICENSE=	GPLv2 # or later

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GShisen.app/GShisen

.include <bsd.port.mk>
