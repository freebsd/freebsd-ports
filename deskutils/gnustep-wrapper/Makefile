PORTNAME=	wrapper
PORTVERSION=	0.1.0
PORTREVISION=	12
CATEGORIES=	deskutils gnustep
#MASTER_SITES=	ftp://ftp.raffael.ch/software/GNUstepWrapper/
MASTER_SITES=	LOCAL/dinoex
PKGNAMEPREFIX=	gnustep-
DISTNAME=	GNUstepWrapper-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create GNUstep app-wrappers of non-GNUstep applications

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

ADDITIONAL_LIB_DIRS+=	-L${WRKSRC}/libGSWrapper/obj
MAKE_FLAGS+=	debug=no

post-patch:
	${REINPLACE_CMD} -e 's|cp -u|#cp -p|' \
		${WRKSRC}/WrapperFactory/GNUmakefile.postamble
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Launcher/obj/GSWrapper_Launcher \
		${STAGEDIR}${GNUSTEP_SYSTEM_ROOT}/Applications/WrapperFactory.app/Resources/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Tools/GSWrapper_Launcher
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Libraries/libGSWrapper.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/WrapperFactory.app/WrapperFactory

.include <bsd.port.mk>
