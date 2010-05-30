# New ports collection makefile for:    fortytwo
# Date created:         28 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	fortytwo
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	graphics gnustep
MASTER_SITES=	SF/${PORTNAME}/FT%20%2842%29/${PORTVERSION}
DISTFILES=	FT-${PORTVERSION}-src.tgz \
		FT-${PORTVERSION}-api-ref.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graph management system for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	Encore:${ENCORE_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	BDB:${FORTYTWO_BDB_PORT}
DEFAULT_LIBVERSION=	0.1
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_BDB=	43

WRKSRC=		${WRKDIR}/FT-${PORTVERSION}
DOCSDIR=	${GNUSTEP_PREFIX}/Local/Library/Documentation/FT

ENCORE_PORT?=	devel/fortytwo-encore
FORTYTWO_BDB_PORT?=	databases/fortytwo-bdb
ADDITIONAL_OBJCFLAGS+=	-I${BDB_INCLUDE_DIR}
ADDITIONAL_LDFLAGS+=	-L${BDB_LIB_DIR}

.include <bsd.port.mk>
