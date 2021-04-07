PORTNAME=	preferences
PORTVERSION=	1.2.0
PORTREVISION=	12
CATEGORIES=	deskutils gnustep
MASTER_SITES=	SF/prefsapp/prefsapp/${PORTVERSION}
DISTNAME=	Preferences-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep workspace manager

LICENSE_COMB=	multi
LICENSE=	GPLv2 LGPL21

USES=		tar:bzip2 gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

MODIFY=		GNUmakefile.preamble PrefsModule/GNUmakefile.preamble \
		Modules/Keyboard/GNUmakefile.preamble \
		Modules/PrefsApp/GNUmakefile.preamble

post-patch:
	${REINPLACE_CMD} 's, -Werror,,' ${MODIFY:S,^,${WRKSRC}/,}
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile.preamble

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Preferences.app/Preferences
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Preferences.app/Resources/PrefsApp.prefs/PrefsApp
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/PrefsModule.framework/Versions/0/libPrefsModule.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Preferences/Keyboard.prefs/Keyboard

.include <bsd.port.mk>
