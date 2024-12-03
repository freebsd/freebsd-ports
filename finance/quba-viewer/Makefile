PORTNAME=	quba-viewer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
PORTREVISION=	8
CATEGORIES=	finance deskutils
MASTER_SITES=	LOCAL/pi/finance/${PORTNAME}/:npm
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npm

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Cross platform application to display hybrid electronic invoices
WWW=		https://www.quba-viewer.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 # Will need to be tested on aarch64

.if defined(MAINTAINER_MODE)
PATCH_DEPENDS=	npm:www/npm-node20
.endif
BUILD_DEPENDS=	\
		app-builder>0:devel/app-builder \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		npm:www/npm-node20
LIB_DEPENDS=	\
		libdrm.so:graphics/libdrm \
		libepoll-shim.so:devel/libepoll-shim \
		libffi.so:devel/libffi \
		libopus.so:audio/opus \
		libpci.so:devel/libpci

USES=		desktop-file-utils gettext-runtime gl nodejs xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ZUGFeRD
USE_GL=		gl
USE_XORG=	x11 xcb xext xi

MAKE_ENV+=	ELECTRON_OVERRIDE_DIST_PATH=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} \
		HOME=${WRKDIR} \
		USE_SYSTEM_APP_BUILDER=true \
		SOURCE_DATE_EPOCH=${_BUILD_DATE} \
		PATH=${WRKSRC}/node_modules/.bin:${LOCALBASE}/bin:${PATH}

_BUILD_DATE=	$$(date +'%s')

_ELECTRON_VERSION=	32
.include <../../devel/electron${_ELECTRON_VERSION}/Makefile.version>

NODE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/}
ELECTRON_DIST=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}
APP_OUT_DIR=	linux-unpacked

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|%%ELECTRON_VERSION%%|${ELECTRON_VER}|; s|%%ELECTRON_DIST%%|${ELECTRON_DIST}|' \
		${WRKSRC}/package.json

do-build:
	${ECHO_CMD} offline=true >> ${WRKSRC}/.npmrc
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm config set cache ${WRKDIR}/node_modules
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm install --prefer-offline
	${CP} ${LOCALBASE}/bin/app-builder ${WRKSRC}/node_modules/app-builder-bin/linux/${NODE_ARCH}/app-builder
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PACKAGE_ENV} npm run build

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC}/release/${APP_OUT_DIR} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/assets/img/logo_small_icon_only.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/quba-desktop.png
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications

	${RLN} ${STAGEDIR}${DATADIR}/quba ${STAGEDIR}${PREFIX}/bin

.if defined(MAINTAINER_MODE)
_make_npm-cache: extract patch post-patch
	@${ECHO_MSG} "===> Creating npm cache tarball"
	${RM} -r ${WRKSRC}/node_modules
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm cache clean --force
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm config set cache ${WRKDIR}/node_modules
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install --cache ${WRKDIR}/node_modules --prefer-offline
	cd ${WRKDIR} && ${TAR} -czf \
		${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} -C ${WRKDIR} node_modules
	scp ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} \
		pi@freefall.freebsd.org:public_distfiles/finance/${PORTNAME}/
.endif

.include <bsd.port.post.mk>
