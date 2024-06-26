PORTNAME=	linux-tradingview
PORTVERSION=	2.7.8
CATEGORIES=	finance linux
MASTER_SITES=	https://tvd-packages.tradingview.com/ubuntu/stable/latest/jammy/
DISTNAME=	tradingview_amd64
EXTRACT_SUFX=	.deb
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	aadonsk4@mts.ru
COMMENT=	Desktop trading application
WWW=		https://www.tradingview.com

LICENSE=	PROPRIETARY
LICENSE_NAME=	PROPRIETARY
LICENSE_PERMS=	none
LICENSE_TEXT=	https://www.tradingview.com/desktop/

ONLY_FOR_ARCHS=	amd64

USES=		desktop-file-utils linux:rl9

USE_LINUX=	libsecret

SUB_FILES=	tradingview
NO_BUILD=	yes

post-extract:
	cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} data.tar.xz ${EXTRACT_AFTER_ARGS}

do-install:
	cd ${WRKDIR}/opt/TradingView && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${CHMOD} +x ${STAGEDIR}${DATADIR}/tradingview
	${INSTALL_SCRIPT} ${WRKDIR}/tradingview ${STAGEDIR}${PREFIX}/bin
	${SED} 's|/opt/TradingView/tradingview|${PREFIX}/bin/tradingview|g' ${WRKDIR}/usr/share/applications/tradingview.desktop > ${STAGEDIR}${DESKTOPDIR}/tradingview.desktop
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKDIR}/usr/share/icons/hicolor/512x512/apps/tradingview.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${FILESDIR}/com.tradingview.tradingview.appdata.xml ${STAGEDIR}${PREFIX}/share/metainfo/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/linux-tradingview/libvulkan.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/linux-tradingview/chrome-sandbox

.include <bsd.port.mk>
