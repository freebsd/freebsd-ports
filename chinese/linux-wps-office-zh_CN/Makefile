PORTNAME=	wps-office
DISTVERSION=	11.1.0.10161
DISTVERSIONSUFFIX=	-zh_CN
CATEGORIES=	chinese editors linux
MASTER_SITES=	https://wdl1.cache.wps.cn/wps/download/ep/Linux2019/10161/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-zh_CN
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.x86_64
EXTRACT_SUFX=	.rpm

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Complete office suite with PDF editor

LICENSE=	commercial
LICENSE_NAME=	End User License Agreement
LICENSE_TEXT=	See: https://www.wps.cn/privacy/full_useragreement/
LICENSE_PERMS=	no-auto-accept no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

ONLY_FOR_ARCHS=	amd64

CONFLICTS_INSTALL=	linux-wps-office

USES=		desktop-file-utils gnome linux shebangfix
USE_LINUX=	png pulseaudio-libs xorglibs

SHEBANG_FILES=	usr/bin/et \
		usr/bin/wpp \
		usr/bin/wps \
		usr/bin/wpspdf

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}

WPS_BINS=	et wpp wps wpspdf
WPS_DESK=	et wpp wps pdf prometheus

post-patch:
.for d in ${WPS_DESK}
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin|${PREFIX}/bin|' ${WRKSRC}/opt/kingsoft/${PORTNAME}/desktops/${PORTNAME}-${d}.desktop
.endfor
.for b in ${WPS_BINS}
	@${REINPLACE_CMD} -e 's|gInstallPath=/opt|gInstallPath=${LINUXBASE}/opt|' ${WRKSRC}/usr/bin/${b}
.endfor

do-install:
.for s in 16 20 24 32 40 48 60 64 72 80 96 128 256 512
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/usr/share/icons/hicolor/${s}x${s}/mimetypes/*.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/
.endfor
.for d in ${WPS_DESK}
	${INSTALL_DATA} ${WRKSRC}/opt/kingsoft/${PORTNAME}/desktops/${PORTNAME}-${d}.desktop \
		${STAGEDIR}${DESKTOPDIR}
.endfor
	${MKDIR} ${STAGEDIR}${LINUXBASE}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} opt ${STAGEDIR}${LINUXBASE})
.for b in ${WPS_BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/${b} ${STAGEDIR}${PREFIX}/bin
	${CHMOD} +x ${STAGEDIR}${LINUXBASE}/opt/kingsoft/wps-office/office6/${b}
.endfor

.include <bsd.port.mk>
