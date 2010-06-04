# New ports collection makefile for:    etoile-typewriter
# Date created:         19 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	typewriter
PORTVERSION=	0.4.1
CATEGORIES=	editors gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	General text editor for plain and rich format text

LICENSE=	BSD

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	OgreKit:${OGREKIT_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	ScriptKit:${SCRIPTKIT_PORT}
USE_GNUSTEP_MAKE_DIRS+=	Services/User/Typewriter

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}

OGREKIT_PORT?=	textproc/etoile-ogrekit
SCRIPTKIT_PORT?=	lang/etoile-scriptkit

.include <bsd.port.mk>
