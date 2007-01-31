# New ports collection makefile for:    toolbox
# Date created:         18 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	toolbox
PORTVERSION=	0.8
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://ftp.azc.uam.mx/mirrors/gnu/savannah/files/toolbox/Release.pkg/0.8/
DISTNAME=	Toolbox-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Collection of tools for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	Toolbox:${TOOLBOXKIT_PORT}

WRKSRC=		${WRKDIR}/Toolbox

TOOLBOXKIT_PORT?=	deskutils/toolboxkit

post-patch:
	${REINPLACE_CMD} -e 's| Toolbox ||' ${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
