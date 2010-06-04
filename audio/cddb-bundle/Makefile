# New ports collection makefile for:    cddb-bundle
# Date created:         17 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	cddb
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	audio gnustep
MASTER_SITES=	SF/gsburn/${PORTNAME}.bundle/${PORTNAME}.bundle-${PORTVERSION}
PKGNAMESUFFIX=	-bundle${PKGNAMESUFFIX2}
DISTNAME=	cddb.bundle-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	CDDB client bundle GNUstep

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/cddb.bundle
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

.include <bsd.port.mk>
