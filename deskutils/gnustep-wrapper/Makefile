# $FreeBSD$

PORTNAME=	wrapper
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	deskutils gnustep
#MASTER_SITES=	ftp://ftp.raffael.ch/software/GNUstepWrapper/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	gnustep-
DISTNAME=	GNUstepWrapper-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create GNUstep app-wrappers of non-GNUstep applications

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

ADDITIONAL_LIB_DIRS+=	-L${WRKSRC}/libGSWrapper/obj
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
MAKE_FLAGS+=	debug=no

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|cp -u|#cp -p|' \
		${WRKSRC}/WrapperFactory/GNUmakefile.postamble

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Launcher/obj/GSWrapper_Launcher \
		${GNUSTEP_SYSTEM_ROOT}/Applications/WrapperFactory.app/Resources/

.include <bsd.port.mk>
