# New ports collection makefile for:    mp3towav-bundle
# Date created:         30 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mp3towav
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	audio gnustep
MASTER_SITES=	SF/gsburn/${PORTNAME}.bundle/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-bundle${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	MP3ToWav plugin for Burn.app

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_APPS+=	Burn:${BURN_PORT}

WRKSRC=		${WRKDIR}/MP3ToWav
ADDITIONAL_INCLUDE_DIRS+=	-I${GNUSTEP_PREFIX}/Local/Library/Headers/Burn
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

BURN_PORT?=	sysutils/burn

.include <bsd.port.mk>
