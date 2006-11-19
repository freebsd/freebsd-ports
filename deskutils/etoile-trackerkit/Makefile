# New ports collection makefile for:    etoile-trackerkit
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	trackerkit
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	deskutils
MASTER_SITES=	http://florida.ethz.ch/ports/distfiles/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile_0+${SNAPSHOT}+dfsg.orig

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project TrackerKit framework

SNAPSHOT=	20060917
WRKSRC=	${WRKDIR}/etoile-0+${SNAPSHOT}+dfsg/Etoile/
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
LDCONFIG_DIRS=	${LOCALLIBDIR}
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/TrackerKit

HEADERS=	TKCollection.h TKKeyValuePredicate.h TKObject.h \
		TKQuery.h TKTracker.h

post-install:
	${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Headers/TrackerKit
.for i in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/Frameworks/TrackerKit/Headers/${i} \
		 ${GNUSTEP_PREFIX}/System/Library/Headers/TrackerKit/
.endfor

.include <bsd.port.mk>
