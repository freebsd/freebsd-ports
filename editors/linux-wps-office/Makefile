PORTNAME=	wps-office
DISTVERSION=	11.1.0.11723
CATEGORIES=	editors linux
MASTER_SITES=	https://wdl1.pcfg.cache.wpscdn.com/wpsdl/wpsoffice/download/linux/11723/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}.XA-1.x86_64
EXTRACT_SUFX=	.rpm

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Complete office suite with PDF editor
WWW=		https://www.wps.com/

LICENSE=	commercial
LICENSE_NAME=	End User License Agreement
LICENSE_TEXT=	See: https://www.wps.com/eula
LICENSE_PERMS=	no-auto-accept no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

ONLY_FOR_ARCHS=	amd64

USES=		desktop-file-utils linux:rl9 shebangfix ssl
USE_LINUX=	cups-libs gtk3 imageformats-libs libglvnd libxslt \
		pulseaudio-libs xorglibs

SHEBANG_FILES=	usr/bin/et \
		usr/bin/wpp \
		usr/bin/wps \
		usr/bin/wpspdf

CONFLICTS_INSTALL=	linux-wps-office-zh_CN

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}

ICONS_SIZES=	16 24 32 48 64 96 128 256 512
WPS_BINS=	et wpp wps wpspdf
WPS_DESK=	et wpp wps pdf prometheus

post-patch:
	${REINPLACE_CMD} -i '' -e 's|/usr/bin|${PREFIX}/bin|' \
		${WPS_DESK:C|(.+)|${WRKSRC}/opt/kingsoft/${PORTNAME}/desktops/${PORTNAME}-\1.desktop|}
	${REINPLACE_CMD} -e 's|gInstallPath=/opt|gInstallPath=${LINUXBASE}/opt|' \
		${WPS_BINS:C|^|${WRKSRC}/usr/bin/|}

do-install:
	${MKDIR} ${ICONS_SIZES:C|([0-9]+)|${STAGEDIR}${PREFIX}/share/icons/hicolor/\1x\1/apps|}
.for s in ${ICONS_SIZES}
	${INSTALL_DATA} ${WRKSRC}/usr/share/icons/hicolor/${s}x${s}/mimetypes/*.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/
.endfor
	${INSTALL_DATA} \
		${WPS_DESK:C|(.+)|${WRKSRC}/opt/kingsoft/${PORTNAME}/desktops/${PORTNAME}-\1.desktop|} \
		${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} opt ${STAGEDIR}${LINUXBASE})
	${INSTALL_SCRIPT} ${WPS_BINS:C|^|${WRKSRC}/usr/bin/|} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
