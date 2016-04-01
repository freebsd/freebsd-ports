# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	lightzone
DISTVERSION=	4.1.5
PORTREVISION=	1
CATEGORIES=	graphics java
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Professional-level digital darkroom and photo editor

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	jhindexer:java/javahelp \
		git:devel/git \
		rsync:net/rsync \
		tidy:www/tidy-lib \
		autoconf:devel/autoconf
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	jhindexer:java/javahelp

USE_GITHUB=	yes
GH_ACCOUNT=	ktgw0316
GH_PROJECT=	LightZone

USES=		desktop-file-utils gmake jpeg pkgconfig
USE_ANT=	yes
USE_JAVA=	yes
USE_GCC=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.6+
JAVA_BUILD=	yes
JAVA_RUN=	yes
INSTALLS_ICONS=	yes

LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB=	LIBDIR="${LIBDIR}"
WRKSRC_SUBDIR=		linux

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' -e 's|g++|${CXX}|' ${WRKSRC}/../lightcrafts/mk/platform.mk
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/products/lightzone

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/products/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/products/*.jar ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${LIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/products/LightZone-forkd ${STAGEDIR}${LIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/products/dcraw_lz ${STAGEDIR}${LIBDIR}
	${INSTALL_LIB} ${WRKSRC}/products/*.so ${STAGEDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/products/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} icons ${STAGEDIR}${PREFIX}/share/

.include <bsd.port.mk>
