# New ports collection makefile for:    gnsutep-wrapper
# Date created:         16 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION=	0.1.0
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.raffael.ch/software/GNUstepWrapper/
PKGNAMEPREFIX=	gnustep-
DISTNAME=	GNUstepWrapper-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Create GNUstep app-wrappers of non-GNUstep applications

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${SYSLIBDIR}

post-patch:
	${REINPLACE_CMD} -e 's|cp -u|cp -p|' \
		${WRKSRC}/WrapperFactory/GNUmakefile.postamble

.include <bsd.port.mk>
