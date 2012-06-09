# New ports collection makefile for:    cddb-bundle
# Date created:         17 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	cddb
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	audio gnustep
MASTER_SITES=	SF/gsburn/cdplayer/${DISTNAME}
PKGNAMESUFFIX=	-bundle${PKGNAMESUFFIX2}
DISTNAME=	cdplayer-${CDPLAYER_VERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	CDDB client bundle GNUstep

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

CDPLAYER_VERSION=	0.5.1
WRKSRC=		${WRKDIR}/CDPlayer-${CDPLAYER_VERSION}/Cddb
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

.include <bsd.port.mk>
