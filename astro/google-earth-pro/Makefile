#
# See versions at:
# https://support.google.com/earth/answer/168344

PORTNAME=	google-earth-pro
DISTVERSION=	7.3.6.10441
DISTVERSIONSUFFIX=	-0
CATEGORIES=	astro deskutils geography
MASTER_SITES=	http://dl.google.com/linux/earth/rpm/stable/x86_64/
DISTFILES_amd64=	${PORTNAME}-stable-${DISTVERSION}${DISTVERSIONSUFFIX}.x86_64.rpm

MAINTAINER=	jhay@FreeBSD.org
COMMENT=	Virtual globe, map and geographical information program
WWW=		https://www.google.com/earth/

LICENSE=	GEARTH
LICENSE_NAME=	Google Earth
LICENSE_TEXT=	Google Earth Terms are available at: \
	https://www.google.com/help/terms_maps/ \
	https://about.google/brand-resource-center/products-and-services/geo-guidelines/#google-earth
LICENSE_PERMS=	no-dist-mirror no-pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64

USES=		desktop-file-utils linux:rl9
USE_LINUX=	dbuslibs dri gstreamer1 libxml2 sqlite3 xorglibs

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}
SUB_FILES=	google-earth-pro
SUB_LIST=	LINUXBASE=${LINUXBASE}

post-patch:
	@${SED} -i '' 's/^Exec=[^[:space:]]*/Exec=google-earth-pro/' \
		${WRKSRC}/opt/google/earth/pro/google-earth-pro.desktop
	@${LN} -sf googleearth ${WRKSRC}/opt/google/earth/pro/google-earth-pro

do-install:
.for s in 16 22 24 32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/opt/google/earth/pro/product_logo_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/google-earth-pro.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/opt/google/earth/pro/google-earth-pro.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${LINUXBASE}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} opt ${STAGEDIR}${LINUXBASE})
	${INSTALL_SCRIPT} ${WRKDIR}/google-earth-pro ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
