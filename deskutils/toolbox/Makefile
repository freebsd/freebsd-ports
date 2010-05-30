# New ports collection makefile for:    toolbox
# Date created:         18 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	toolbox
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://ftp.azc.uam.mx/mirrors/gnu/savannah/files/toolbox/Release.pkg/0.8/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
DISTNAME=	Toolbox-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Collection of tools for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	Toolbox:${TOOLBOXKIT_PORT}

WRKSRC=		${WRKDIR}/Toolbox
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

TOOLBOXKIT_PORT?=	deskutils/toolboxkit

post-patch:
	${REINPLACE_CMD} -e 's| Toolbox ||' ${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
