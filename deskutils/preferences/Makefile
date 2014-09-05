# $FreeBSD$

PORTNAME=	preferences
PORTVERSION=	1.2.0
PORTREVISION=	5
CATEGORIES=	deskutils gnustep
MASTER_SITES=	SF/prefsapp/prefsapp/${PORTVERSION}
DISTNAME=	Preferences-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep workspace manager

LICENSE_COMB=	multi
LICENSE=	GPLv2 LGPL21

USES=		tar:bzip2
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

DEAFULT_LIBVERSION=	1.1.1
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
MODIFY=		GNUmakefile.preamble PrefsModule/GNUmakefile.preamble \
		Modules/Keyboard/GNUmakefile.preamble \
		Modules/PrefsApp/GNUmakefile.preamble

post-patch:
	${REINPLACE_CMD} 's, -Werror,,' ${MODIFY:S,^,${WRKSRC}/,}
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile.preamble

.include <bsd.port.mk>
