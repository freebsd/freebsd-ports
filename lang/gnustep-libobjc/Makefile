# New ports collection makefile for:    libobjc2
# Date created:         06 Octil 2010
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	libobjc2
PORTVERSION=	1.2
CATEGORIES=	lang devel gnustep
MASTER_SITES=	http://download.gna.org/gnustep/
PKGNAMEPREFIX=	gnustep-

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep Objective-C runtime for GCC and LLVM

LICENSE=	MIT

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
GNUSTEP_WITHOUT_LIBOBJC=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
DEFAULT_LIBVERSION=	5

post-patch:
	${REINPLACE_CMD} -e 's|libobjc_VERSION = 4|libobjc_VERSION = ${DEFAULT_LIBVERSION}|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
