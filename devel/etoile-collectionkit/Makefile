# New ports collection makefile for:    etoile-collectionkit
# Date created:         22 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	collectionkit
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Provides a common storage facility for records with properties

PORTSCOUT=	limit:^0\.2

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/CollectionKit

.include <bsd.port.mk>
