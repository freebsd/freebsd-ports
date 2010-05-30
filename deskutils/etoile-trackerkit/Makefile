# New ports collection makefile for:    etoile-trackerkit
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	trackerkit
PORTVERSION=	0.1.${SNAPSHOT}
PORTREVISION=	2
CATEGORIES=	deskutils gnustep
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project TrackerKit framework

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
DEFAULT_LIBVERSION=	0.1
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/TrackerKit
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

HEADERS=	TKCollection.h TKKeyValuePredicate.h TKObject.h \
		TKQuery.h TKTracker.h

post-install:
	${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Headers/TrackerKit
.for i in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/Frameworks/TrackerKit/Headers/${i} \
		 ${GNUSTEP_PREFIX}/System/Library/Headers/TrackerKit/
.endfor

.include <bsd.port.mk>
