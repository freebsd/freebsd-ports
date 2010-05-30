# New ports collection makefile for:    etoile-scriptservices
# Date created:         26 Nov 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	scriptservices
PORTVERSION=	0.4.1
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project ScriptServices

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	EtoileFoundation:${FOUNDATION_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	LanguageKit:${LANGUAGEKIT_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	SmalltalkSupport:${SMALLTALKKIT_PORT}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Services/Private/ScriptServices
MORE_SRC=	${WRKSRC}/Services/Private/ScriptServices/Examples
MORE_DEST=	${GNUSTEP_PREFIX}/Local/Applications/ScriptServices.app/Resources/Scripts/
EXAMPLE=	Current_Time_.sh Open_in_Wikipedia.sh \
		Open_in_Wiktionary.sh today.sh

FOUNDATION_PORT?=	devel/etoile-foundation
LANGUAGEKIT_PORT?=	lang/etoile-languagekit
SMALLTALKKIT_PORT?=	lang/etoile-smalltalkkit

post-install:
	cd ${MORE_SRC} && ${INSTALL_DATA} today.plist ${MORE_DEST}
	cd ${MORE_SRC} && ${INSTALL_SCRIPT} ${EXAMPLE} ${MORE_DEST}

.include <bsd.port.mk>
