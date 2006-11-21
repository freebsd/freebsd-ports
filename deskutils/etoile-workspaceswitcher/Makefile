# New ports collection makefile for:    etoile-workspaceswitcher
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	workspaceswitcher
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	deskutils
MASTER_SITES=	http://io.debian.net/~tar/ports/distfiles/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile_0+${SNAPSHOT}+dfsg.orig

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project WorkspaceSwitcher bundle

SNAPSHOT=	20060917
WRKSRC=	${WRKDIR}/etoile-0+${SNAPSHOT}+dfsg/Etoile/
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
NO_FILTER_SHLIBS=	yes
USE_GNUSTEP_MAKE_DIRS+=	Bundles/WorkspaceSwitcher

.include <bsd.port.mk>
