# New ports collection makefile for:    gnsutep-wrapper
# Date created:         16 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	deskutils gnustep
#MASTER_SITES=	ftp://ftp.raffael.ch/software/GNUstepWrapper/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	gnustep-
DISTNAME=	GNUstepWrapper-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Create GNUstep app-wrappers of non-GNUstep applications

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

ADDITIONAL_LIB_DIRS+=	-L${WRKSRC}/libGSWrapper/obj
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
MAKE_FLAGS+=	debug=no

post-patch:
	${REINPLACE_CMD} -e 's|cp -u|#cp -p|' \
		${WRKSRC}/WrapperFactory/GNUmakefile.postamble

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Launcher/obj/GSWrapper_Launcher \
		${GNUSTEP_SYSTEM_ROOT}/Applications/WrapperFactory.app/Resources/

.include <bsd.port.mk>
