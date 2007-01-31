# New ports collection makefile for:    fortytwo-encore
# Date created:         28 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	encore
PORTVERSION=	0.3.0
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fortytwo
PKGNAMEPREFIX=	fortytwo-
DISTFILES=	Encore-${PORTVERSION}-src.tgz \
		Encore-${PORTVERSION}-api-ref.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Utility classes for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
DEFAULT_LIBVERSION=	0.1
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Encore-${PORTVERSION}
DOCSDIR=	${GNUSTEP_PREFIX}/Local/Library/Documentation/Encore

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${TAR} -C ${WRKDIR}/Encore-${PORTVERSION}-api-ref -cf - . | \
		${TAR} -C ${DOCSDIR} -xf -
.endif

.include <bsd.port.mk>
