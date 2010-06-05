# New ports collection makefile for:    objectivelib
# Date created:         1 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	objectivelib
PORTVERSION=	1.0.0
CATEGORIES=	devel gnustep
MASTER_SITES=	SF

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Object containers and generic algorithms for Objective-C

LICENSE=	LGPL21

USE_GNUSTEP=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_ICONV=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS+=	 --with-libiconv-prefix=${LOCALBASE}

.include <bsd.port.mk>
