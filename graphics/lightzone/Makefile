# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	lightzone
DISTVERSION=	4.1.8-3
DISTVERSIONSUFFIX=	-g36e87773
PORTREVISION=	6
CATEGORIES=	graphics java
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	https://github.com/ktgw0316/LightZone/commit/
PATCHFILES=	376ec67ddfb1.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Professional-level digital darkroom and photo editor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	jhindexer:java/javahelp \
		git:devel/git \
		rsync:net/rsync \
		tidy:www/tidy-lib \
		autoconf:devel/autoconf
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libomp.so:devel/openmp \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	jhindexer:java/javahelp

BROKEN_armv6=		fails to compile: build.xml: exec returned: 1
BROKEN_armv7=		fails to compile: build.xml: exec returned: 1

USE_GITHUB=	yes
GH_ACCOUNT=	ktgw0316
GH_PROJECT=	LightZone

USES=		desktop-file-utils gmake jpeg pkgconfig xorg
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

PATCH_WRKSRC=	${WRKSRC:H}
WRKSRC_SUBDIR=	linux

LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB=	LIBDIR="${LIBDIR}"

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
