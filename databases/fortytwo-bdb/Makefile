# New ports collection makefile for:    fortytwo-bdb
# Date created:         28 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	bdb
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	databases gnustep
MASTER_SITES=	SF/fortytwo/Berkeley%20DB%20Wrapper%20%28BDB%29/${PORTVERSION}
PKGNAMEPREFIX=	fortytwo-
DISTFILES=	BDB-${PORTVERSION}-src.tgz \
		BDB-${PORTVERSION}-api-ref.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Interface to Berkeley DB for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	Encore:${ENCORE_PORT}
DEFAULT_LIBVERSION=	0.1
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_BDB=	43

WRKSRC=		${WRKDIR}/BDB-${PORTVERSION}
DOCSDIR=	${GNUSTEP_PREFIX}/Local/Library/Documentation/BDB
ADDITIONAL_OBJCFLAGS+=	-I${BDB_INCLUDE_DIR}
ADDITIONAL_LDFLAGS+=	-L${BDB_LIB_DIR}

ENCORE_PORT?=	devel/fortytwo-encore

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${TAR} -C ${WRKDIR}/BDB-0.2.0-api-ref -cf - . | \
		${TAR} -C ${DOCSDIR} -xf -
.endif

.include <bsd.port.mk>
