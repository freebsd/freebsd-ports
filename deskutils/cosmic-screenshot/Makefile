PORTNAME=	cosmic-screenshot
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	epoch-
CATEGORIES=	deskutils

MAINTAINER=	jo.sh@tutanota.com
COMMENT=	Screenshot capture tool for the COSMIC desktop environment
WWW=		https://github.com/pop-os/cosmic-screenshot

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	cosmic-icons>=${PORTVERSION}:x11-themes/cosmic-icons \
		xdg-desktop-portal-cosmic>=${PORTVERSION}:x11/xdg-desktop-portal-cosmic

USES=		cargo desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	pop-os

PLIST_FILES=	bin/cosmic-screenshot \
		share/applications/com.system76.CosmicScreenshot.desktop \
		share/icons/hicolor/16x16/apps/com.system76.CosmicScreenshot.svg \
		share/icons/hicolor/24x24/apps/com.system76.CosmicScreenshot.svg \
		share/icons/hicolor/32x32/apps/com.system76.CosmicScreenshot.svg \
		share/icons/hicolor/48x48/apps/com.system76.CosmicScreenshot.svg \
		share/icons/hicolor/64x64/apps/com.system76.CosmicScreenshot.svg \
		share/icons/hicolor/128x128/apps/com.system76.CosmicScreenshot.svg \
		share/icons/hicolor/256x256/apps/com.system76.CosmicScreenshot.svg

post-install:
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} \
		${WRKSRC}/resources/com.system76.CosmicScreenshot.desktop \
		${STAGEDIR}${DESKTOPDIR}
.for size in 16x16 24x24 32x32 48x48 64x64 128x128 256x256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
	${INSTALL_DATA} \
		${WRKSRC}/resources/icons/hicolor/${size}/apps/com.system76.CosmicScreenshot.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
.endfor

.include <bsd.port.mk>
