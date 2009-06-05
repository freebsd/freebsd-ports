# New ports collection makefile for:    etoile-smalltalkkit
# Date created:         26 Nov 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	smalltalkkit
PORTVERSION=	0.4.1
CATEGORIES=	lang gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project SmalltalkKit framework

BUILD_DEPENDS=	lemon:${PORTSDIR}/devel/lemon

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_GNUSTEP_LOCAL_LIBS+=	EtoileFoundation:${FOUNDATION_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	LanguageKit:${LANGUAGEKIT_PORT}

DEFAULT_LIBVERSION=	0.6
WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Languages/Smalltalk
DEFAULT_LIBVERSION2=	0.0.1
ADDITIONAL_LIB_DIRS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	LIBVERSION2=${DEFAULT_LIBVERSION2}
PLIST_SUB+=	MAJORLIBVERSION2=${DEFAULT_LIBVERSION2:C/([0-9]).*/\1/1}

FOUNDATION_PORT?=	devel/etoile-foundation
LANGUAGEKIT_PORT?=	lang/etoile-languagekit

.include <bsd.port.mk>
