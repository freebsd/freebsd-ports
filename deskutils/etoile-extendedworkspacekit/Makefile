# New ports collection makefile for:    etoile-extendedworkspacekit
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	extendedworkspacekit
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	deskutils
MASTER_SITES=	http://io.debian.net/~tar/ports/distfiles/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile_0+${SNAPSHOT}+dfsg.orig

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project ExtendedWorkspaceKit framework

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
USE_GNUSTEP_SYSTEM_LIBS+=	TrackerKit:${TRACKERKIT_PORT}
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/ExtendedWorkspaceKit

TRACKERKIT_PORT?=	deskutils/etoile-trackerkit

.include <bsd.port.mk>
