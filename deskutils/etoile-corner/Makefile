# New ports collection makefile for:    etoile-corner
# Date created:         26 Nov 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	corner
PORTVERSION=	0.4.1
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Etoile Project hot-corners

LICENSE=	BSD

DEPRECATED=	API no longer supported
EXPIRATION_DATE=	2012-07-20

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	SmalltalkSupport:${SMALLTALKKIT_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	ScriptKit:${SCRIPTKIT_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	LanguageKit:${LANGUAGEKIT_PORT}
USE_XORG=	x11

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Services/Private/Corner
PLIST_FILES=	GNUstep/System/Tools/Corner

SMALLTALKKIT_PORT?=	lang/etoile-smalltalkkit
SCRIPTKIT_PORT?=	lang/etoile-scriptkit
LANGUAGEKIT_PORT?=	lang/etoile-languagekit

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
ADDITIONAL_LDFLAGS+=	-lgcc_s -lgcc
.endif

.include <bsd.port.post.mk>
