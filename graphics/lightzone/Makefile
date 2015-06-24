# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	lightzone
DISTVERSION=	4.1.1
CATEGORIES=	graphics java
MASTER_SITES=	GH
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Professional-level digital darkroom and photo editor

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		jhindexer:${PORTSDIR}/java/javahelp \
		git:${PORTSDIR}/devel/git \
		rsync:${PORTSDIR}/net/rsync \
		tidy:${PORTSDIR}/www/tidy-lib \
		autoconf:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libtiff.so:${PORTSDIR}/graphics/tiff

USE_GITHUB=	yes
GH_ACCOUNT=	ktgw0316
GH_PROJECT=	LightZone

USES=		desktop-file-utils gmake pkgconfig
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

DATADIR=	${PREFIX}/libexec/${PORTNAME}
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME}/linux

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' -e 's|g++|${CXX}|' ${WRKSRC}/../lightcrafts/mk/platform.mk

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/products/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/products/*.jar ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/products/LightZone-forkd ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/products/dcraw_lz ${STAGEDIR}${DATADIR}
	${INSTALL_LIB} ${WRKSRC}/products/*.so ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/products/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} icons ${STAGEDIR}${PREFIX}/share/

.include <bsd.port.mk>
