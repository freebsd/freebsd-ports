# New ports collection makefile for:    etoile-languagekit
# Date created:         26 Nov 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	languagekit
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	lang gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project LanguageKit framework

BUILD_DEPENDS=	llc:${PORTSDIR}/devel/llvm-devel

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_GNUSTEP_LOCAL_LIBS+=	EtoileFoundation:${FOUNDATION_PORT}
USE_PERL5_BUILD=	yes

DEFAULT_LIBVERSION=	0.6
WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Languages/LanguageKit
DEFAULT_LIBVERSION2=	0.0.1
ADDITIONAL_LIB_DIRS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	LIBVERSION2=${DEFAULT_LIBVERSION2}
PLIST_SUB+=	MAJORLIBVERSION2=${DEFAULT_LIBVERSION2:C/([0-9]).*/\1/1}

FOUNDATION_PORT?=	devel/etoile-foundation

.include <bsd.port.mk>
