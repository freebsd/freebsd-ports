# New ports collection makefile for:    gnsutep-wrapper
# Date created:         16 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION=	0.1.0
CATEGORIES=	deskutils gnustep
#MASTER_SITES=	ftp://ftp.raffael.ch/software/GNUstepWrapper/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	gnustep-
DISTNAME=	GNUstepWrapper-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Create GNUstep app-wrappers of non-GNUstep applications

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

post-patch:
	${REINPLACE_CMD} -e 's|cp -u|cp -p|' \
		${WRKSRC}/WrapperFactory/GNUmakefile.postamble

.include <bsd.port.mk>
